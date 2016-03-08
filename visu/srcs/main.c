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

void	ft_debug_app(t_app *app)
{
	printf("Joueur 1 : id : %d, name : %s\n", app->p1.id, app->p1.name);
	printf("Joueur 2 : id : %d, name : %s\n", app->p2.id, app->p2.name);
}

void	ft_set_player(t_app *app, char *str)
{
	t_player	p;
	int			i;
	int			start;

	ft_bzero(&p, sizeof(t_player));
	if (ft_strlen(str) > 11)
		str += 10;
	p.id = ft_atoi(str);
	i = 0;
	start = 0;
	while (str[i])
	{
		start++;
		if (str[i] == '/')
			start = 0;
		i++;
	}
	str = (&str[i] - start);
	p.name = ft_strndup(str, ft_strlen(str) - 1);
	if (p.id == 1)
		app->p1 = p;
	if (p.id == 2)
		app->p2 = p;
}

int		main(void)
{
	char	*line;
	int		i;
	t_app	app;

	line = NULL;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] && line[0] == '$')
			ft_set_player(&app, line);
		//printf("%s\n", line);
		ft_strdel(&line);
		i++;
		if (i == 10)
			break ;
	}
	ft_debug_app(&app);
	return (0);
}