/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 03:47:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/18 02:40:26 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strchr_ind(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	i++;
	return (-i);
}