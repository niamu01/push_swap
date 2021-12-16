/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:44:15 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:30:57 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	*pop(t_list **stack)
{
	void	*out;
	t_list	*head;

	out = NULL;
	if (!stack || !stack[0])
		return (NULL);
	head = *stack;
	if (head->next)
	{
		*stack = head->next;
		out = head->content;
		free(head);
		return (out);
	}
	out = head->content;
	free(head);
	*stack = NULL;
	return (out);
}

int	push(t_list **stack, void *newcontent, size_t size)
{
	t_list	*new;

	new = new_stack(newcontent, size);
	if (!new)
		return (0);
	ft_lstadd_front(stack, new);
	return (1);
}

t_list	*cut_stack(t_list *stack, int index)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack);
		i++;
		stack = stack->next;
	}
	return (NULL);
}

t_list	*new_stack(void *newcontent, size_t size)
{
	t_list	*new;
	void	*content;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	content = malloc(size);
	if (!content)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(content, newcontent, size);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	temp = NULL;
	if (*stack)
	{
		while (*stack)
		{
			temp = *stack;
			stack[0] = stack[0]->next;
			free(temp->content);
			free(temp);
			temp = NULL;
		}
	}
	*stack = NULL;
}
