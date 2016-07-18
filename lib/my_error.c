/*
** my_error.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Jun 24 00:27:51 2016 Dimitri Wyzlic
** Last update Fri Jun 24 00:30:09 2016 Dimitri Wyzlic
*/

#include <unistd.h>
#include "my.h"

void	my_puterror(char c)
{
  if (c)
    write(2, &c, 1);
  return ;
}

void	my_putserror(char *c)
{
  int	i;

  i = 0;
  if (c == NULL)
    return ;
  while (c[i])
    {
      my_puterror(c[i]);
      i = i + 1;
    }
  return ;
}

void	my_error(char *a, char *b)
{
  my_putserror(a);
  my_putserror(b);
  return ;
}
