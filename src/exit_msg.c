/*
** exit_msg.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun 25 17:48:57 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:46:18 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	exit_msg(t_all *all)
{
  if (all->bonus == 0)
    return (EXIT_SUCCESS);
  my_putstr(MAGENTA);
  my_putstr("Goodbye ");
  my_putstr(YELLOW);
  my_putstr(all->name);
  my_putstr(MAGENTA);
  my_putstr(" \nHave fun on your new ");
  my_putstr(CYAN);
  my_putstr("bad | ugly | disgusting ");
  my_putstr(MAGENTA);
  my_putstr("shell\n");
  my_putstr("\e[96m");
  my_putstr("\e[0;39m");
  return (EXIT_SUCCESS);
}
