#include "visu.h"

void	ft_parsing(t_app *app, char *str)
{
	if (str[0])
	{
		if (str[0] == '$')
			ft_set_player(app, str);
		else if (str[0] == 'P')
			ft_init_board_or_piece(app, str);
		else if (str[0] == '<')
			ft_set_current_player(app, str);
		else if (app->mode == 1)
			ft_set_board(app, str);
		else if (app->mode == 2)
			ft_set_piece(app, str);
		else if (str[0] == '=')
			ft_set_winner(app, str);
	}
}

int		main(void)
{
	char	*line;
	t_app	app;

	line = NULL;
	ft_bzero(&app, sizeof(t_app));
	app.list_tmp = NULL;
	ft_nc_init(&app);
	while (1)
	{
		//printf("%s\n", line);
		if (app.render.run || !app.start)
		{
			if (get_next_line(0, &line) > 0)
			{
				ft_parsing(&app, line);
				ft_strdel(&line);
				app.line++;
			}
			else
				break ;
		}
		ft_nc_key_hook(&app);
	}
	//sleep(2);
	return (0);
}