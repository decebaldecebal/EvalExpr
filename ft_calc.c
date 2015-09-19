#include "evalexpr.h"

int		get_number_size(char *str, int i)
{
	int j;

	j = i;
	while (str[i] && is_number(str[i]))
		i++;
	return (i - j);
}

char	*read_number(char *str, int *i)
{
    char	*temp;
    int		n;

	n = get_number_size(str, *i);
	temp = (char *)malloc(sizeof(char) * (n + 1));
	temp = ft_strncpy(temp, &str[*i], n);
	*i = *i + n;
	return (temp);
}

void	add_operator(t_env *env, char *str, int *i)
{
	char	*op;

	op = (char *)malloc(sizeof(char) * 2);
	op[0] = str[*i];
	op[1] = '\0';
	//while there are operators in the stack with lower higher or equal precedence, add them to the queue
	while (env->stack && is_operator(env->stack->data[0])
		&& get_operator_order(env->stack->data[0]) >= get_operator_order(op[0]))
	{
		add_to_queue(env, env->stack->data);
		pop_from_stack(env);
	}
	add_to_stack(env, op); //add the operator to the stack
	(*i)++;
}

void	add_paranthesis(t_env *env, char *str, int *i)
{
	char	*op;

	op = (char *)malloc(sizeof(char) * 2);
	op[0] = str[*i];
	op[1] = '\0';
    if (str[*i] == '(')
		add_to_stack(env, op);
	else if (str[*i] == ')')
	{
        while (env->stack && env->stack->data[0] != '(') // until we find a ( pop operators from stack to queue, excluding the (
		{
            add_to_queue(env, env->stack->data);
            pop_from_stack(env);
		}
		pop_from_stack(env);
	}
	(*i)++;
}

void	calculate_value(t_env *env, char op)
{
    int n;
    int m;

	n = ft_atoi(env->stack->data);
	pop_from_stack(env);
	m = ft_atoi(env->stack->data);
	pop_from_stack(env);
	if (op == '+')
		m += n;
	else if (op == '-')
		m -= n;
	else if (op == '/')
		m /= n;
	else if (op == '*')
		m *= n;
	else if (op == '%')
		m %= n;
	add_to_stack(env, ft_itoa(m));
}
