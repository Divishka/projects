NAME		= minishell

LIBDIR		= ./libft/
LIBFT		= $(LIBDIR)libft.a

LIBFLAGS	= -L libft -lft -lreadline -L/Users/awhana/.brew/opt/readline/lib -ltermcap -L/usr/local/opt/readline/lib

CFLAGS		= -Wall -Wextra -Werror
CC			= gcc -g

INCLUDES	= -I ./includes/. -I $(LIBDIR)includes/.  -I/Users/awhana/.brew/opt/readline/include -I/usr/local/opt/readline/include
HEADER		= ./includes/minishell.h

SRCDIR		= ./sources/
OBJDIR		= ./objs/

FLS			= \
			main \
			init_structs \
			mainloop \
			check_line \
			pars_and_run \
			parser \
			pars_struct \
			pars_command \
			brakets_clean \
			insert_env_var \
			get_var_name \
			replace_path \
			read_stdin \
			split_argv \
			split_command \
			split_tools \
			redirects \
			get_redirects \
			quaote_open \
			rl_with_hist \
			rl_without_hist \
			term_rl \
			term_read \
			term_keys \
			tmp_files_tools \
			str_utils_2 \
			tools \
			history \
			errors \
			clears \
			minishell_pipe \
			str_utils \
			export_main \
			export \
			unset_main \
			unset \
			env_main \
			exit_main \
			pwd_main \
			cd_main \
			cd \
			echo_main \
			output_err \
			cd_path \
			minishell_main \
			minishell_init \
			minishell_choice \
			minishell_utils \
			minishell_build \
			redirect

SRC			= $(FLS)

OBJ			= $(addprefix $(OBJDIR), $(SRC:=.o))
DFLS		= $(SRC:=.d)

all: $(LIBFT) | $(NAME)
	$(MAKE) $(NAME)

$(OBJ):			$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@$(CC)		$(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD
	@echo "Compiled $@"

$(NAME):		$(OBJDIR) $(LIBFT) $(OBJ)
	@echo '----Making minishell ------'
	$(CC)		$(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFLAGS) -o $(NAME)
	@echo "Ready"

$(OBJDIR):
	@mkdir -p $@

include $(wildcard $(addprefix $(OBJDIR), $(DFLS)))

$(LIBFT):	#FORCE
	@echo '---Making libft ------'
	$(MAKE) -C $(LIBDIR)
	@echo 'Making libft done'

#FORCE:

clean:
	$(MAKE) clean	-C $(LIBDIR)
	rm -rf		$(OBJDIR) *.o *.d

fclean:		clean
	$(MAKE) fclean	-C $(LIBDIR)
	rm -f		$(NAME)
	rm -rf		.*.tmp *.tmp

re:		fclean
	$(MAKE)

norma:
	norminette $(SRCDIR) $(LIBDIR)srcs/*.c $(LIBDIR)includes/*.h ./includes/

bonus:	all

.PHONY: all debug clean fclean re bonus
