# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:47:27 by oevtushe          #+#    #+#              #
#    Updated: 2018/08/07 15:59:46 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override FTP_DIR	:= .
include 	 		Libftp.mk
include		 		$(FT_DIR)/Pretty.mk
include				$(FT_DIR)/Templates.mk


all: $(FTP_NAME)
obj: $(FTP_OBJS)

$(eval $(call EXTRALIB_template1,FT,libft,obj))
$(eval $(call LIB_template,FTP,ft_printf))
$(eval $(call BASIC_template,FTP))

clean:
	@$(RM) $(FTP_OBJS_DIR)
	@$(MAKE) clean $(MFLAGS) $(FT_DIR)
fclean: clean
	@$(RM) $(FTP_NAME)
