/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:21:36 by yeju              #+#    #+#             */
/*   Updated: 2021/10/06 18:35:46 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_atoi(const char *str, long *num)
{
	int		minus;

	minus = 1;
	*num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		minus = -minus;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (ft_isdigit(*str))
	{
		*num = 10 * *num + (*str - '0');
		if (*num > 2147483647 && minus == 1)
			return (-1);
		if (*num > 2147483648 && minus == -1)
			return (-1);
		str++;
	}
	if (*str && !ft_isspace(*str))
		return (-1);
	*num *= minus;
	return (0);
}
