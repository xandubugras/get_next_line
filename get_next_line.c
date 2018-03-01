/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:11:43 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/28 23:31:40 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

/*
{
	- check if there is the new fd is different from the old;
	- if not allocate and initialize
	- read the whole memory into the content
	- find the current line
	- copy line into the "line" argument
	- return if there are errors
}*/


static int		get_file_len(int fd, char **file_conten)
{
	int		i;
	char	*tmp;
	char	*file_content;

	i = 0;
	file_content = *file_conten;
	//file_content = malloc(sizeof(char) * 2);
	file_content = ft_strnew(1);
	while (read(fd, &file_content[i], 1) == 1)
	{
		i++;
		tmp = ft_strnew(i);
		ft_strncpy(tmp, file_content, i + 1);
		ft_strdel(&file_content);
		file_content = ft_strnew(i + 1);
		ft_strncpy(file_content, tmp, i + 1);
		ft_strdel(&tmp);
	}
	*file_conten = file_content;
	return (i);
}

static char	*get_line(t_gnl *current_file)
{
	int i;
	int tmp;

	i = 0;
	while (current_file->file_content[current_file->i + i] != '\n' && current_file->file_content[current_file->i + i] != '\0')
		i++;
	if (current_file->file_content[current_file->i + i] == '\0')
		return (0);
	tmp = current_file->i;
	current_file->i += i + 1;
	printf("%s, i:%d\n", ft_strsub(current_file->file_content, tmp, i), current_file->i);
	return (ft_strsub(current_file->file_content, tmp, i));
}

static t_gnl	*find_or_create_file_struct(int fd, t_gnl **file_list)
{
	t_gnl	*helper;

	helper = *file_list;
	while (helper)
	{
		if (helper->fd == fd)
			return (helper);
		helper = helper->next;
	}
	helper = malloc(sizeof(t_gnl));
	helper->fd = fd;
	helper->count = get_file_len(helper->fd, &helper->file_content);
	helper->i = 0;
	helper->nl = 0;
	helper->next = NULL;
	if (*file_list != NULL)
		(*file_list)->next = helper;
	else
		*file_list = helper;
	return (helper);
}


int		get_next_line(const int fd, char **line)
{
	static t_gnl	*file_list;
	t_gnl			current_file;

	line = 0;
	current_file = *find_or_create_file_struct(fd, &file_list);
	get_line(file_list);
	return (0);
}

int main()
{
	char *printing_line;
	get_next_line(open("test.txt", O_RDONLY), &printing_line);
	get_next_line(open("test.txt", O_RDONLY), &printing_line);
	//get_next_line(open("test.txt", O_RDONLY), &printing_line);
	//get_next_line(open("test.txt", O_RDONLY), &printing_line);
	//get_next_line(open("test.txt", O_RDONLY), &printing_line);
	//get_next_line(open("test2.txt", O_RDONLY), &printing_line);
	//get_next_line(open("test3.txt", O_RDONLY), &printing_line);
	//printf("%s\n",printing_line);
	return (0);
}
