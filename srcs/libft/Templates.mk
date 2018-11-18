# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Templates.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasha <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/05 12:30:58 by sasha             #+#    #+#              #
#    Updated: 2018/11/05 12:26:26 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Templates for basic project compilation
#
# Templates description:
#
# 	BASIC		->	objects dir creation and
# 					objects compilation with
# 					pretty output
#	
#	EXTRALIB	->	Calls for other makefile to compile
#					additional library
#
#	LIB			->	Make a lib from objects
#
#	BINARY		->	Make a binary file from objects and libs
#
#
# Variables that has to be defined before using templates:
#
# 	* <PFX>_NAME			->	a name of binary/library
#
# 	* <PFX>_DEPS_DIR		->	dir where *.h located
# 	* <PFX>_OBJS_DIR		->	dir with objs files
# 	* <PFX>_SRCS_DIR		->	dir with srcs files
#
# 	* <PFX>_SRCS			->	sorces for current project
# 	* <PFX>_DEPS			->	*.h files for current project
# 	* <PFX>_OBJS			->	object files for current project
#
# 	* <PFX>_ALL_DEPS		->	all *.h files needed
# 								for current project
# 	* <PFX>_ALL_DEPS_DIRS	->	all deps dirs that will
# 								be created
# 	* <PFX>_ALL_OBJS_DIRS	->	all objs dirs for current
# 								project
# 	* <PFX>_ALL_OBJS		->  all objs for cur project 
# 	* <PFX>_ALL_SRCS		->	all srcs needed for
# 								current project
# 	* <PFX>_ALL_EXTRA_LIBS	->	all additional librarys (names)
# 								needed for this project
#
# <PFX> - stands for 'prefix'.
#
# Copy and init this vars:
#
#		<PFX>_NAME
#
#		<PFX>_SRCS_DIR
#		<PFX>_OBJS_DIR
#		<PFX>_DEPS_DIR
#
#		<PFX>_SRCS
#		<PFX>_OBJS
#		<PFX>_DEPS
#
#		<PFX>_ALL_SRCS
#		<PFX>_ALL_OBJS
#		<PFX>_ALL_DEPS
#
#		<PFX>_ALL_DEPS_DIRS
#		<PFX>_ALL_OBJS_DIRS
#		<PFX>_ALL_EXTRA_LIBS
#
# -------------------------------------------------------------------------------------
# Or use basic template:
#
# <NAME>.mk:
#
#	<HERE>_SRCS_DIR					:= srcs
#	<HERE>_OBJS_DIR					:= objs
#	<HERE>_DEPS_DIR					:= includes
#
#	<HERE>_DIR						:= $(<HERE>_SRCS_DIR)/libft
#
#	<HERE>clude						$(FT_DIR)/Templates.mk
#	<HERE>clude						$(FT_DIR)/Libft.mk
#
#	<HERE>_NAME						:=
#
#	<HERE>_SRCF						:=
#
#	<HERE>_SRCS						:= $(<HERE>_SRCF:%=$(<HERE>_SRCS_DIR)/%)
#	<HERE>_OBJS						:= $(<HERE>_SRCF:%.c=$(<HERE>_OBJS_DIR)/%.o)
#	<HERE>_DEPS						:=
#
#	<HERE>_ALL_SRCS					:= $(FT_ALL_SRCS) $(<HERE>_SRCS)
#	<HERE>_ALL_OBJS					:= $(FT_ALL_OBJS) $(<HERE>_OBJS)
#	<HERE>_ALL_DEPS					:= $(FT_ALL_DEPS) $(<HERE>_DEPS)
#
#	<HERE>_ALL_DEPS_DIRS			:= $(FT_ALL_DEPS_DIRS) $(<HERE>_DEPS_DIR)
#	<HERE>_ALL_OBJS_DIRS			:= $(FT_ALL_OBJS_DIRS) $(<HERE>_OBJS_DIR)
#	<HERE>_ALL_EXTRA_LIBS			:= $(FT_NAME)
#
# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#
# Makefile:
#
#	include				<NAME>.mk
#	
#	all: $(<HERE>_NAME)
#	
#	$(eval $(call BINARY_template2,<HERE>,FT))
#	$(eval $(call EXTRALIB_template2,FT,libft.a,all))
#	$(eval $(call BASIC_template,<HERE>))
#	
#	clean:
#		@$(MAKE) clean $(MFLAGS) $(FT_DIR)
#		@$(RM) $(<HERE>_OBJS_DIR)
#	
#	fclean: clean
#		@$(MAKE) fclean $(MFLAGS) $(FT_DIR)
#		@$(RM) $(<HERE>_OBJS_DIR)
#
# -------------------------------------------------------------------------------------
#
# Concise advantages and disadvantages of *_template1 and *_template2:
#
# 	*_template1	->	recompile modified files when one of *.c *.h *.o files was
# 					changed. If changed file is one from the sub-level library
# 					(current lib depends on) than nothing will be recompiled.
# 					So it useful only for root librarys.
#
# 	*_template2	->	recompile modified files when one of *.c *.h files was changed.
# 					Also recompiles project if sub-level library files was changed.
# 					But absence of/modifying *.o files won't be a reason for recompiling.
#
# NOTICE:	use only templates with the same number in the end, so that if you use
# 			BINARY_template1 and want to use EXTRALIB_template you have to choose
# 			EXTRALIB_template1, etc..

