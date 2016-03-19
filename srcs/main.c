#include "filler.h"

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
	}
}

int		main(void)
{
	char	*line;
	t_app	app;

	ft_bzero(&app, sizeof(t_app));
	app.play = 1;
	while (get_next_line(0, &line))
	{
		ft_parsing(&app, line);
		if (!app.play)
			ft_putstr("0 0\n");
		ft_strdel(&line);
	}
	return (0);
}