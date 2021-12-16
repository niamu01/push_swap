/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:44:56 by yeju              #+#    #+#             */
/*   Updated: 2021/10/08 02:35:19 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	swap_ss(t_list **a, t_list **b)
{
	swap_ab(a, 0);
	swap_ab(b, 0);
	ft_putstr_fd("ss\n", 1);
	return (1);
}

int	rotate_rr(t_list **a, t_list **b)
{
	if (!rotate_ab(a, 0))
		return (0);
	if (!rotate_ab(b, 0))
		return (0);
	ft_putstr_fd("rr\n", 1);
	return (1);
}

int	reverse_rrr(t_list **a, t_list **b)
{
	if (!reverse_ab(a, 0))
		return (0);
	if (!reverse_ab(b, 0))
		return (0);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
