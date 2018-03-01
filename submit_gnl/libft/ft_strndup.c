/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:30:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/22 13:45:52 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strncpy(tmp, s1, n);
	tmp[ft_strlen(s1)] = '\0';
	return (tmp);
}
