/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:51:20 by chanson           #+#    #+#             */
/*   Updated: 2023/03/30 21:16:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strcpy(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	temp[i] = '\0';
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	return (temp);
}

int main(int	argc, char **argv, char **envp)
{
    int pid, child_pid, status;
	char	**cmd;
	cmd = (char **)malloc(sizeof(char *) * 2);
	cmd[0] = ft_strcpy("/bin/lt");
	cmd[1] = NULL;
    (void)argc;
	(void)argv;
	if ((pid=fork()) == -1)
       perror("fork failed");
    /* 부모 프로세스 */
    else if (pid != 0) 
	{
       pid = waitpid(pid, &status, 0);
	   printf("status: %d\n", status);
       if (WIFEXITED(status))
	   {
          printf("child terminated with code %d\n", WEXITSTATUS(status));
		  status = WEXITSTATUS(status);
		  printf("st: %d\n", status);
	   }
       else
          printf("child terminated abnormally\n");
    /* 자식 프로세스 */
    } else {
		int n
       printf("run child\n");
	   exit(execve(cmd[0], cmd, envp));   /* 자식 프로세스는 종료 코드 27을 반환하고 종료 */
    }
}
