#include "visu.h"

static void	ft_nc_init_pair(void)
{
	init_pair(1, COL_GREY, COLOR_BLACK);
	init_pair(2, COL_RED, COLOR_BLACK);
	init_pair(3, COL_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COL_LIGHT_RED);
	init_pair(5, COLOR_BLACK, COL_LIGHT_BLUE);
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

void	ft_nc_init_window(t_app *app)
{
	app->render.w_left = newwin(app->board.y + 3, app->board.x + 4, 0, 0);
	app->render.w_right = newwin(app->board.y + 30, 40, 0, app->board.x + 5);
	box(app->render.w_left, ACS_VLINE, ACS_HLINE);
	//refresh();
	//vm_init_const_text(app, r);
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