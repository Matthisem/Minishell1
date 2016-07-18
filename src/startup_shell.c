/*
** startup_shell.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Jun 22 23:55:07 2016 Dimitri Wyzlic
** Last update Wed Jul  6 22:56:43 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*copy_ab(char *a)
{
  char	*out;
  int	i;
  int	max;

  max = my_strlen(a);
  i = 0;
  out = malloc(max * sizeof(char));
  if (out == NULL || a == NULL)
    return (NULL);
  while (i < max)
    {
      out[i] = a[i];
      i = i + 1;
    }
  out[i] = 0;
  return (out);
}

char	*get_cur_dir()
{
  char	buff[1024];

  if (buff == NULL)
    return (NULL);
  return (copy_ab(getcwd(buff, 1024)));
}

char	*get_home_fd(char *name)
{
  return (my_conca("/home/", name));
}

char	*get_username(t_all *all)
{
  int	i;

  i = 0;
  while (all->env_char[i] != NULL)
    {
      if (is_same_str(all->env_char[i], "USER=", 5) == 0)
	  return (take_ft(all->env_char[i], 5, 0, &all->bin));
      i = i + 1;
    }
  return (NULL);
}

int	startup_shell(t_all *all)
{
  char	buff[1024];

  if (buff == NULL)
    return (1);
  all->name = get_username(all);
  all->result = 0;
  all->env = get_env(all);
  all->home_fold = get_home_fd(all->name);
  all->floca = copy_ab(getcwd(buff, 1024));
  all->loca = del_home(all->home_fold, all->floca);
  if (all->bonus == 1)
    welc(all);
  return (0);
}
