/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:16:15 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:32:48 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	find(t_list *stack, void *content, size_t size)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (!ft_memcmp(stack->content, content, size))
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

t_list	*min(t_list *stack)
{
	t_list	*min;

	min = NULL;
	while (stack)
	{
		if (!min || *(int *)min->content > *(int *)stack->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*max(t_list *stack)
{
	t_list	*max;

	max = NULL;
	while (stack)
	{
		if (!max || *(int *)max->content < *(int *)stack->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	replace_stack(t_list **stack, int index, void *num, int size)
{
	int		i;
	t_list	*start;

	i = 0;
	start = *stack;
	while (start)
	{
		if (i == index)
		{
			free(start->content);
			start->content = NULL;
			start->content = malloc(size);
			ft_memcpy(start->content, num, size);
			break ;
		}
		i++;
		start = start->next;
	}
}
