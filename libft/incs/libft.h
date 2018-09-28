/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:45:47 by mmervoye          #+#    #+#             */
/*   Updated: 2018/09/27 19:09:49 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				ft_bzero(void *s, size_t n);
void				ft_deltab(char ***tab);
void				ft_delfunction(void *content, size_t content_size);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_endl(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_memdel(void **ap);
void				ft_lstdelone(t_list **alstr, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alstr, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strclen(char *str, char c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_numlen_base(int nb, int base);
int					ft_isalpha(int c);
int					ft_isspace(char c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					get_next_line(int fd, char **line);
char				*ft_strnew(size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t len);
char				*ft_strnstr(const char *h, const char *n, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinf(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_tab_to_list(char **tab);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstreverse(t_list *lst);
void				*malloc_error(void);

#endif