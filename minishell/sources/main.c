#include "minishell.h"

t_data		*g_data;

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		error;

	init_struct(&data, envp);
	error = 0;
	g_data = &data;
	(void)argv;
	(void)argc;
	main_loop(&data);
	free_struct(&data);
	return (error);
}
