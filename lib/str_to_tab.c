/*
** str_to_tab.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Jun 23 16:07:01 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:10:14 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	nb_words(char *src)
{
  int	i;
  int	out;

  out = (src[0] == ' ' || src[0] == '\t') ? 0 : 1;
  i = 0;
  while (src[i])
    {
      if (src[i - 1] == ' ' && src[i - 1] != '\t'
	  && src[i] != ' ' && src[i] != '\t')
	out = (i > 0) ? out + 1 : out;
      i = i + 1;
    }
  return (out);
}

char	*take_word(char *src, int *pos, int len)
{
  char	*out;
  int	j;

  j = 0;
  out = malloc(sizeof(char) * len);
  if (out == NULL)
    return (NULL);
  while (src[*pos] && src[*pos] != ' ')
    {
      out[j] = src[*pos];
      *pos = *pos + 1;
      j = j + 1;
    }
  while (src[*pos] && (src[*pos] == ' ' || src[*pos] == '\t'))
    *pos = *pos + 1;
  return (out);
}

char	**strtab(char *src)
{
  char	**out;
  int	nbwords;
  int	i;
  int	pos;
  int	max;

  if (src == NULL)
    return (NULL);
  max = my_strlen(src);
  pos = 0;
  i = 0;
  nbwords = nb_words(src);
  out = malloc(sizeof(char *) * (nbwords + 1));
  if (out == NULL)
    return (NULL);
  while (i < nbwords)
    {
      out[i] = take_word(src, &pos, max);
      if (out[i] == NULL)
	return (NULL);
      i = i + 1;
    }
  out[i] = NULL;
  return (out);
}
