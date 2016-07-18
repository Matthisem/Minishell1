/*
** utils.c for shell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Jul  8 21:20:55 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:30:24 2016 Dimitri Wyzlic
*/

#include <unistd.h>
#include "my.h"

int	my_poww(int a)
{
  int	out;
  int	i;

  out = 1;
  i = 0;
  while (i < a)
    {
      out = out * 10;
      i = i + 1;
    }
  return (out);
}
