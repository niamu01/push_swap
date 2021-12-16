/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:46:03 by yeju              #+#    #+#             */
/*   Updated: 2021/10/06 19:01:44 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	new_dest = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (new_dest != NULL || new_src != NULL)
			new_dest[i] = new_src[i];
		i++;
	}
	return ((void *)new_dest);
}
