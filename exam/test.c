/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:06:34 by chanson           #+#    #+#             */
/*   Updated: 2023/03/25 21:38:44 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(2, str, ft_strlen(str));
}

void	fatal_error()
{
	ft_putstr("error fatal\n");
	exit(1);
}

char	*ft_strcpy(char *str)
{
	int		i;
	char	*temp;

	i = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		fatal_error();
	temp[i] = '\0';
	i = 0;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_strjoin(char **str, char *string)
{
	int		index;
	char	**temp;

	if (str == NULL)
	{
		str = (char **)malloc(sizeof(char *) * 2);
		if (!str)
			fatal_error();
		str[0] = ft_strcpy(string);
		str[1] = NULL;
		return (str);
	}
	else
	{
		index = 0;
		while (str[index])
			index++;
		temp = (char **)malloc(sizeof(char *) * (index + 2));
		if (temp == NULL)
			fatal_error();
		temp[index + 1] = NULL;
		temp[index] = ft_strcpy(string);
		index = 0;
		while (str[index])
		{
			temp[index] = ft_strcpy(str[index]);
			index++;
		}
		ft_free(str);
	}
	return (temp);
}

char	**ft_strscpy_index(char **str, int start, int end)
{
	int		index;
	char	**temp;

	index = start;
	temp = NULL;
	while (index < end)
	{
		temp = ft_strjoin(temp, str[index]);
		index++;
	}
	return (temp);
}

void	exe_cd(int argc, char **argv)
{
	if (argc > 3)
	{
		write(2, "error: cd: bad arguments\n", 25);
		exit(1);
	}
	if (chdir(argv[2]) < 0)
	{
		write(2, "error: cd: cannot change directory to ", 38);
		write(2, argv[2], ft_strlen(argv[2]));
		write(2, "\n", 1);
	}
}

void	execute_no_pipe(t_cmd *cmd, char **argv, char **envp)
{
	int		idx;
	char	**command;

	idx = -1;
	command = NULL;
	while (argv[++idx])
	{
		if (strcmp(argv[idx], ";") == -1)
			break ;
		command = ft_strjoin(command, argv[idx]);
	}
	cmd->pid[0] = fork();
	if (cmd->pid[0] < 0)
		fatal_error();
	if (cmd->pid[0] == 0)
	{
		cmd->cmd = ft_strscpy_index(argv, 0, idx);
		if (execve(cmd->cmd[0], cmd->cmd, envp) < 0)
		{
			ft_free(cmd->cmd);
			write(2, "error: cannot execute ", 22);
			write(2, cmd->cmd[0], ft_strlen(cmd->cmd[0]));
			write(2, "\n", 1);
		}
	}
	else
	{
		ft_free(command);
		if (waitpid(cmd->pid[0], 0, 0) == -1)
			fatal_error();
	}
}

void	fork_first(t_cmd *cmd, char **command, char **envp, int idx)
{
	int	i;

	cmd->pid[idx] = fork();
	if (cmd->pid[idx] < 0)
		fatal_error();
	else if (cmd->pid[idx] == 0)
	{
		i = 0;
		while (++i < cmd->pipe_cnt)
		{
			if (close(cmd->pipe[i][0]) < 0 || close(cmd->pipe[i][1]) < 0)
				fatal_error();
		}
		if (dup2(cmd->pipe[idx][1], STDOUT_FILENO) < 0)
			fatal_error();
		if (close(cmd->pipe[idx][1]) < 0 || close(cmd->pipe[idx][0]) < 0)
			fatal_error();
		if (execve(command[0], command, envp) < 0)
		{
			ft_putstr("error: cannot execute ");
			ft_putstr(command[0]);
			ft_putstr("\n");
			exit(1);
		}
	}
}

void	fork_mid(t_cmd *cmd, char **command, char **envp, int idx)
{
	int	i;

	cmd->pid[idx] = fork();
	if (cmd->pid[idx] < 0)
		fatal_error();
	else if (cmd->pid[idx] == 0)
	{
		i = -1;
		while (++i < cmd->pipe_cnt)
		{
			if (i == idx || i == idx - 1)
				continue ;
			if (close(cmd->pipe[i][0]) < 0 || close(cmd->pipe[i][1]) < 0)
				fatal_error();
		}
		if (close(cmd->pipe[idx][0]) < 0 || close(cmd->pipe[idx - 1][1]) < 0)
			fatal_error();
		if (dup2(cmd->pipe[idx - 1][0], STDIN_FILENO) < 0)
			fatal_error();
		if (dup2(cmd->pipe[idx][1], STDOUT_FILENO) < 0)
			fatal_error();
		if (close(cmd->pipe[idx - 1][0]) < 0 || close(cmd->pipe[idx][1]) < 0)
			fatal_error();
		if (execve(command[0], command, envp) < 0)
		{
			ft_putstr("error: cannot execute ");
			ft_putstr(command[0]);
			ft_putstr("\n");
			exit(1);
		}
	}
}

void	fork_last(t_cmd *cmd, char **command, char **envp, int idx)
{
	int	i;

	cmd->pid[idx] = fork();
	if (cmd->pid[idx] < 0)
		fatal_error();
	else if (cmd->pid[idx] == 0)
	{
		i = -1;
		while (++i < cmd->pipe_cnt - 1)
		{
			if (close(cmd->pipe[i][0]) < 0 || close(cmd->pipe[i][1]) < 0)
				fatal_error();
		}
		if (close(cmd->pipe[idx - 1][1]) < 0)
			fatal_error();
		if (dup2(cmd->pipe[idx - 1][0], STDIN_FILENO) < 0)
			fatal_error();
		if (close(cmd->pipe[idx - 1][0]) < 0)
			fatal_error();
		if (execve(command[0], command, envp) < 0)
		{
			ft_putstr("error: cannot execute ");
			ft_putstr(command[0]);
			ft_putstr("\n");
			exit(1);
		}
	}
}

void	execute_pipe(t_cmd *cmd, char **envp)
{
	char	**command;
	int		i;
	int		idx;

	i = -1;
	cmd->pipe_cnt = 0;
	while (cmd->cmd[++i])
	{
		if (strcmp(cmd->cmd[i], "|") == 0)
			cmd->pipe_cnt++;
	}
	if (cmd->pipe_cnt == 0)
	{
		execute_no_pipe(cmd, cmd->cmd, envp);
		return ;
	}
	cmd->pipe = (int **)malloc(sizeof(int *) * (cmd->pipe_cnt));
	if (cmd->pipe == NULL)
		fatal_error();
	i = -1;
	while (++i < cmd->pipe_cnt)
	{
		cmd->pipe[i] = (int *)malloc(sizeof(int) * 2);
		if (cmd->pipe[i] == NULL || pipe(cmd->pipe[i]) < 0)
			fatal_error();
	}
	cmd->pid = (pid_t *)malloc(sizeof(pid_t) * (cmd->pipe_cnt + 1));
	if (cmd->pid == NULL)
		fatal_error();
	i = 0;
	idx = 0;
	command = NULL;
	while (cmd->cmd[i])
	{
		if (strcmp(cmd->cmd[i], "|") == 0 || cmd->cmd[i + 1] == NULL)
		{
			if (cmd->cmd[i + 1] == NULL)
				command = ft_strjoin(command, cmd->cmd[i]);
			if (idx == 0)
				fork_first(cmd, command, envp, idx);
			else if (idx == cmd->pipe_cnt)
				fork_last(cmd, command, envp, idx);
			else
				fork_mid(cmd, command, envp, idx);
			ft_free(command);
			command = NULL;
			idx++;
		}
		else
			command = ft_strjoin(command, cmd->cmd[i]);
		i++;
	}
	i = -1;
	while (++i < cmd->pipe_cnt)
	{
		if (close(cmd->pipe[i][0]) < 0 || close(cmd->pipe[i][1]) < 0)
			fatal_error();
	}
	i = -1;
	while (++i <= cmd->pipe_cnt)
	{
		if (waitpid(cmd->pid[i], 0, 0) < 0)
			fatal_error();
	}
	ft_free(command);
	free(cmd->pid);
	i = -1;
	while (++i < cmd->pipe_cnt)
		free(cmd->pipe[i]);
	free(cmd->pipe);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int		index;
	int		pipe_cnt;

	if (argc < 2)
		return (0);
	if (strcmp(argv[1], "cd") == 0)
		exe_cd(argc, argv);
	else
	{
		index = 1;
		pipe_cnt = 0;
		cmd.pid = NULL;
		cmd.cmd = NULL;
		while (++index < argc)
		{
			if (strcmp(argv[index], "|") == 0)
				pipe_cnt++;
		}
		if (pipe_cnt == 0)
		{
			cmd.cmd = ft_strscpy_index(argv, 1, argc);
			display_str(cmd.cmd);
			execute_no_pipe(&cmd, cmd.cmd, envp);
			return (0);
		}
		index = 0;
		while (argv[++index] && pipe_cnt > 0)
		{
			if (strcmp(argv[index], ";") == 0 || argv[index + 1] == NULL)
			{
				if (argv[index + 1] == NULL)
					cmd.cmd = ft_strjoin(cmd.cmd, argv[index]);
				execute_pipe(&cmd, envp);
				ft_free(cmd.cmd);
				cmd.cmd = NULL;
			}
			else
			{
				cmd.cmd = ft_strjoin(cmd.cmd, argv[index]);
			}
		}
	}
	return (0);
}
