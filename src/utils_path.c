/*
** utils_path.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun 25 16:19:04 2016 Dimitri Wyzlic
** Last update Sun Jun 26 00:53:37 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	count_pp(char *src)
{
  int	i;
  int	out;

  out = 0;
  i = 0;
  if (src == NULL)
    return (0);
  while (src[i])
    {
      if (src[i] == ':')
	out = out + 1;
      i = i + 1;
    }
  return (out);
}

char	**arr_to_path(char *src)
{
  char	**out;
  int	i;
  int	max;
  int	pos;

  max = count_pp(src);
  if (max == 0)
    max = 1;
  i = 0;
  pos = 0;
  out = malloc(sizeof(char *) * (max + 1));
  if (out == NULL)
    return (NULL);
  while (i < max)
    {
      out[i] = take_ft(src, pos, ':', &pos);
      if (out[i] == NULL)
	return (NULL);
      pos = pos + 1;
      i = i + 1;
    }
  out[i] = NULL;
  return (out);
}

char	*find_path(char *bin, char **src)
{
  int	i;
  char	*temp;

  i = 0;
  if (src == NULL)
    return (NULL);
  while (src[i] != NULL)
    {
      temp = my_conca(my_conca(src[i], "/"), bin);
      if (access(temp, F_OK | X_OK) != -1)
	return (my_conca(my_conca(src[i], "/"), bin));
      i = i + 1;
    }
  return (NULL);
}

void	dbg_p(char **a)
{
  int i = 0;
  if (a == NULL)
    return ;
  while (a[i] != NULL)
    {
      my_putstr(a[i]);
      my_putstr("\n");
      i = i + 1;
    }
}

char	*get_binpath(t_all *all)
{
  char	*out;
  char	**path;

  if (access(all->cmd[0], F_OK | X_OK) == 0)
    {
      out = my_conca(all->floca, "/");
      return (my_conca(out, all->cmd[0]));
    }
  path = arr_to_path(getenv_path(all->env));
  out = find_path(all->cmd[0], path);
  return (out);
}
