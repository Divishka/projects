#include "minishell.h"

int	ft_cd_argv(t_pars *pars, t_data *data, char **path)
{
	int		code;

	code = 0;
	if (pars->argv[1][0] == '~' && pars->argv[1][1] == '\0')
		*path = ft_path_home(data);
	else if (pars->argv[1][0] == '~' && pars->argv[1][1] != '\0')
		return (ft_output_err(1, pars->argv[1],
				": No such file or directory\n", NULL));
	else if (pars->argv[1] != NULL && pars->argv[1][0] == '-'
		&& ft_strlen(pars->argv[1]) == 1)
	{
		code = ft_path_back(data, path);
		if (code != 0)
			return (code);
	}
	else if (pars->argv[1][0] == '-' && pars->argv[1][1] != '\0')
	{
		pars->argv[1][2] = '\0';
		return (ft_output_err(1, pars->argv[1],
				": invalid option\n", "cd: usage: cd [-L|-P] [dir]\n"));
	}
	else
		*path = ft_strdup(pars->argv[1]);
	return (code);
}

int	ft_check_home(t_data *data)
{
	int	i;

	i = -1;
	while (data->envp[++i])
	{
		if (ft_strncmp(data->envp[i], "HOME=", 5) == 0)
			return (1);
	}
	return (0);
}

int	ft_cd(t_data *data, t_pars *pars)
{
	int			code;
	char		*path;

	path = NULL;
	code = 0;
	if (pars->argv[1] == NULL)
	{
		if (ft_check_home(data) == 0)
			return (ft_output_err(1, "cd: ", "HOME not set\n", NULL));
		path = ft_path_home(data);
	}
	else
		code = ft_cd_argv(pars, data, &path);
	if (code != 0)
		return (code);
	if (path)
		code = ft_cd_path(data, &path);
	if (code != 0)
		return (code);
	if (path)
		free(path);
	return (code);
}
