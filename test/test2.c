/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:39:32 by chanson           #+#    #+#             */
/*   Updated: 2023/03/13 17:08:20 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_no
{
	int	test;
}	t_no;

void	test_no_3(t_no *test)
{
	test->test = 3;
}

int	main(void)
{
	t_no	test;
	pid_t	pid;
	int		fd;
	char	buf[1024];

	printf("old addr: %s\n", getcwd(NULL, 0));
	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	if (chdir("/private/etc") == -1)
	{
		perror("chdir");
		exit(EXIT_FAILURE);
	}
	printf("new addr: %s\n", getcwd(NULL, 0));
	return (0);
}
