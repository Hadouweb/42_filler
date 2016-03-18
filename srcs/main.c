#include "filler.h"

int		main(void)
{
	char	*line;
	t_app	app;

	ft_bzero(&app, sizeof(t_app));
	app.play = 1;
	while (get_next_line(0, &line))
	{
		if (!app.id_player)
			ft_set_id_player(&app, line);
		else if (app.play)
			ft_set_data(&app, line);
		if (!app.play)
			ft_putstr("0 0\n");
		ft_strdel(&line);
	}
	return (0);
}