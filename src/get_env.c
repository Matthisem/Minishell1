/*
** get_env.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Jun 23 01:25:42 2016 Dimitri Wyzlic
** Last update Sun Jun 26 00:51:27 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	my_unsetenv(t_all *all, char **delete)
{
  t_env	*temp;

  if (delete[1] == NULL)
    {
      my_putstr("unsetenv usage : unsetenv [VAR_TO_DELETE]\n");
      return (1);
    }
  temp = delete_lenv(all->env, delete[1]);
  if (temp == NULL)
    return (1);
  all->env = temp;
  return (0);
}

int	my_setenv(t_all *all, char **cmd)
{
  if (cmd == NULL)
    return (1);
  if (cmd[0] == NULL)
    return (1);
  if (cmd[1] == NULL)
    {
      my_error("setenv usage : setenv [NAME] [VAR]", "\n");
      return (1);
    }
  if (cmd[2] == NULL)
    {
      my_error("setenv usage : setenv [NAME] [VAR]", "\n");
      return (1);
    }
  all->env = delete_lenv(all->env, cmd[1]);
  if (all->env == NULL)
    return (1);
  all->env = add_lenv(all->env, cmd[1], cmd[2]);
  if (all->env == NULL)
    return (1);
  return (0);
}

t_env	*get_env(t_all *all)
{
  int	i;
  t_env	*start;

  i = 0;
  start = NULL;
  while (all->env_char[i])
    {
      start = add_lenv(start, take_ft(all->env_char[i], 0, '=', &all->bin),
		       take_ft_car(all->env_char[i], '=', 0, &all->bin));
      if (start == NULL)
	return (NULL);
      i = i + 1;
    }
  return (start);
}

char	**env_to_char(t_all *all)
{
  return (all->env_char);
}
