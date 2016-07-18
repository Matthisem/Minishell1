/*
** print_start.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Jun 23 00:43:29 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:34:25 2016 Dimitri Wyzlic
*/

#include "my.h"

void	print_start_next(t_all *all)
{
  if (all->bonus == 0)
    return ((void)my_putstr("$> "));
  my_putstr(GREEN);
  my_putstr("\e[4m");
  my_putstr(all->name);
  my_putstr("\e[24m");
  my_putstr(YELLOW);
  my_putstr(" || ");
  my_putstr(all->floca);
  if (all->result != 0)
    my_putstr(RED);
  else
    my_putstr(GREEN);
  my_putstr(" => ");
  my_putstr("\e[0;39m");
  my_putstr("\e[96m");
  return ;
}

void	print_start(t_all *all)
{
  if (is_same_str(all->name, "root", 4) == 0)
    {
      my_putstr(RED);
      my_putstr("\e[4;7m");
      my_putstr(all->name);
      my_putstr("\e[24;27m");
      my_putstr(YELLOW);
      my_putstr(" || ");
      my_putstr(all->floca);
      if (all->result != 0)
	my_putstr(RED);
      else
	my_putstr(GREEN);
      my_putstr(" => ");
      my_putstr("\e[0;39m");
    }
  else
    return (print_start_next(all));
  return;
}
