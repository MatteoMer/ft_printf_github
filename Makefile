# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:06:35 by mmervoye          #+#    #+#              #
#    Updated: 2018/10/19 13:30:48 by mmervoye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./libft/srcs/ft_atoi.c \
	  ./libft/srcs/ft_bzero.c \
	  ./libft/srcs/ft_deltab.c \
	  ./libft/srcs/ft_delfunction.c \
	  ./libft/srcs/ft_isalnum.c \
	  ./libft/srcs/ft_isspace.c\
	  ./libft/srcs/ft_isalpha.c \
	  ./libft/srcs/ft_isascii.c \
	  ./libft/srcs/ft_isdigit.c \
	  ./libft/srcs/ft_islower.c \
	  ./libft/srcs/ft_isprint.c \
	  ./libft/srcs/ft_isupper.c \
	  ./libft/srcs/ft_itoa.c \
	  ./libft/srcs/ft_lstadd.c \
	  ./libft/srcs/ft_lstdel.c \
	  ./libft/srcs/ft_lstdelone.c \
	  ./libft/srcs/ft_lstiter.c \
	  ./libft/srcs/ft_lstnew.c \
	  ./libft/srcs/ft_lstmap.c \
	  ./libft/srcs/ft_lstreverse.c \
	  ./libft/srcs/ft_memalloc.c \
	  ./libft/srcs/ft_memccpy.c \
	  ./libft/srcs/ft_memchr.c \
	  ./libft/srcs/ft_memcmp.c \
	  ./libft/srcs/ft_memcpy.c \
	  ./libft/srcs/ft_memdel.c \
	  ./libft/srcs/ft_memmove.c \
	  ./libft/srcs/ft_memset.c \
	  ./libft/srcs/ft_numlen_base.c \
	  ./libft/srcs/ft_putchar.c \
	  ./libft/srcs/ft_putchar_fd.c \
	  ./libft/srcs/ft_putendl.c \
	  ./libft/srcs/ft_putendl_fd.c \
	  ./libft/srcs/ft_putnbr.c \
	  ./libft/srcs/ft_putnbr_endl.c \
	  ./libft/srcs/ft_putnbr_fd.c \
	  ./libft/srcs/ft_putstr.c \
	  ./libft/srcs/ft_putstr_fd.c \
	  ./libft/srcs/ft_strcat.c \
	  ./libft/srcs/ft_strchr.c \
	  ./libft/srcs/ft_strclr.c \
	  ./libft/srcs/ft_strcmp.c \
	  ./libft/srcs/ft_strclen.c \
	  ./libft/srcs/ft_strcpy.c \
	  ./libft/srcs/ft_strdel.c \
	  ./libft/srcs/ft_strdup.c \
	  ./libft/srcs/ft_strequ.c \
	  ./libft/srcs/ft_striter.c \
	  ./libft/srcs/ft_striteri.c \
	  ./libft/srcs/ft_strjoin.c \
	  ./libft/srcs/ft_strjoinf.c \
	  ./libft/srcs/ft_strlcat.c \
	  ./libft/srcs/ft_strlen.c \
	  ./libft/srcs/ft_strmap.c \
	  ./libft/srcs/ft_strmapi.c \
	  ./libft/srcs/ft_strncat.c \
	  ./libft/srcs/ft_strncmp.c \
	  ./libft/srcs/ft_strncpy.c \
	  ./libft/srcs/ft_strnequ.c \
	  ./libft/srcs/ft_strnew.c \
	  ./libft/srcs/ft_strnstr.c \
	  ./libft/srcs/ft_strrchr.c \
	  ./libft/srcs/ft_strsplit.c \
	  ./libft/srcs/ft_strstr.c \
	  ./libft/srcs/ft_strsub.c \
	  ./libft/srcs/ft_strtrim.c \
	  ./libft/srcs/ft_tab_to_list.c \
	  ./libft/srcs/ft_tolower.c \
	  ./libft/srcs/ft_toupper.c \
	  ./libft/srcs/get_next_line.c \
	  ./libft/srcs/ft_count_word.c \
	  ./srcs/ft_printf.c\
	  ./srcs/ft_printf_conv.c\
	  ./srcs/ft_printf_conv_unicode_char.c\
	  ./srcs/ft_printf_conv_charc.c\
	  ./srcs/ft_printf_conv_nb.c\
	  ./srcs/ft_printf_conv_nb_2.c\
	  ./srcs/ft_printf_insert_nb.c\
	  ./srcs/ft_printf_insert_unicode_char.c\
	  ./srcs/ft_printf_insert_flags.c\
	  ./srcs/ft_printf_insert_strings.c\
	  ./srcs/ft_printf_launch.c\
	  ./srcs/ft_printf_lltoa_base.c\
	  ./srcs/ft_printf_misc.c\
	  ./srcs/ft_printf_percent.c\
	  ./srcs/ft_printf_pointer_conv.c


OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ilibft/incs -Iincludes -O2

AR = ar

ARFLAGS = rc

RL = ranlib

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(RL) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
