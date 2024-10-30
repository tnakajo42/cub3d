/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:55:07 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 15:58:59 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

// struct for linked lists
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// printf-struct for subspecifiers
typedef struct s_subs
{
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_hash;
	char	flag_zero;
	int		width;
	int		precision;
}	t_subs;

// linked lists-struct with fd-information
typedef struct s_fd_head
{
	int					fd;
	struct s_fd_head	*next;
	t_list				*begin;
}	t_fd_head;

// BASICS:
int		ft_atoi(const char *string);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	ft_isai(const char *string);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *buf, int c, size_t count);
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *dest, int c, size_t count);
char	**ft_split(char const *s, char c);
void	ft_split_free(char **split);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(const char *string);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlen(const char *string);
int		ft_strncmp(const char *string1, const char *string2, size_t count);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *string, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
// printf-functions
int		ft_printf(const char *input, ...);
int		ft_pf_putchar(char c, t_subs *subs);
int		ft_pf_strlen(char *str);
void	ft_pf_repchar(char c, int rep);
int		ft_pf_putstr(char *str, t_subs *subs);
int		ft_pf_atoi(const char **string);
int		ft_pf_putptr(void *ptr, t_subs *subs);
int		ft_pf_intlen(int input);
int		ft_pf_putint(int input, int len, t_subs *subs);
int		ft_pf_putunsigned(unsigned int input, t_subs *subs);
int		ft_pf_puthex(char *set, unsigned int input, t_subs *subs);
int		ft_pf_putperc(void);
// Get Next Line functions
char	has_nl(char *line);
void	refactor_line(char *text);
ssize_t	len_toend(char *element);
void	copy_to_out(char *out, t_list *segment);
char	*get_next_line(int fd);

// BONUS Linked Lists:
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif 
