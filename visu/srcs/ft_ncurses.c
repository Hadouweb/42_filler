#include "visu.h"

void	ft_nc_key_hook(t_app *app)
{
	int		key;

	key = 0;
	if ((key = getch()) > 0)
	{
		//mvwprintw(app->render.w_right, 10, 1, "%d      ", key);
		if (key == 32 && !app->render.run)
			app->render.run = 1;
		else if (key == 32 && app->render.run)
			app->render.run = 0;
		else if (key == 65 && app->speed < 20)
			app->speed += 1;
		else if (key == 66 && app->speed > 1)
			app->speed -= 1;
	}
	if (app->render.run)
		mvwprintw(app->render.w_right, 1, 3, "** RUNNING **");
	else
		mvwprintw(app->render.w_right, 1, 3, "** PAUSED ** ");
	mvwprintw(app->render.w_right, 3, 3, "Vitesse : %d ", app->speed);
	if (app->is_finish)
	{
		wclear(app->render.w_right);
		mvwprintw(app->render.w_right, 1, 3, "Score :");
		wattron(app->render.w_right, COLOR_PAIR(2));
		mvwprintw(app->render.w_right, 3, 3, "%s : %d", app->p1.name, app->p1_score);
		wattroff(app->render.w_right, COLOR_PAIR(2));
		wattron(app->render.w_right, COLOR_PAIR(3));
		mvwprintw(app->render.w_right, 4, 3, "%s : %d", app->p2.name, app->p2_score);
		wattroff(app->render.w_right, COLOR_PAIR(3));
		mvwprintw(app->render.w_right, app->board.y, 3, "ESC pour quitter", app->speed);
		wrefresh(app->render.w_right);
		while (getch() != 27)
			;
		wclear(app->render.w_right);
		wclear(app->render.w_left);
	}
	wrefresh(app->render.w_right);
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
				id = 3;
			else if (app->board.tab[y][x] == 'o')
				id = 4;
			else if (app->board.tab[y][x] == 'x')
				id = 5;
			wattron(app->render.w_left, COLOR_PAIR(id));
			mvwprintw(app->render.w_left, y + 1, x + 2, "%c", app->board.tab[y][x]);
			wattroff(app->render.w_left, COLOR_PAIR(id));
			//mvwprintw(app->render.w_left, y + 1, x * 2 + 4, " ");
			x++;
		}
		y++;
	}
}

void	ft_print_piece(t_app *app)
{
	int 	max_y;
	int 	y;

	max_y = app->piece.y;
	y = 0;
	while (y < max_y)
	{
		mvwprintw(app->render.w_right, y + 10, 3, "%s", app->piece.tab[y]);
		y++;
	}
}

void	ft_menu(t_app *app)
{
	wclear(app->render.w_right);
	if (app->render.run)
		mvwprintw(app->render.w_right, 1, 3, "** RUNNING **");
	else
		mvwprintw(app->render.w_right, 1, 3, "** PAUSED ** ");
	mvwprintw(app->render.w_right, 3, 3, "Vitesse : %d ", app->speed);
	mvwprintw(app->render.w_right, 5, 3, "Tour du joueur : %d", app->current_player.id);
	wattron(app->render.w_right, COLOR_PAIR(app->current_player.id + 1));
	mvwprintw(app->render.w_right, 6, 3, "%s             ", app->current_player.name);
	wattroff(app->render.w_right, COLOR_PAIR(app->current_player.id + 1));
	mvwprintw(app->render.w_right, 8, 3, "Piece :");
	if (app->piece.tab)
		ft_print_piece(app);
}

int		ft_nc_update(t_app *app)
{
	if (app->mode == 2 || !app->start)
		ft_nc_print_arena(app);
	if (app->mode == 1 || !app->start)
		ft_menu(app);
	wrefresh(app->render.w_left);
	wrefresh(app->render.w_right);
	usleep(1000000 / app->speed);
	return (1);
}
