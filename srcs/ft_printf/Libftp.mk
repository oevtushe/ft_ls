# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Libftp.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 12:51:24 by oevtushe          #+#    #+#              #
#    Updated: 2018/08/05 14:34:50 by sasha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# In your makefile set relative path to libft. For correct generating
FT_DIR			?= ../libft

FTP_DIR			?= .
FTP_NAME		:= $(FTP_DIR)/libftprintf.a

# Var for relative path. To correct output directories in FTP makefile.
RPTH			?= $(FTP_DIR)

# Obviously you don't have to include Libft.mk in your makefile.
include $(FT_DIR)/Libft.mk

FTP_DEPF		:= ft_printf.h ft_printf_helpers.h ft_structures.h
FTP_DG_SRCF		:= digits_flag_except.c \
				 signed_decimals.c \
				 unsigned_decimals.c \
				 octal_manager.c \
				 group_by_thousands.c \
				 signed_gdata_load.c \
				 binary_manager.c \
				 ft_group_by.c \
				 hex_manager.c \
				 signed_decimal_modifiers.c \
				 unsigned_decimal_modifiers.c \
				 zeroes_handling.c
FTP_STR_SRCF	:= ft_utu8.c \
				 str_manager.c \
				 str_modifiers.c \
				 ft_witomb.c \
				 chr_manager.c \
				 chr_modifiers.c
FTP_M_SRCF		:= ft_printf.c \
				 format_parser.c \
				 split_string.c \
				 get_format_string.c \
				 get_arr_size.c \
				 get_data_arr.c \
				 get_type_arr.c \
				 spaces_handling.c \
				 ptr_manager.c \
				 normalize_full_type.c \
				 ft_memct.c \
				 mk_format.c \
				 ft_memjoin.c \
				 new_gdata.c \
				 new_full_type.c \
				 get_manager_dispatcher.c \
				 string_readers.c \
				 ft_lstaddelem.c \
				 percent_manager.c \
				 logic_type.c \
				 normalize_width.c \
				 get_cur_data.c \
				 outside_param.c \
				 is_type.c \
				 validate_lists.c \
				 ft_format.c \
				 repeat_manager.c \
				 freshers.c

FTP_SRCS_DIR	:= $(FTP_DIR)/srcs
FTP_DEPS_DIR	:= $(FTP_DIR)/includes

# Auxiliary variables for FTP_SRCS and FTP_OBJS.
# You don't have to use them.
FTP_DG_DIR		:= $(FTP_SRCS_DIR)/digits
FTP_STR_DIR		:= $(FTP_SRCS_DIR)/strings
FTP_OBJS_DIR	:= $(FTP_DIR)/objs
FTP_M_SRCS		:= $(addprefix $(FTP_SRCS_DIR)/,$(FTP_M_SRCF))
FTP_DG_SRCS		:= $(addprefix $(FTP_DG_DIR)/,$(FTP_DG_SRCF))
FTP_STR_SRCS	:= $(addprefix $(FTP_STR_DIR)/,$(FTP_STR_SRCF))

FTP_DEPS		:= $(addprefix $(FTP_DEPS_DIR)/,$(FTP_DEPF))
FTP_SRCS		:= $(FTP_M_SRCS) $(FTP_DG_SRCS) $(FTP_STR_SRCS)
FTP_OBJS		:= $(FTP_SRCS:$(FTP_SRCS_DIR)/%.c=$(FTP_OBJS_DIR)/%.o)
FTP_ALL_OBJS_DIRS	:= $(FTP_OBJS_DIR) \
	$(FTP_DG_DIR:$(FTP_SRCS_DIR)%=$(FTP_OBJS_DIR)%) \
	$(FTP_STR_DIR:$(FTP_SRCS_DIR)%=$(FTP_OBJS_DIR)%)
FTP_ALL_DEPS	:= $(FT_ALL_DEPS) $(FTP_DEPS)
FTP_ALL_DEPS_DIRS	:= $(FT_ALL_DEPS_DIRS) $(FTP_DEPS_DIR)
FTP_ALL_OBJS	:= $(FT_OBJS) $(FTP_OBJS)
FTP_ALL_EXTRA_LIBS	:= $(FT_NAME)
FTP_ALL_SRCS		:= $(FT_SRCS) $(FTP_SRCS)
