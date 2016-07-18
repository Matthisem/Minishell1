/*
** cmd.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Jun 23 15:53:01 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:46:47 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char	**take_opt(char **src)
{
  int	i;

  i = 0;
  if (src[i] == NULL)
    return (NULL);
  while (src[i + 1] != NULL)
    {
      src[i] = src[i + 1];
    }
  src[i] = NULL;
  return (src);
}

int	exec_cmd(t_all *all, char *path)
{
  pid_t	pid;
  int	statut;
  char	**my_env;

  my_env = env_to_char(all);
  pid = fork();
  if (pid == -1)
    {
      my_error(ERROR_FORK, "ERREUR FORK");
      return (1);
    }
  else if (pid == 0)
    {
      if (execve(path, all->cmd, my_env) == -1)
	{
	  my_error("Unknown command ", all->cmdstr);
	  return (1);
	}
    }
  else
    wait(&statut);
  return (0);
}

int	handle_cmd_error(t_all *all)
{
  if (all->bonus == 1)
    {
      my_error(RED, "Commande invalide : ");
      my_error(MAGENTA, all->cmd[0]);
      my_error("\n", "\e[0;39m");
    }
  my_error(all->cmd[0], ": command not found\n");
  return (1);
}

int	handle_cmd(t_all *all)
{
  char	*cmd;

  if (is_it(all->cmd[0], "env") == 0 && all->cmd[0][3] == 0)
    return (print_env(all->env));
  if (is_it(all->cmd[0], "cd") == 0 && all->cmd[0][2] == 0)
    return (my_cd(all, all->cmd[1]));
  if (is_it(all->cmd[0], "pwd") == 0 && all->cmd[0][3] == 0)
    return (my_putstr(my_conca(all->floca, "\n")));
  if (is_it(all->cmd[0], "exit") == 0 && all->cmd[0][4] == 0)
    return (66);
  if (is_it(all->cmd[0], "unsetenv") == 0 && all->cmd[0][8] == 0)
    return (my_unsetenv(all, all->cmd));
  if (is_it(all->cmd[0], "setenv") == 0 && all->cmd[0][8] == 0)
    return (my_setenv(all, all->cmd));
  cmd = get_binpath(all);
  if (cmd == NULL)
    return (handle_cmd_error(all));
  return (exec_cmd(all, cmd));
}
