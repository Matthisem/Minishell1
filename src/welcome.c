/*
** welcome.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun 25 17:27:56 2016 Dimitri Wyzlic
** Last update Sun Jun 26 00:53:12 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

void	welc_str(char *src)
{
  int	i;

  i = my_strlen(src);
  while (i >= 0 && src[i] != '/')
    i = i - 1;
  i = i + 1;
  if (i > my_strlen(src))
    {
      my_putstr("your default shell");
      return ;
    }
  while (src[i])
    {
      my_putchar(src[i]);
      i = i + 1;
    }
  return ;
}

void	welc(t_all *all)
{
  int	i;

  i = 0;
  my_putstr(RED);
  my_putstr("Hey ");
  my_putstr(MAGENTA);
  my_putstr(all->name);
  my_putstr(RED);
  my_putstr(" stop");
  my_putstr(CYAN);
  my_putstr(" use ");
  my_putstr(GREEN);
  while (all->env_char[i] != NULL)
    {
      if (is_same_str(all->env_char[i], "SHELL=", 6) == 0)
	welc_str(take_ft(all->env_char[i], 6, 0, &all->bin));
      i = i + 1;
    }
  my_putstr(CYAN);
  my_putstr(" , MySh (wyzlic_a) shell is far away better\n");
  my_putstr("\e[0;39m");
  return ;
}
