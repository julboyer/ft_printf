NAME=libftprintf.a

NLIBFT = libft.a

LCPATH = ./libft/

CPATH = ./srcs/

LSRCS = ${LCPATH}ft_atoi.c \
		${LCPATH}ft_isalnum.c \
		${LCPATH}ft_isalpha.c \
		${LCPATH}ft_isascii.c \
		${LCPATH}ft_isdigit.c \
		${LCPATH}ft_isprint.c \
		${LCPATH}ft_strchr.c \
		${LCPATH}ft_strlen.c \
		${LCPATH}ft_strncmp.c \
		${LCPATH}ft_strnstr.c \
		${LCPATH}ft_strrchr.c \
		${LCPATH}ft_tolower.c \
		${LCPATH}ft_toupper.c \
		${LCPATH}ft_strlcpy.c \
		${LCPATH}ft_strlcat.c \
		${LCPATH}ft_memset.c \
		${LCPATH}ft_bzero.c \
		${LCPATH}ft_memccpy.c \
		${LCPATH}ft_strdup.c \
		${LCPATH}ft_memchr.c \
		${LCPATH}ft_memcmp.c \
		${LCPATH}ft_memmove.c \
		${LCPATH}ft_memcpy.c \
		${LCPATH}ft_calloc.c \
		${LCPATH}ft_substr.c \
		${LCPATH}ft_strjoin.c \
		${LCPATH}ft_split.c \
		${LCPATH}ft_putstr_fd.c \
		${LCPATH}ft_putchar_fd.c \
		${LCPATH}ft_itoa.c \
		${LCPATH}ft_putendl_fd.c \
		${LCPATH}ft_putnbr_fd.c \
		${LCPATH}ft_strmapi.c \
		${LCPATH}ft_strtrim.c \
		${LCPATH}ft_lstlast.c \
		${LCPATH}ft_lstsize.c \
		${LCPATH}ft_lstiter.c \
		${LCPATH}ft_lstnew.c \
		${LCPATH}ft_lstadd_back.c \
		${LCPATH}ft_lstadd_front.c \
		${LCPATH}ft_lstdelone.c \
		${LCPATH}ft_lstclear.c \
		${LCPATH}ft_lstmap.c \
		${LCPATH}ft_strcat.c \
		${LCPATH}ft_strcpy.c \
		${LCPATH}ft_strncpy.c \
		${LCPATH}get_next_line.c

SRCS =	${CPATH}ft_atoll.c \
		${CPATH}ft_c_handle.c\
		${CPATH}ft_d_handle.c \
		${CPATH}ft_dot_flag.c \
		${CPATH}ft_diese_flag.c \
		${CPATH}ft_isprintconvert.c \
		${CPATH}ft_isprintflag.c \
		${CPATH}ft_lltoa_abs.c \
		${CPATH}ft_nhandle.c \
		${CPATH}ft_p_handle.c \
		${CPATH}ft_positive_flag.c \
		${CPATH}ft_printarg.c \
		${CPATH}ft_printf.c \
		${CPATH}ft_putwc.c \
		${CPATH}ft_shandle.c \
		${CPATH}ft_ulltoa_base.c \
		${CPATH}ft_width.c \
		${CPATH}ft_xhandle.c \
		${CPATH}ft_zero_flag.c

LOBJ = ${LSRCS:.c=.o}

OBJ = ${SRCS:.c=.o}

HEADERS = ./headers

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

all :	${NAME}

$(NAME) :	${LOBJ} ${OBJ}
			ar rcs ${NAME} ${LOBJ} ${OBJ}

clean :	
		${RM} ${LOBJ} ${OBJ} ${NLIBFT}

fclean :	clean
			${RM} ${NAME}

re :	fclean all

libft : ${LOBJ}
		ar rcs ${NLIBFT} ${LSRCS}

.PHONY: all clean fclean re so
