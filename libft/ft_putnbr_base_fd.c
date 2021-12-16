/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:13:33 by yeju              #+#    #+#             */
/*   Updated: 2021/10/06 19:02:49 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_putnbr_base_fd(long num, char *base, int fd)
{
	int	count;
	int	base_len;

	count = 0;
	if (!base || !base[0] || ft_strlen(base) < 2)
		base = "0123456789";
	base_len = ft_strlen(base);
	if (num < 0)
	{
		count += write(1, "-", 1);
		num *= -1;
	}
	if (num >= base_len && num < 2147483648)
	{
		ft_putnbr_base_fd(num / base_len, base, fd);
		ft_putnbr_base_fd(num % base_len, base, fd);
	}
	else
		count += ft_putchar_fd(num + '0', fd);
	return (count);
}
