/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:37:12 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/01 11:51:23 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 4096

typedef struct		s_gnl
{
	char			*file_content;
	int				count;
	int				i;
	int				nl;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int const fd, char **line);

#endif
