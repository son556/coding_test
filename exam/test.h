/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:15:44 by chanson           #+#    #+#             */
/*   Updated: 2023/03/24 19:34:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

typedef struct s_cmd
{
	int		pipe_cnt;
	int		**pipe;
	int		status;
	char	**cmd;
	pid_t	*pid;
}	t_cmd;
#endif