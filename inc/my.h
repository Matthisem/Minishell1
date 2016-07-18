/*
** my.h for my_ls in /home/wyzlic_a/.live-packs/wyzlic_a-pack
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Apr 27 15:42:14 2016 Dimitri Wyzlic
** Last update Fri Jul  8 21:26:45 2016 Dimitri Wyzlic
*/

#ifndef MY_H_
# define MY_H_

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"
# define ERROR_404 "error 404"
# define ERROR_ACCES_DENIED "error access denied "
# define ERROR_DIR_LOCKED "error dir locked "
# define ERROR_FORK "erreur fork "

typedef struct	s_hist
{
  char		*str;
  struct s_env	*next;
  int		key;
}		t_hist;

typedef struct	s_env
{
  char		*name;
  char		*var;
  struct s_env	*next;
}		t_env;

typedef struct	s_all
{
  int		bonus;
  char		*cmdstr;
  char		**cmd;
  char		**path_exe;
  t_env		*env;
  t_hist	*history;
  char		**env_char;
  char		*loca;
  char		*floca;
  char		*home_fold;
  char		*name;
  int		bin;
  int		exit;
  int		key_hist;
  int		result;
}		t_all;

int	my_putstr(char *);
void	my_putchar(char);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_putnbr(int);
int	minishell(t_all *);
int	startup_shell(t_all *);
int	is_same_str(char *, char *, int);
char	*get_username(t_all *);
void	print_start(t_all *);
t_env	*add_lenv(t_env *, char *, char *);
char	*take_ft(char *, int, char, int *);
int	print_env(t_env *);
t_env	*get_env(t_all *);
char	*take_ft_car(char *, char, char, int *);
int	my_unsetenv(t_all *, char **);
int	my_setenv(t_all *, char **);
t_env	*delete_lenv(t_env *, char *);
char	*get_next_line(const int);
int	handle_cmd(t_all *);
char	**strtab(char *);
int	is_it(char *, char *);
void	my_error(char *, char *);
char	*my_conca(char *, char *);
char	*del_home(char*, char *);
int	my_cd(t_all *, char *);
char	*get_cur_dir();
char	*cd_wave(t_all *, char *);
char	**pwave(t_all *, char **);
char	**env_to_char(t_all *);
char	*getenv_path(t_env *);
char	*get_binpath(t_all *);
void	welc(t_all *);
int	exit_msg(t_all *);
int	my_strlen(char *);
int	my_poww(int);

#endif /* MY_H_ */
