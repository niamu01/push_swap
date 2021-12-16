/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:53:13 by yeju              #+#    #+#             */
/*   Updated: 2021/10/06 19:02:13 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_nbrlen(long num, int base)
{
	int	len;

	len = 0;
	if (!base)
		base = 10;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}
