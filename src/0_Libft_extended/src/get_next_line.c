/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:00:39 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:31 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Fills a list to a given head (connected to fd) until read '\n'
static char	fill_llist(t_fd_head *head, t_list **end, ssize_t bytes_read)
{
	if (!head->begin)
		end = &(head->begin);
	else if (has_nl(head->begin->content))
		return (1);
	else
		end = &(head->begin->next);
	while (1)
	{
		*end = (t_list *)malloc(sizeof(t_list));
		if (*end == NULL)
			return (0);
		(*end)->next = NULL;
		(*end)->content = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!(*end)->content)
			return (0);
		bytes_read = read(head->fd, (*end)->content, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		if (has_nl((*end)->content) || len_toend((*end)->content) < BUFFER_SIZE)
			return (1);
		end = &((*end)->next);
	}
	return (1);
}

static char	*create_line(t_fd_head *head, ssize_t full_len)
{
	t_list	*end;
	char	*out;
	ssize_t	line_len;

	if (!head->begin || !len_toend(head->begin->content))
		return (0);
	end = head->begin;
	while (end)
	{
		line_len = len_toend(end->content);
		full_len += line_len;
		if (!line_len)
			end = NULL;
		else
			end = end->next;
	}
	out = (char *)malloc((full_len + 1) * sizeof(char));
	if (!out)
		return (0);
	copy_to_out(out, head->begin);
	return (out);
}

static void	clean_list(t_fd_head *head, char *out)
{
	t_list	*element;
	t_list	*tmp;

	if (!head || !head->begin)
		return ;
	element = head->begin;
	while (element && (!has_nl(element->content) || !out))
	{
		tmp = element->next;
		if (element->content)
			free(element->content);
		free(element);
		element = tmp;
	}
	if (element && out)
		refactor_line(element->content);
	if (element && (!len_toend(element->content) || !out))
	{
		if (element->content)
			free(element->content);
		free(element);
		element = NULL;
	}
	head->begin = element;
}

static t_fd_head	**add_or_find_head(t_fd_head **head, int fd)
{
	while (*head)
	{
		if ((*head)->fd == fd)
			return (head);
		head = &((*head)->next);
	}
	(*head) = (t_fd_head *)malloc(sizeof(t_fd_head));
	if (!(*head))
		return (0);
	(*head)->fd = fd;
	(*head)->begin = NULL;
	(*head)->next = NULL;
	return (head);
}

char	*get_next_line(int fd)
{
	static t_fd_head	*head_list;
	t_fd_head			**head;
	t_fd_head			*tmp;
	char				*out;

	out = 0;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (0);
	head = add_or_find_head(&head_list, fd);
	if (head && fill_llist(*head, 0, 0))
		out = create_line(*head, 0);
	if (head)
		clean_list(*head, out);
	if (head && !out)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	return (out);
}
