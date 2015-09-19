#include "evalexpr.h"

t_node	*create_node(char *data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->data = data;
	return (node);
}

void	add_to_queue(t_env *env, char *data)
{
	t_node *node;

	node = create_node(data);
    if (env->queue_start == NULL)
	{
		env->queue_start = node;
		env->queue_end = node;
	}
    else
	{
		env->queue_end->next = node;
		env->queue_end = node;
	}
}

void	pop_from_stack(t_env *env)
{
    t_node *node;

	node = env->stack;
	if (node)
	{
        env->stack = node->next;
        free(node);
	}
}

void	add_to_stack(t_env *env, char *data)
{
	t_node *node;

	node = create_node(data);
    if (env->stack)
		node->next = env->stack;
	env->stack = node;
}
