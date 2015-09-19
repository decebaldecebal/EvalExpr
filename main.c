#include "evalexpr.h"

t_env	*create_env()
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
    if (!env)
		return (NULL);
    env->queue_end = NULL;
    env->queue_start = NULL;
    env->stack = NULL;
    return (env);
}

int		calc_expr(t_env *env)
{
	int		result;
	t_node *node;

	node = env->queue_start;
    while (node)
	{
        if (is_operator(node->data[0]) && node->data[1] == '\0') //if operator, pop two values from stack, calculate and add back the result
            calculate_value(env, node->data[0]);
		else
            add_to_stack(env, node->data); //if number, add to stack
		node = node->next;
	}
	result = ft_atoi(env->stack->data);
	free_env(env);
	return (result);
}

void	read_token(t_env *env, char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
    if (is_number(str[*i]))
        add_to_queue(env, read_number(str, i));
    else if (is_operator(str[*i]))
		add_operator(env, str, i);
	else
		add_paranthesis(env, str, i);
}

int     eval_expr(char *str)
{
	int		i;
	t_env	*env;

	env = create_env();
	if (!env)
		return (0);
	i = 0;
	while (str[i])
        read_token(env, str, &i); //transform to reverse-polish notation
	while (env->stack)
	{
		add_to_queue(env, env->stack->data);
		pop_from_stack(env);
	}
	env->stack = NULL;
	i = calc_expr(env); //calculate result from reverse-polish notation
	free(env);
	return (i);
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        ft_putnbr(eval_expr(av[1]));
        ft_putchar('\n');
    }
    return (0);
}
