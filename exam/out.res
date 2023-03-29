/bin/ls
Makefile
a
a.out
a.out.dSYM
display.c
display.o
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o
out.res
s.c
test
test.h
test.sh
test.txt

/bin/cat microshell.c
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
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

void	execute_cd(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		i++;
	if (i != 3)
	{
		put_error("error: cd: bad arguments\n");
	}
	else if (chdir(argv[2]) < 0)
	{
		put_error("error: cd: cannot change directory to ");
		put_error(argv[2]);
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
	int		start;
	int		end;
	pid_t	pid;
	int		pipe_fd[2];
	char	**cmd;

	temp_fd = dup(STDIN_FILENO);
	if (temp_fd < 0)
		fatal_error();
	start = 1;
	end = 1;
	while (1)
	{
		if (argv[end] == NULL || !strcmp(argv[end], ";"))
		{
			if (start == 1 && !strcmp(argv[start], "cd"))
				execute_cd(argv);
			else if (start != end)
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
					if (waitpid(pid, 0 , 0) < 0)
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
				execute_cd(argv);
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
					if (waitpid(pid, 0 ,0) < 0)
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
	return (0);
}

/bin/ls microshell.c
microshell.c

/bin/ls salut

;

; ;

; ; /bin/echo OK
OK

; ; /bin/echo OK ;
OK

; ; /bin/echo OK ; ;
OK

; ; /bin/echo OK ; ; ; /bin/echo OK
OK
OK

/bin/ls | /usr/bin/grep microshell
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o

/bin/ls ewqew | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo
dernier


/bin/ls | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo ftest ;
     1	microshell
     2	microshell.c
     3	microshell.o
     4	microshell1.c
     5	microshell2.c
     6	microshell2.o
dernier
ftest

/bin/echo ftest ; /bin/echo ftewerwerwerst ; /bin/echo werwerwer ; /bin/echo qweqweqweqew ; /bin/echo qwewqeqrtregrfyukui ;
ftest
ftewerwerwerst
werwerwer
qweqweqweqew
qwewqeqrtregrfyukui

/bin/ls ftest ; /bin/ls ; /bin/ls werwer ; /bin/ls microshell.c ; /bin/ls subject.fr.txt ;
Makefile
a
a.out
a.out.dSYM
display.c
display.o
leaks.res
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o
out.res
s.c
test
test.h
test.sh
test.txt
microshell.c

/bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ;
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o
microshell
microshell.c
microshell.o
microshell1.c
microshell2.c
microshell2.o

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b ; /bin/cat subject.fr.txt ;

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt ;

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt

/bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt

; /bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt

blah | /bin/echo OK
OK

blah | /bin/echo OK ;
OK

