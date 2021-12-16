/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:42:39 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:37:37 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stddef.h>

void	*pop(t_list **stack);
int		push(t_list **stack, void *newcontent, size_t size);
t_list	*new_stack(void *newcontent, size_t size);
t_list	*printstack(t_list *stack, char *base, int max_value);
int		printstack_ab(t_list *a, t_list *b, char *base);
int		swap_ab(t_list **stack, char c);
int		swap_ss(t_list **a, t_list **b);
int		push_ab(t_list **a, t_list **b, char c);
int		rotate_ab(t_list **stack, char c);
int		rotate_rr(t_list **a, t_list **b);
int		reverse_ab(t_list **stack, char c);
int		reverse_rrr(t_list **a, t_list **b);
int		find(t_list *stack, void *content, size_t size);
int		check_sorted(t_list *stack);
int		first_node(t_list **stack, void *content, char c);
t_list	*min(t_list *stack);
t_list	*max(t_list *stack);
t_list	*cut_stack(t_list *stack, int index);
void	replace_stack(t_list **stack, int index, void *num, int size);

void	translate(t_list **stack);
int		order(t_list **a, t_list **b);
void	sort_3(t_list **a, t_list **b);
int		bit_sort(t_list **a, t_list **b, int max_len, int n_bit);
int		sorted_stack(t_list *a, t_list *b, char c);

#endif
