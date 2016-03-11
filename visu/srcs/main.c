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

void	ft_debug_player(t_app *app)
{
	printf("Joueur 1 : id : %d, name : %s\n", app->p1.id, app->p1.name);
	printf("Joueur 2 : id : %d, name : %s\n", app->p2.id, app->p2.name);
}

void	ft_debug_board(t_app *app)
{
	int		i;
	int		j;
	char	**tab;

	tab = app->b.tab;
	printf("_Taille du plateau : y = %d, x = %d\n", app->b.y, app->b.x);
	i = 0;
	while (i < app->b.y)
	{
		j = 0;
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_debug_piece(t_app *app)
{
	int		i;
	int		j;
	char	**tab;

	tab = app->p.tab;
	printf("_Taille de la piece : y = %d, x = %d\n", app->p.y, app->p.x);
	i = 0;
	while (i < app->p.y)
	{
		j = 0;
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_set_player(t_app *app, char *str)
{
	t_player	p;
	int			i;
	int			start;

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

void	ft_init_board_or_piece(t_app *app, char *str)
{
	if (ft_strstr(str, "Plateau"))
	{
		if (!app->b.x)
		{
			app->b.y = ft_atoi(str += 8);
			app->b.x = ft_atoi(str += 2);
		}
		app->m = 1;
	}
	else if (ft_strstr(str, "Piece"))
	{
		app->p.y = ft_atoi(str += 6);
		app->p.x = ft_atoi(str += 2);
		app->m = 2;
	}
}

void	ft_debug_lst(t_app *app)
{
	t_list	*l;

	l = app->list_tmp;
	while (l)
	{
		printf("%s\n", l->content);
		l = l->next;
	}
}

void	ft_clear_list(t_app *app)
{
	t_list	*l;
	t_list	*tmp;

	l = app->list_tmp;
	tmp = NULL;
	while (l)
	{
		free(l->content);
		l->content = NULL;
		l->content_size = 0;
		tmp = l;
		free(l);
		l = tmp->next;
	}
	app->list_tmp = NULL;
}

void	ft_set_board(t_app *app, char *str)
{
	if (ft_strlen(str) > 5)
	{
		ft_lstpush_back(&app->list_tmp, str + 4, app->b.x);
		app->b.cl++;
		if (app->b.cl == app->b.y + 1)
		{
			app->list_tmp = app->list_tmp->next;
			app->b.tab = (char**)ft_lsttotab(app->list_tmp);
			//ft_clear_list(app);
			//ft_debug_board(app);
			app->m = 0;
			app->b.cl = 0;
		}
	}
}

void	ft_set_piece(t_app *app, char *str)
{
	if (*str)
	{
		ft_lstpush_back(&app->list_tmp, str, ft_strlen(str));
		app->p.cl++;
		if (app->p.cl == app->p.y)
		{
			app->p.tab = (char**)ft_lsttotab(app->list_tmp);
			//ft_clear_list(app);
			//ft_debug_piece(app);
			app->m = 0;
			app->p.cl = 0;
		}
	}
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
		if (line[0] && line[0] == '$')
			ft_set_player(&app, line);
		else if (line[0] && line[0] == 'P')
			ft_init_board_or_piece(&app, line);
		else if (line[0] && line[0] == '<')
		{
			continue ;
		}
		else if (app.m == 1)
			ft_set_board(&app, line);
		else if (app.m == 2)
			ft_set_piece(&app, line);
		//printf("%s\n", line);
		ft_strdel(&line);
		app.line++;
		i++;
		//if (i == 30)
		//	break ;
	}
	printf("lol\n");
	ft_debug_lst(&app);
	//ft_debug_piece(&app);
	//ft_debug_board(&app);
	//ft_debug_player(&app);
	return (0);
}