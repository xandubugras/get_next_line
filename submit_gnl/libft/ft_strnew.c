/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:51:57 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/23 20:41:52 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	str[size] = '\0';
	return (str);
}
