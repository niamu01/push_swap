/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:45:49 by yeju              #+#    #+#             */
/*   Updated: 2021/10/06 19:00:48 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*dest;
	const char	*src;
	size_t		i;

	dest = (const char *)s1;
	src = (const char *)s2;
	i = 0;
	while (i < n)
	{
		if (dest[i] != src[i])
			return ((unsigned char)dest[i] - (unsigned char)src[i]);
		i++;
	}
	return (0);
}
