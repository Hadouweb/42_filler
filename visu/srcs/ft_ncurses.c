#include "visu.h"

void	ft_nc_init_window(t_app *app)
{
	app->render.w_left = newwin(50, 50, 0, 0);
	app->render.w_right = subwin(stdscr, 68, 55, 0, 198);
	box(app->render.w_left, ACS_VLINE, ACS_HLINE);
	box(app->render.w_right, ACS_VLINE, ACS_HLINE);
	//vm_init_const_text(app, r);
}

void	ft_nc_print_arena(t_app *app)
{
	wrefresh(app->render.w_right);
	wrefresh(app->render.w_left);
}

int		vm_nc_event(void)
{
	int		ch;

	ch = getch();
	if (ch != ERR)
	{
		ungetch(ch);
		return (1);
	}
	return (0);
}

int		ft_nc_update(t_app *app)
{
	int		key;

	key = 0;
	//setbuf(stdout, NULL);
	if ((key = getch()) > 0)
		mvwprintw(app->render.w_left, 10, 1, "%d      ", key);
	mvwprintw(app->render.w_left, 2, 3, "%d  ", app->line);
	wrefresh(app->render.w_right);
	wrefresh(app->render.w_left);
	return (1);
}

void	ft_nc_init(t_app *app)
{
	app->render.run = IS_RUN;
	initscr();
	start_color();
	nodelay(stdscr, TRUE);
	curs_set(0);
	noecho();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_BLUE);
	ft_nc_init_window(app);
	ft_nc_print_arena(app);
}