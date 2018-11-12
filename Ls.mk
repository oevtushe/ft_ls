# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Ls.mk                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 11:40:23 by oevtushe          #+#    #+#              #
#    Updated: 2018/11/12 13:57:50 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LS_SRCS_DIR					:= srcs
LS_OBJS_DIR					:= objs
LS_DEPS_DIR					:= includes

FT_DIR						:= $(LS_SRCS_DIR)/libft
FTP_DIR						:= $(LS_SRCS_DIR)/ft_printf

include						$(FT_DIR)/Templates.mk
include						$(FT_DIR)/Libft.mk
include						$(FTP_DIR)/Libftp.mk

LS_NAME						:= ft_ls

LS_SRCF						:=	main.c				\
								big_r.c				\
								handle_l.c			\
								ft_qslist.c			\
								ft_abs.c			\
								ft_treeadd_kid.c	\
								ft_get_fs_type.c	\
								ft_qstreelevel.c	\
								ft_arrtotreelevel.c	\
								ft_treeleveldel.c	\
								ft_treelevellen.c	\
								ft_treenew_cc.c		\
								ft_treeleveltoarr.c	\
								ft_treenew.c

LS_DEPF						:= ft_ls.h

LS_SRCS						:= $(LS_SRCF:%=$(LS_SRCS_DIR)/%)
LS_OBJS						:= $(LS_SRCF:%.c=$(LS_OBJS_DIR)/%.o)
LS_DEPS						:= $(LS_DEPF:%=$(LS_DEPS_DIR)/%)

LS_ALL_SRCS					:= $(FTP_ALL_SRCS) $(LS_SRCS)
LS_ALL_OBJS					:= $(FTP_ALL_OBJS) $(LS_OBJS)
LS_ALL_DEPS					:= $(FTP_ALL_DEPS) $(LS_DEPS)

LS_ALL_DEPS_DIRS			:= $(FTP_ALL_DEPS_DIRS) $(LS_DEPS_DIR)
LS_ALL_OBJS_DIRS			:= $(FTP_ALL_OBJS_DIRS) $(LS_OBJS_DIR)
LS_ALL_EXTRA_LIBS			:= $(FTP_NAME)
