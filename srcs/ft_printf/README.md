# Printf

Project in *42 School*.

My version of well known function *printf*.

### How to add new type ?
1. Add new type in enumeration `t_type` in `includes/ft_structures.h`
2. Add new type in function `is_type`
3. Bind new type with corresponding loader in `srcs/init_loader.c`
4. Write new function `char *<name>_manager(t_format *sfmt, size_t *len)`
(in new file `srcs/<name>_manager.c`) which will be executed when new key appears
5. Add new file name in `Libftp.mk` in variable `FTP_M_SRCF`
6. In `get_manager_dispatcher.c` add your function in dispatcher array
7. Increase by one variable `DISPATCHER_SIZE` in `includes/ft_structures.h`

> New type can use all standart modifiers and flags.
