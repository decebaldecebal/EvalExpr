#ifndef EVALEXPR_H
# define EVALEXPR_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_node
{
    char			*data;
    struct s_node	*next;
}				t_node;

typedef struct	s_env
{
	t_node		*stack;
	t_node		*queue_start;
	t_node		*queue_end;
}				t_env;

/* main.c */
int		eval_expr(char *str);
void	read_token(t_env *env, char *str, int *i);
int		calc_expr(t_env *env);
t_env	*create_env();

/* ft_utils.c */
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		get_operator_order(char op);
void	free_env(t_env *env);

/* ft_numbers.c */
int		is_number(char c);
int		is_operator(char c);
int		ft_atoi(char *str);
int		get_length(int n);
char	*ft_itoa(int n);

/* ft_lists.c */
t_node	*create_node(char *data);
void	add_to_queue(t_env *env, char *data);
void	pop_from_stack(t_env *env);
void	add_to_stack(t_env *env, char *data);

/* ft_calc.c */
int		get_number_size(char *str, int i);
char	*read_number(char *str, int *i);
void	add_operator(t_env *env, char *str, int *i);
void	add_paranthesis(t_env *env, char *str, int *i);
void	calculate_value(t_env *env, char op);

#endif