RM			 		:= rm -rf
AR			 		:= ar
CC			 		:= gcc
ARFLAGS		 		:= rc
CFLAGS		 		:= -Wall -Werror -Wextra
MFLAGS		 		:= --no-print-directory -C

define BINARY_template1
$$($(1)_NAME): $$($(1)_ALL_OBJS)
	@printf "\r\033[38;5;117m✓ $$@ created\033[0m\033[K\n"
	@$$(CC) $$(CFLAGS) -o $$($(1)_NAME) $$^ $$($(2)_NAME)
endef

define BINARY_template2
$$($(1)_NAME): $$($(1)_ALL_EXTRA_LIBS) $$($(1)_OBJS)
	@printf "\r\033[38;5;117m✓ $$@ created\033[0m\033[K\n"
	@$$(CC) $$(CFLAGS) -o $$($(1)_NAME) $$^ $$($(2)_NAME) $$($(1)_EXTRA)
endef

define BASIC_template
ifeq ($$(MAKELEVEL),0)
WCOMPILE_P = @printf "\033[2KCompiling: $$(@:%=$$(RPTH)/%)\r"
else
WCOMPILE_P = @printf "\033[2KCompiling: $$(@:%=$$(RPTH)/%)\r"
endif

$$($(1)_OBJS_DIR)/%.o: $$($(1)_SRCS_DIR)/%.c $$($(1)_ALL_DEPS)
	$$(WCOMPILE_P)
	@$(CC) $(CFLAGS) -o $$@ -c $$< $$($(1)_ALL_DEPS_DIRS:%=-I%)
$$($(1)_OBJS): |$$($(1)_ALL_OBJS_DIRS)

$$($(1)_ALL_OBJS_DIRS):
	@mkdir $$@

re: fclean all

.PHONY: all clean fclean re obj
endef

define EXTRALIB_template1
$$($(1)_OBJS_DIR)/%.o: $$($(1)_SRCS_DIR)/%.c $$($(1)_DEPS)
	@$$(MAKE) $(3) RPTH=$$($(1)_DIR) $$(MFLAGS) $$($(1)_DIR)
endef

define EXTRALIB_template2
$$($(1)_NAME): $$($(1)_ALL_SRCS) $$($(1)_ALL_DEPS)
	@$$(MAKE) $(3) RPTH=$$($(1)_DIR) $$(MFLAGS) $$($(1)_DIR)
endef

define LIB_template
$$($(1)_NAME): $$($(1)_ALL_OBJS)
	@$$(AR) $$(ARFLAGS) $$($(1)_NAME) $$?
	@ranlib $$($(1)_NAME)
endef
