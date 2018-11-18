# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 08:08:33 by oevtushe          #+#    #+#              #
#    Updated: 2018/11/18 13:34:50 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FT_DEPS FT_SRCS use this variable. So if you need to get right
# dependencies don't forget to define FT_DIR before including this file.
FT_DIR				?= .

RPTH				?= $(FT_DIR)

# Example of use this header in your Makefile:
# *
# *
# FT_DIR 	:= <libft path>
# include $(FT_DIR)/Libft.mk
# *
# *
# If you want to compile only objs files:
# $(NAME): $(FT_OBJS) ...
# $(FT_OBJS_DIR)/%.o: $(FT_DIR)/%.c $(FT_DEPS)
#	 @$(MAKE) obj RPTH=<relative path to libft> $(MFLAGS) $(FT_DIR)
#
# Or you want lib:
# $(NAME): $(FT_OBJS) ...
# $(FT_NAME): $(FT_SRCS) $(FT_DEPS)
# 	 @$(MAKE) RPTH=<relative path to libft> $(MFLAGS) $(FT_DIR)

FT_SRCF				:= ft_bzero.c			\
					   ft_memcmp.c 			\
					   ft_memmove.c 		\
					   ft_memset.c 			\
					   ft_strlen.c 			\
					   ft_strdup.c 			\
					   ft_strcpy.c 			\
					   ft_strncpy.c 		\
					   ft_strcat.c			\
					   ft_strncat.c 		\
					   ft_strlcat.c			\
					   ft_strchr.c			\
					   ft_strrchr.c 		\
					   ft_strcmp.c 			\
					   ft_strstr.c			\
					   ft_strnstr.c			\
					   ft_strncmp.c			\
					   ft_atoi.c			\
					   ft_itoabase.c		\
					   ft_intln.c			\
					   ft_isalpha.c			\
					   ft_isdigit.c			\
					   ft_isalnum.c 		\
					   ft_isascii.c			\
					   ft_isnumber.c		\
					   ft_isprint.c			\
					   ft_isvldint.c		\
					   ft_toupper.c			\
					   ft_tolower.c			\
					   ft_memalloc.c		\
					   ft_memdel.c			\
					   ft_strnew.c			\
					   ft_strdel.c			\
					   ft_strclr.c			\
					   ft_striter.c			\
					   ft_striteri.c 		\
					   ft_strmap.c			\
					   ft_strmapi.c			\
					   ft_strequ.c			\
					   ft_strnequ.c			\
					   ft_strsub.c			\
					   ft_strjoin.c			\
					   ft_strtrim.c			\
					   ft_putchar.c			\
					   ft_putstr.c			\
					   ft_putendl.c			\
					   ft_putchar_fd.c		\
					   ft_putstr_fd.c		\
					   ft_putnbr.c			\
					   ft_putnbr_fd.c		\
					   ft_itoa.c			\
					   ft_lstnew.c			\
					   ft_lstdelone.c		\
					   ft_lstdel.c			\
					   ft_lstadd.c			\
					   ft_lstiter.c			\
					   ft_lstappend.c		\
					   ft_memdup.c			\
					   ft_lstlen.c			\
					   ft_lstmap.c			\
					   ft_strsplit.c		\
					   ft_memcpy.c			\
					   ft_memchr.c			\
					   ft_putendl_fd.c		\
					   ft_memccpy.c			\
					   ft_strconnect.c		\
					   ft_swap.c			\
					   ft_strfnd.c			\
					   ft_str_realloc.c		\
					   ft_lstcorder.c		\
					   ft_uitoabase_gen.c	\
					   ft_putstr_ln.c		\
					   ft_spsign.c			\
					   ft_strcntllr.c		\
					   ft_strtoupper.c		\
					   ft_lstswap.c			\
					   ft_lstget.c			\
					   ft_lstnew_de.c		\
					   ft_lstdelone_de.c	\
					   ft_lstdel_de.c		\
					   ft_lstadd_de.c		\
					   ft_lstiter_de.c		\
					   ft_lstmap_de.c		\
					   ft_lstappend_de.c	\
					   ft_lstlen_de.c		\
					   ft_lstcorder_de.c	\
					   ft_lstswap_de.c		\
					   ft_lstget_de.c		\
					   ft_strimplode.c		\
					   ft_newpair.c			\
					   ft_lstdelsafe.c		\
					   ft_lstdequeue.c		\
					   ft_lstgetidx.c		\
					   ft_lstpeeklast.c		\
					   ft_realloc.c			\
					   ft_lstpop.c			\
					   ft_parrdel_zt.c		\
					   ft_parrlen_zt.c		\
					   ft_strchcnt.c		\
					   ft_arrgetidx.c		\
					   ft_argsparser.c		\
					   ft_argsparser_ti.c	\
					   ft_freepa.c			\
					   ft_freepa_sd.c		\
					   ft_lstnew_cc.c		\
					   ft_newpair_cc.c		\
					   get_next_line.c		\
					   ft_lsttoarr.c		\
					   ft_qsarr.c			\
					   ft_arrtolst.c		\
					   ft_abs.c				\
					   ft_treenew.c			\
					   ft_treenew_cc.c		\
					   ft_treeadd_kid.c		\
					   ft_treedel.c			\
					   ft_qstreelevel.c		\
					   ft_treeleveltoarr.c	\
					   ft_treelevellen.c	\
					   ft_treeleveldel.c	\
					   ft_treenew_spec.c	\
					   ft_qslist.c			\
					   ft_arrtotreelevel.c	\
					   ft_count_words.c

FT_NAME				:= $(FT_DIR)/libft.a

FT_DEPS_DIR			:= $(FT_DIR)/includes
FT_SRCS_DIR			:= $(FT_DIR)/srcs
FT_DEPF				:= libft.h
FT_DEPS				:= $(addprefix $(FT_DEPS_DIR)/,$(FT_DEPF))

FT_SRCS				:= $(addprefix $(FT_SRCS_DIR)/,$(FT_SRCF))
FT_OBJS_DIR			:= $(FT_DIR)/objs
FT_OBJS				:= $(FT_SRCS:$(FT_SRCS_DIR)/%.c=$(FT_OBJS_DIR)/%.o)
FT_ALL_DEPS_DIRS	:= $(FT_DEPS_DIR)
FT_ALL_DEPS			:= $(FT_DEPS)
FT_ALL_OBJS_DIRS	:= $(FT_OBJS_DIR)
FT_ALL_OBJS			:= $(FT_OBJS)
FT_ALL_SRCS			:= $(FT_SRCS)
