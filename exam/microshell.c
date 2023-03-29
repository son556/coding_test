#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	if (str == NULL)
		return (cnt);
	while (str[cnt])
		cnt++;
	return (cnt);
}

void	put_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	fatal_error(void)
{
	put_error("error: fatal\n");
	exit(1);
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

char	*ft_strcpy(char *str)
{
	char	*temp;
	int		idx;

	if (str == NULL)
		return (NULL);
	idx = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (idx + 1));
	if (temp == NULL)
		fatal_error();
	temp[idx] = '\0';
	idx = -1;
	while (str[++idx])
		temp[idx] = str[idx];
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

void	execute_cd(char **argv, int start)
{
	int	i;

	i = start;
	while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		i++;
	if (i - start != 2)
	{
		put_error("error: cd: bad arguments\n");
	}
	else if (chdir(argv[start + 1]) < 0)
	{
		put_error("error: cd: cannot change directory to ");
		put_error(argv[start + 1]);
		put_error("\n");
	}
}

void	execute_cmd(char **cmd, int temp_fd, char **envp)
{
	if (dup2(temp_fd, STDIN_FILENO) < 0)
		fatal_error();
	close(temp_fd);
	if (execve(cmd[0], cmd, envp) < 0)
	{
		put_error("error: cannot execute ");
		put_error(cmd[0]);
		put_error("\n");
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		temp_fd;
	int		child_status;
	int		start;
	int		end;
	pid_t	pid;
	int		pipe_fd[2];
	char	**cmd;

	if (argc == 1)
		return (0);
	temp_fd = dup(STDIN_FILENO);
	if (temp_fd < 0)
		fatal_error();
	start = 1;
	end = 1;
	child_status = 0;
	while (1)
	{
		if (argv[end] == NULL || !strcmp(argv[end], ";"))
		{
			if (start == 1 && !strcmp(argv[start], "cd"))
				execute_cd(argv, start);
			else if (start != end)
			{
				cmd = ft_strscpy_index(argv, start, end);
				pid = fork();
				if (pid < 0)
					fatal_error();
				else if (pid == 0)
				{
					execute_cmd(cmd, temp_fd, envp);
				}
				else
				{
					close(temp_fd);
					if (waitpid(pid, &child_status, 0) < 0)
						fatal_error();
					ft_free(cmd);
					temp_fd = dup(STDIN_FILENO);
					if (temp_fd < 0)
						fatal_error();
					cmd = NULL;
				}
			}
			start = end + 1;
			if (argv[end] == NULL)
				break ;
		}
		else if (!strcmp(argv[end], "|"))
		{
			if (start == 1 && !strcmp(argv[start], "cd"))
				execute_cd(argv, start);
			else if (start != end)
			{
				cmd = ft_strscpy_index(argv, start, end);
				if (pipe(pipe_fd) < 0)
					fatal_error();
				pid = fork();
				if (pid < 0)
					fatal_error();
				else if (pid == 0)
				{
					close(pipe_fd[0]);
					if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
						fatal_error();
					close(pipe_fd[1]);
					execute_cmd(cmd, temp_fd, envp);
				}
				else
				{
					close(temp_fd);
					close(pipe_fd[1]);
					if (waitpid(pid, &child_status, 0) < 0)
						fatal_error();
					temp_fd = pipe_fd[0];
					ft_free(cmd);
					cmd = NULL;
				}
			}
			start = end + 1;
		}
		end++;
	}
	close(temp_fd);
	if (child_status != 0)
		return (1);
	else
		return (0);
}
