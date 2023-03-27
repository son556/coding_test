#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	display_str(char **str);

int	ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	if (str == NULL)
		return (0);
	while (str[cnt])
		cnt++;
	return (cnt);
}

void	ft_puterr(char *err)
{
	write(2, err, ft_strlen(err));
}

void	fatal_error(void)
{
	write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(1);
}

char	*ft_strcpy(char *str)
{
	char	*temp;
	int		i;
	int		cnt;

	cnt = ft_strlen(str);
	if (cnt == 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (cnt + 1));
	if (temp == NULL)
		fatal_error();
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	return (temp);
}

char	**ft_strscpy_index(char **str, int start, int end)
{
	char	**temp;
	int		idx;

	if (start == end)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (end - start + 1));
	if (temp == NULL)
		fatal_error();
	temp[end - start] = NULL;
	idx = 0;
	while (start + idx < end)
	{
		temp[idx] = ft_strcpy(str[start + idx]);
		idx++;
	}
	return (temp);
}

void	ft_free(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_cd(char **argv)
{
	int	cnt;

	cnt = 1;
	while (argv[cnt])
		cnt++;
	if (cnt - 1 != 2)
	{
		ft_puterr("error: cd: bad arguments\n");
		exit(1);
	}
	else if (chdir(argv[2]) < 0)
	{
		ft_puterr("error: cd: cannot change directory to ");
		ft_puterr(argv[2]);
		ft_puterr("\n");
	}
}

void	execute_cmd(char **cmd, int temp_fd, char **envp)
{
	if (dup2(temp_fd, STDIN_FILENO) < 0)
		fatal_error();
	close(temp_fd);
	if (execve(cmd[0], cmd, envp) < 0)
	{
		ft_puterr("error: cannot execute ");
		ft_puterr(cmd[0]);
		ft_puterr("\n");
	}
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd;
	int		start;
	int		end;
	pid_t	pid;
	int		pipe_fd[2];
	int		temp_fd;

	(void)argc;
	temp_fd = dup(STDIN_FILENO);
	if (temp_fd < 0)
		fatal_error();
	cmd = NULL;
	start = 1;
	end = 1;
	while (argv[start])
	{
		if (start == 1 && !strcmp(argv[1], "cd"))
			ft_cd(argv);
		else if (argv[end] == NULL || !strcmp(argv[end], ";"))
		{
			cmd = ft_strscpy_index(argv, start, end);
			pid = fork();
			if (pid < 0)
				fatal_error();
			else if (pid == 0)
				execute_cmd(cmd, temp_fd, envp);
			else
			{
				close(temp_fd);
				if (waitpid(pid, 0, 0) < 0)
					fatal_error();
				temp_fd = dup(STDIN_FILENO);
				if (temp_fd < 0)
					fatal_error();
				ft_free(cmd);
				cmd = NULL;
				if (argv[end] == NULL)
					break ;
				start = end + 1;
			}
		}
		else if (!strcmp(argv[end], "|"))
		{
			cmd = ft_strscpy_index(argv, start, end);
			if (pipe(pipe_fd) < 0)
				fatal_error();
			pid = fork();
			if (pid < 0)
				fatal_error();
			else if (pid == 0)
			{
				if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
					fatal_error();
				close(pipe_fd[1]);
				execute_cmd(cmd, temp_fd, envp);
			}
			else
			{
				close(temp_fd);
				close(pipe_fd[1]);
				if (waitpid(pid, 0, 0) < 0)
					fatal_error();
				temp_fd = pipe_fd[0];
				ft_free(cmd);
				cmd = NULL;
				start = end + 1;
			}
		}
		end++;
	}
	close(temp_fd);
	while(1);
	return (0);
}

void	display_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		printf("NULL\n");
		return ;
	}
	while (1)
	{
		printf("%d: %s\n", i, str[i]);
		if (str[i] == NULL)
			break ;
		i++;
	}
}
