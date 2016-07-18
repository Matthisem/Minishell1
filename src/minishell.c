/*
** minishell.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Jun 22 23:45:10 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:47:04 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	minishell(t_all *all)
{
  int	fail;

  fail = 0;
  if (startup_shell(all) != 0)
    return (1);
  all->result = 0;
  while (fail == 0)
    {
      all->name = get_username(all);
      print_start(all);
      all->cmdstr = get_next_line(0);
      all->cmd = pwave(all, strtab(all->cmdstr));
      if (all->cmd == NULL)
	return (EXIT_FAILURE);
      my_putstr("\e[0;39m");
      all->result = handle_cmd(all);
      if (all->result == 66)
	return (exit_msg(all));
      all->floca = get_cur_dir();
      if (all->floca == NULL)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
