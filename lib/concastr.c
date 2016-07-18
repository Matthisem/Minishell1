/*
** concastr.c for monishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Jun 24 01:02:05 2016 Dimitri Wyzlic
** Last update Sun Jun 26 00:50:11 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

char	*del_home(char *home, char *path)
{
  char	*out;
  int	i;
  int	j;

  i = 0;
  j = 0;
  out = malloc(sizeof(char) * my_strlen(path));
  if (out == NULL || home == NULL || path == NULL)
    return (NULL);
  while (home[i] && path[i] && home[i] == path[i])
    i = i + 1;
  while (path[i])
    {
      out[j] = path[i];
      j = j + 1;
      i = i + 1;
    }
  out[j] = 0;
  return (out);
}

char	*my_conca(char *a, char *b)
{
  char	*out;
  int	i;
  int	j;

  i = 0;
  j = 0;
  out = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b)));
  if (a == NULL || b == NULL || out == NULL)
    return (NULL);
  while (a[i])
    {
      out[i] = a[i];
      i = i + 1;
    }
  while (b[j])
    {
      out[i + j] = b[j];
      j = j + 1;
    }
  out[i + j] = 0;
  return (out);
}
