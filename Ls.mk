# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Ls.mk                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 11:40:23 by oevtushe          #+#    #+#              #
#    Updated: 2018/11/18 14:01:32 by oevtushe         ###   ########.fr        #
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

LS_NAME						:=	ft_ls

LS_SRCF						:=	main.c						\
								big_r.c						\
								handle_l.c					\
								entrynew.c					\
								sort_entry_comparators.c	\
								printers.c					\
								init_rights.c				\
								helpers.c					\
								sort_data.c

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
