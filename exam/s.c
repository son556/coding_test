#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *str)
{
	int 	i;
	int		cnt;
	char	*temp;

	i = 0;
	while (str[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	temp[i] = '\0';
	cnt = i;
	i = -1;
	while (++i < cnt)
		temp[i] = str[i];
	return (temp);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd;

	cmd = (char **)malloc(sizeof(char *) * 3);
	cmd[0] = ft_strcpy("/bin/echo");
	cmd[1] = ft_strcpy("-l");
	cmd[2] = NULL;
	printf("%s\n", cmd[0]);
	execve(cmd[0], cmd, envp);
	printf("error\n");
	return (0);
}
