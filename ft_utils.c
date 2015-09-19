#include "evalexpr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
    if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src != '\0' && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		get_operator_order(char op)
{
	if (op == '+' || op == '-')
		return (1);
	else
		return (2);
}

void	free_env(t_env *env)
{
    t_node *node;

	while (env->stack)
	{
		node = env->stack;
		env->stack = node->next;
		free(node->data);
		free(node);
	}
	while (env->queue_start)
	{
		node = env->queue_start;
		env->queue_start = node->next;
		free(node->data);
		free(node);
	}
}
