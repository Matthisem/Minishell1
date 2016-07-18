/*
** cd.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Jun 24 00:24:00 2016 Dimitri Wyzlic
** Last update Sun Jun 26 18:26:52 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_cd_next(t_all *all, char *path)
{
  if (access(path, R_OK) == -1)
    {
      my_error(RED, "Error : [cd] can't access to ");
      my_error(MAGENTA, path);
      my_error(RED, " \n\e[0;39m");
      return (-1);
    }
  if (chdir(path) == -1)
    {
      my_error(RED, "Error : [cd] Directory Locked or it's a File ");
      my_error(MAGENTA, path);
      my_error(RED, " Try with 'sudo'\n\e[0;39m");
      return (-1);
    }
  all->floca = path;
  return (0);
}
  int	my_cd(t_all *all, char *path)
{
  if (path == NULL)
    {
      my_error(RED, "Error : [cd] ");
      my_error(MAGENTA, "usage : cd [PATH]");
      my_error("\e[0;39m", "\n");
      return (-1);
    }
  if (access(path, F_OK) == -1)
    {
      my_error(RED, "Error : [cd] ");
      my_error(MAGENTA, path);
      my_error(RED, " doesnt exist\n");
      my_error("", "\e[0;39m");
      return (-1);
    }
  return (my_cd_next(all, path));
}

char	*cd_p(t_all *all, char *path)
{
  char	*out;

  out = my_conca(all->loca, path);
  return (out);
}

char	*cd_wave(t_all *all, char *path)
{
  char	*out;

  if (my_strlen(path) < 1)
    return (NULL);
  out = my_conca(all->home_fold, path);
  return (out);
}
