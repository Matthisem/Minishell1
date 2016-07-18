/*
** my_str_str.c for day06 in /home/wyzlic_a/blih/Piscine_C_J06
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon Mar  7 15:57:06 2016 Dimitri Wyzlic
** Last update Sat Jun 25 17:08:39 2016 Dimitri Wyzlic
*/

#include "my.h"

int	is_it(char *a, char *b)
{
  int	i;

  i = 0;
  if (my_strlen(a) != my_strlen(b))
    return (-1);
  while (a[i] && b[i] && a[i] == b[i])
    i = i + 1;
  if (a[i] == 0)
    return (0);
  return (-1);
}

int	is_same_str(char *a, char *b, int len)
{
  int	i;

  i = 0;
  while (i < len && a[i] && b[i])
    {
      if (a[i] != b[i])
	return (-1);
      i = i + 1;
    }
  if (i == len)
    return (0);
  return (-1);
}
