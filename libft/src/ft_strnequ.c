/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:45:37 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:50:24 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1) || (!s2))
		return (0);
	if (!(*s1) || !(*s2))
		return (1);
	while (*s1 == *s2 && *s1 != '\0' && (n - 1))
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
