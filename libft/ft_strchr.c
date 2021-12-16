/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:47:43 by yeju              #+#    #+#             */
/*   Updated: 2021/10/06 19:03:39 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;

	find = (unsigned char)c;
	if (find == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
