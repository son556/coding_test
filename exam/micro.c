#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

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

void	ft_free(char **cmd)
{
	int	idx;

	if (cmd == NULL)
		return ;
	idx = -1;
	while (cmd[++idx])
		free(cmd[idx]);
	free(cmd);
	return (cmd);
}

void	ft_free_int(int	**nums, int end)
{
	int	i;

	i = -1;
	while (++i < end)
		free(nums[i]);
	free(nums);
}

void	put_error(char *err)
{
	write(2, err, ft_strlen(err));
}

void	fatal_error(void)
{
	put_error("error : fatal\n");
	exit(1);
}

char	*ft_strcpy(char *str)
{
	int		i;
	char	*temp;

	i = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		fatal_error();
	temp[i] = '\0';
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	return (temp);
}

char	**ft_strscpy_index(char **str, int start, int end)
{
	int		idx;
	char	**temp;

	if (end == start)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (end - start + 1));
	if (!temp)
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

int	execute_cd(char **argv, int start)
{
	int	idx;

	idx = start;
	while (argv[idx] && strcmp(argv[idx], "|") && strcmp(argv[idx], ";"))
		idx++;
	if (idx - start != 2)
	{
		put_error("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(argv[start + 1]) < 0)
	{
		put_error("error: cd: cannot change directory to ");
		put_error(argv[start + 1]);
		put_error("\n");
		return (1);
	}
	return (0);
}

int	execute_cmd(char **cmd, char **envp)
{
	char	**command;
	int		**pipe_fd;
	int		pipe_cnt;
	pid_t	*pid;
	int		idx;
	int		start;
	int		child;

	pipe_cnt = 0;
	pipe_fd = NULL;
	pid = NULL;
	idx = -1;
	while (cmd[++idx])
		if (!strcmp(cmd, "|"))
			pipe_cnt++;
	if (pipe_cnt > 0)
	{
		pipe_fd = (int **)malloc(sizeof(int *) * pipe_cnt);
		if (pipe_fd == NULL)
			fatal_error();
		idx = -1;
		while (++idx < pipe_cnt)
		{
			pipe_fd[idx] = (int *)malloc(sizeof(int) * 2);
			if (pipe_fd[idx] == NULL)
				fatal_error();
		}
	}
	pid = (pid_t *)malloc(sizeof(pid_t) * (pipe_cnt + 1));
	if (pid == NULL)
		fatal_error();
	idx = 0;
	start = 0;
	while (1)
	{
		if (cmd[idx] == NULL)
		{
			command = ft_strscpy_index(cmd, start, idx);
			child = fork_last(command, pipe_fd, pid, idx - 1);
			break ;
		}
		else if (!strcmp(cmd[idx], "|") && start == 0)
		{
			command = ft_strscpy_index(cmd, start, idx);
			fork_
		}
	}
}
