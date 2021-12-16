/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:18:11 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:32:58 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_sorted(t_list *stack)
{
	void	*temp;

	temp = NULL;
	if (!stack)
		return (0);
	while (stack)
	{
		if (temp && *(int *)temp > *(int *)stack->content)
			return (0);
		temp = stack->content;
		stack = stack->next;
	}
	return (1);
}

int	first_node(t_list **stack, void *content, char c)
{
	int		pos;
	void	*temp;

	temp = malloc(sizeof(int));
	if (!temp)
		return (0);
	ft_memcpy(temp, content, sizeof(int));
	pos = find(*stack, content, sizeof(int));
	if (*(int *)stack[0]->content != *(int *)temp && pos != -1)
	{
		while (ft_memcmp(temp, stack[0]->content, sizeof(int)))
		{
			if (pos > (ft_lstsize(*stack) - 1) / 2)
				reverse_ab(stack, c);
			else
				rotate_ab(stack, c);
		}
	}
	free(temp);
	return (0);
}

void	translate(t_list **stack)
{
	t_list	*temp;
	int		len;
	int		i;
	int		content;

	i = 0;
	content = 0;
	temp = NULL;
	len = ft_lstsize(*stack);
	while (i++ < len)
		ft_lstadd_front(&temp, new_stack((void *)&content, sizeof(int)));
	i = 0;
	content = *(int *)max(*stack)->content + 1;
	while (i < len)
	{
		replace_stack(&temp, find(*stack, min(*stack)->content, \
			sizeof(int)), (void *)&i, sizeof(int));
		replace_stack(stack, find(*stack, min(*stack)->content, \
			sizeof(int)), (void *)&content, sizeof(int));
		i++;
		content++;
	}
	ft_lstclear(stack, free);
	*stack = temp;
}

int	sorted_stack(t_list *a, t_list *b, char c)
{
	int	len;
	int	ret;

	ret = 0;
	len = 0;
	while (c == 'a' && a)
	{
		if (*(int *)a->content == len)
			ret++;
		else
			ret = 0;
		len++;
		a = a->next;
	}
	len = ft_lstsize(b) - 1;
	while (c == 'b' && b)
	{
		if (*(int *)b->content == len)
			ret++;
		else
			ret = 0;
		len--;
		b = b->next;
	}
	return (ret);
}
