/*
** take_str.c for mini in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Jun 23 13:02:24 2016 Dimitri Wyzlic
** Last update Sun Jun 26 00:50:01 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	strlen_ft(char *src, int start, char end)
{
  if (src == NULL)
    return (0);
  while (src[start] && src[start] != end)
    start = start + 1;
  return (start);
}

char	*take_ft(char *src, int start, char end, int *save)
{
  char	*out;
  int	i;

  i = 0;
  if (src == NULL)
    {
      *save = -1;
      return (NULL);
    }
  out = malloc(sizeof(char) * strlen_ft(src, start, end));
  if (out == NULL)
    {
      *save = -1;
      return (NULL);
    }
  while (src[start] && src[start] != end)
    out[i++] = src[start++];
  *save = start;
  if (src[start] == 0)
    *save = -1;
  out[i] = 0;
  return (out);
}

char	*take_ft_car(char *src, char start, char end, int *save)
{
  char	*out;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if (src == NULL)
    return (NULL);
  out = malloc(sizeof(char) * strlen_ft(src, 0, end));
  if (out == NULL)
    return (NULL);
  while (src [j] && src[j] != start)
    j = j + 1;
  j = j + 1;
  while (src[j] && src[j] != end)
    out[i++] = src[j++];
  *save = j;
  if (src[j] == 0)
    *save = -1;
  out[i] = 0;
  return (out);
}
