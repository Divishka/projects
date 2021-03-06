#include "minishell.h"

void	aam_main_and(t_data *data, int ret)
{
	if (ret == 0)
		data->curr_pars = data->curr_pars->next;
	else
	{
		while (data->curr_pars->f_spec[0] != ';'
			&& !(data->curr_pars->f_spec[0] == '|'
				&& data->curr_pars->f_spec[1] == '|')
			&& data->curr_pars->next)
			data->curr_pars = data->curr_pars->next;
		if (data->curr_pars)
			data->curr_pars = data->curr_pars->next;
	}
}

void	aam_main_or(t_data *data, int ret)
{
	if (ret != 0)
		data->curr_pars = data->curr_pars->next;
	else
	{
		while (data->curr_pars->f_spec[0] != ';'
			&& data->curr_pars->f_spec[0] != '&'
			&& data->curr_pars->next)
			data->curr_pars = data->curr_pars->next;
		if (data->curr_pars)
			data->curr_pars = data->curr_pars->next;
	}
}

void	aam_main_basic_loop(t_data *data, int *ret)
{
	*ret = ft_choice_command(data);
	while (data->curr_pars->count > 1)
		data->curr_pars = data->curr_pars->next;
	if (data->curr_pars->f_spec[0] == ';')
		data->curr_pars = data->curr_pars->next;
	else if (data->curr_pars->f_spec[0] == '&'
		&& data->curr_pars->f_spec[1] == '&')
		aam_main_and(data, *ret);
	else if (data->curr_pars->f_spec[0] == '|'
		&& data->curr_pars->f_spec[1] == '|')
		aam_main_or(data, *ret);
	else
		data->curr_pars = data->curr_pars->next;
}

int	aam_main(t_data *dt)
{
	int			ret;
	t_fdesk		*fd;
	t_pars		*pars;
	t_data		*data;

	data = dt;
	pars = data->curr_pars;
	while (data->curr_pars)
	{
		fd = (t_fdesk *)malloc(sizeof(t_fdesk));
		ft_init_fd(data, &fd);
		aam_main_basic_loop(data, &ret);
		ft_free_fd(&fd);
	}
	if (fd)
		ft_free_fd(&fd);
	data->curr_pars = pars;
	return (ret);
}
