/*
** main.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Jun 22 23:39:46 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:48:23 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	main(int nb, char **arg, char **env)
{
  t_all	*all;

  (void)arg;
  all = malloc(sizeof(t_all));
  if (all == NULL || env == NULL)
    return (1);
  if (nb < 2)
    all->bonus = 0;
  else
    all->bonus = 1;
  all->exit = 0;
  all->env_char = env;
  (void)minishell(all);
  return (EXIT_SUCCESS);
}
