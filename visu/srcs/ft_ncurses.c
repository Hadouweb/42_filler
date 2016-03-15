#include "visu.h"

void	ft_nc_init_window(t_app *app)
{
	app->render.w_left = newwin(50, 150, 0, 0);
//	app->render.w_right = subwin(stdscr, 68, 55, 0, 198);
	box(app->render.w_left, ACS_VLINE, ACS_HLINE);
//	box(app->render.w_right, ACS_VLINE, ACS_HLINE);
	//refresh();
	//vm_init_const_text(app, r);
}

void	ft_nc_print_arena(t_app *app)
{
	int 	max_x;
	int 	max_y;
	int 	x;
	int 	y;
	int 	id;

	max_x = app->board.x;
	max_y = app->board.y;
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			id = 1;
			if (app->board.tab[y][x] == 'O')
				id = 2;
			else if (app->board.tab[y][x] == 'X')
				id = 4;
			else if (app->board.tab[y][x] == 'o')
				id = 6;
			else if (app->board.tab[y][x] == 'x')
				id = 8;
			wattron(app->render.w_left, COLOR_PAIR(id));
			mvwprintw(app->render.w_left, y + 1, x + 2, "%c", app->board.tab[y][x]);
			wattroff(app->render.w_left, COLOR_PAIR(id));
			//mvwprintw(app->render.w_left, y + 1, x * 2 + 4, " ");
			x++;
		}
		y++;
	}
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

void	ft_nc_key_hook(t_app *app)
{
	int		key;

	key = 0;
	if ((key = getch()) > 0)
	{
		//mvwprintw(app->render.w_left, 10, 1, "%d      ", key);
		if (key == 32 && !app->render.run)
			app->render.run = 1;
		else if (key == 32 && app->render.run)
			app->render.run = 0;
		//mvwprintw(app->render.w_left, 1, 1, "%d   %d", key, app->line);
	}
//	wrefresh(app->render.w_left);
}

int		ft_nc_update(t_app *app)
{
	ft_nc_print_arena(app);
	wrefresh(app->render.w_left);
	//usleep(10000);
	return (1);
}

static void	ft_nc_init_pair(void)
{
	/*init_pair(1, COLOR_BLACK, COL_GREY);
	init_pair(2, COLOR_BLACK, COL_RED);
	init_pair(3, COLOR_BLACK, COL_GREEN);
	init_pair(4, COLOR_BLACK, COL_BLUE);
	init_pair(5, COLOR_BLACK, COL_YELLOW);
	init_pair(6, COLOR_BLACK, COL_LIGHT_RED);
	init_pair(7, COLOR_BLACK, COL_LIGHT_GREEN);
	init_pair(8, COLOR_BLACK, COL_LIGHT_BLUE);
	init_pair(9, COLOR_BLACK, COL_LIGHT_YELLOW);*/

	init_pair(1, COL_GREY, COLOR_BLACK);
	init_pair(2, COL_RED, COLOR_BLACK);
	init_pair(3, COL_GREEN, COLOR_BLACK);
	init_pair(4, COL_BLUE, COLOR_BLACK);
	init_pair(5, COL_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COL_LIGHT_RED);
	init_pair(7, COL_LIGHT_GREEN, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COL_LIGHT_BLUE);
	init_pair(9, COL_LIGHT_YELLOW, COLOR_BLACK);
}

void		ft_nc_init_color(void)
{
	init_color(COL_GREY, 300, 300, 300);
	init_color(COL_RED, 600, 0, 0);
	init_color(COL_LIGHT_RED, 1000, 300, 300);
	init_color(COL_GREEN, 0, 600, 0);
	init_color(COL_LIGHT_GREEN, 300, 1000, 300);
	init_color(COL_BLUE, 0, 0, 600);
	init_color(COL_LIGHT_BLUE, 300, 300, 1000);
	init_color(COL_YELLOW, 600, 600, 0);
	init_color(COL_LIGHT_YELLOW, 1000, 1000, 300);
	init_color(COL_WHITE, 1000, 1000, 1000);
	ft_nc_init_pair();
}

void	ft_nc_init(t_app *app)
{
	FILE 	*file_id = fopen("/dev/tty", "r+");

	newterm(getenv("TERM"), file_id, file_id);
	app->render.run = IS_RUN;
	start_color();
	nodelay(stdscr, TRUE);
	curs_set(0);
	noecho();
	ft_nc_init_color();
	ft_nc_init_window(app);
	refresh();
}