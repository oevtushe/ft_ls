# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 11:38:23 by oevtushe          #+#    #+#              #
#    Updated: 2018/11/07 15:43:35 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include				Ls.mk

CFLAGS		+= -g

all: $(LS_NAME)

$(eval $(call BINARY_template2,LS,FT))
$(eval $(call EXTRALIB_template2,FT,libft.a,all))
$(eval $(call BASIC_template,LS))

clean:
	@$(MAKE) clean $(MFLAGS) $(FT_DIR)
	@$(RM) $(LS_OBJS_DIR)

fclean: clean
	@$(MAKE) fclean $(MFLAGS) $(FT_DIR)
	@$(RM) $(LS_OBJS_DIR)
