# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Ls.mk                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 11:40:23 by oevtushe          #+#    #+#              #
#    Updated: 2018/11/09 18:57:04 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LS_SRCS_DIR					:= srcs
LS_OBJS_DIR					:= objs
LS_DEPS_DIR					:= includes

FT_DIR						:= $(LS_SRCS_DIR)/libft

include						$(FT_DIR)/Templates.mk
include						$(FT_DIR)/Libft.mk

LS_NAME						:= ft_ls

LS_SRCF						:=	main.c				\
								big_r.c				\
								ft_treeadd_kid.c	\
								ft_get_fs_type.c	\
								ft_treenew.c

LS_SRCS						:= $(LS_SRCF:%=$(LS_SRCS_DIR)/%)
LS_OBJS						:= $(LS_SRCF:%.c=$(LS_OBJS_DIR)/%.o)
LS_DEPS						:=

LS_ALL_SRCS					:= $(FT_ALL_SRCS) $(LS_SRCS)
LS_ALL_OBJS					:= $(FT_ALL_OBJS) $(LS_OBJS)
LS_ALL_DEPS					:= $(FT_ALL_DEPS) $(LS_DEPS)

LS_ALL_DEPS_DIRS			:= $(FT_ALL_DEPS_DIRS) $(LS_DEPS_DIR)
LS_ALL_OBJS_DIRS			:= $(FT_ALL_OBJS_DIRS) $(LS_OBJS_DIR)
LS_ALL_EXTRA_LIBS			:= $(FT_NAME)
