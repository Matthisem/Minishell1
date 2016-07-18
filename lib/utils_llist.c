/*
** utils_llist.c for minishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Jun 23 01:13:48 2016 Dimitri Wyzlic
** Last update	Sun Jun 26 00:56:44 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

char	*getenv_path(t_env *src)
{
  t_env	*temp;

  temp = malloc(sizeof(t_env));
  if (temp == NULL)
    return (NULL);
  temp = src;
  while (temp != NULL)
    {
      if (is_same_str(temp->name, "PATH", 4) == 0)
	return (temp->var);
      temp = temp->next;
    }
  return (NULL);
}

int	print_env(t_env *src)
{
  t_env	*temp;

  temp = malloc(sizeof(t_env));
  if (temp == NULL)
    return (42);
  temp = src;
  while (temp != NULL)
    {
      my_putstr(temp->name);
      my_putstr("=");
      my_putstr(temp->var);
      my_putstr("\n");
      temp = temp->next;
    }
  return (0);
}

t_env	*delete_lenv(t_env *src, char *delete)
{
  t_env	*temp;

  temp = malloc(sizeof(t_env));
  if (src == NULL || delete == NULL || temp == NULL)
    return (NULL);
  temp = src;
  while (temp->next->next != NULL)
    {
      if (is_same_str(temp->next->name, delete, my_strlen(delete)) == 0)
	{
	  temp->next = temp->next->next;
	  return (src);
	}
      temp = temp->next;
    }
  return (src);
}

t_env	*add_lenv(t_env *src, char *str, char *var)
{
  t_env	*new;
  t_env	*temp;

  new = malloc(sizeof(t_env));
  temp = malloc(sizeof(t_env));
  if (new == NULL || temp == NULL || str == NULL)
    return (NULL);
  new->name = str;
  new->next = NULL;
  new->var = var;
  if (src == NULL)
    return (new);
  temp = src;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new;
  return (src);
}
