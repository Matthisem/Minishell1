/*
** parse_wave.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun 25 15:34:58 2016 Dimitri Wyzlic
** Last update Sun Jun 26 17:31:10 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

char	*delwave(char *src)
{
  int	i;
  char	*out;

  out = malloc(sizeof(char) * my_strlen(src));
  if (out == NULL)
    return (NULL);
  i = 1;
  while (src[i])
  {
    out[i - 1] = src[i];
    i = i + 1;
  }
  out[i - 1] = 0;
  return (out);
}

char	**pwave(t_all *all, char **src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (NULL);
  while (src[i] != NULL)
    {
      if (src[i][0] == '~')
	src[i] = my_conca(all->home_fold, delwave(src[i]));
      if (src[i] == NULL)
	return (NULL);
      i = i + 1;
    }
  src[i] = NULL;
  return (src);
}
