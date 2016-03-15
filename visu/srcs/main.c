#include "visu.h"

void	ft_init_ncurses()
{
	initscr();
	start_color();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_BLUE);
	//vm_init_window(r);
}

void	ft_parsing(t_app *app, char *str)
{
	if (str[0] && str[0] == '$')
		ft_set_player(app, str);
	else if (str[0] && str[0] == 'P')
		ft_init_board_or_piece(app, str);
	else if (str[0] && str[0] == '<')
		;
	else if (app->mode == 1)
		ft_set_board(app, str);
	else if (app->mode == 2)
		;//ft_set_piece(app, str);
}

int		main(void)
{
	char	*line;
	int		i;
	t_app	app;

	line = NULL;
	i = 0;
	ft_bzero(&app, sizeof(t_app));
	app.list_tmp = NULL;
	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
		ft_parsing(&app, line);
		ft_strdel(&line);
		app.line++;
		i++;
		if (i == 18)
			exit(1);
	}
	return (0);
}