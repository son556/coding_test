/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:06:34 by chanson           #+#    #+#             */
/*   Updated: 2023/03/24 21:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	fatal_error()
{
	ft_putstr("error fatal\n");
	exit(1);
}

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
			temp[index] = str[index];
			index++;
		}
		ft_free(str);
	}
	return (temp);
}

void	execute_cmd(t_cmd *cmds, char **cmd, int start, int i)
{
	if (start == 0)
	{
		if (close(cmds->pipe[start][0]) == -1)
			fatal_error();
		if (dup2(cmds->pipe[start][1], STDOUT_FILENO) == 1)
			fatal_error();
	}
}

void	exe_cmd(char **cmd, char **env)
{
	int		i;
	int		start;
	t_cmd	cmds;

	i = -1;
	cmds.pipe_cnt = 0;
	cmds.cmd = NULL;
	while (cmd[++i])
	{
		if (strcmp(cmd[i], "|") == 0)
			cmds.pipe_cnt++;
	}
	if (cmds.pipe_cnt == 0)
		execute_no_pipe(&cmds, cmd);
	else
	{
		cmds.pipe = (int **)malloc(sizeof(int *) * cmds.pipe_cnt);
		if (cmds.pipe == NULL)
			fatal_error();
		i = -1;
		while (++i < cmds.pipe_cnt)
		{
			cmds.pipe[i] = (int *)malloc(sizeof(int) * 2);
			if (cmds.pipe[i] == NULL)
				fatal_error();
		}
		cmds.pid = (pid_t *)malloc(sizeof(pid_t) * (cmds.pipe_cnt + 1));
		if (cmds.pid == NULL)
			fatal_error();
		start = 0;
		i = -1;
		while (++i < cmds.pipe_cnt)
		{
			if (pipe(cmds.pipe[i]) == -1)
				fatal_error();
		}
		while (cmd[i])
		{
			if (strcmp(cmd[i], "|") == 0)
			{
				cmds.pid[start] = fork();
				if (cmds.pid[start] == -1)
					fatal_error();
				if (cmds.pid[start])
					execute_cmd(&cmds, cmd, start, i);
				start = i;
			}
			else if (cmd[i + 1] == NULL)
			{
				cmds.pid[start] = fork();
				if (cmds.pid[start] == -1)
					fatal_error();
				if (cmds.pid[start] == 0)
					execute_cmd(&cmds, cmd, start, i);
			}
			i++;
		}
		i = -1;
		while (++i < cmds.pipe_cnt + 1)
		{
			if (i < cmds.pipe_cnt)
			{
				if (close(cmds.pipe[i][0]) == -1)
					fatal_error();
				if (close(cmds.pipe[i][1]) == -1)
					fatal_error();
			}
			if (waitpid(cmds.pid[i], 0, 0) == -1)
				fatal_error();
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	char	**cmd;
	int		index;

	if (argc < 2)
		return (0);
	if (strcmp(argv[1], "cd") == 0)
		exe_cd(argv);
	else
	{
		index = 1;
		cmd = NULL;
		while (index < argc)
		{
			if (strcmp(argv[index], ";") == 0 || index + 1 == argc)
			{
				exe_cmd(cmd, env);
				ft_free(cmd);
				cmd = NULL;
			}
			else
				cmd = ft_strjoin(cmd, argv[index]);
			index++;
		}
	}
	return (0);
}
