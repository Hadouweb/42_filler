#include "filler.h"

int		main(void)
{
	char	*line;
	t_game	g;
	t_line 	*lst_b;
	t_line 	*lst_p;

	ft_bzero(&g, sizeof(t_game));
	lst_b = NULL;
	lst_p = NULL;
	g.loop = 1;
	while (get_next_line(0, &line))
	{
		//fprintf(stderr, "_________________%d\n", g.loop);
		if (!g.id_player)
			ft_set_id_player(&g, line);
		else if (g.loop)
			ft_loop(&g, line, &lst_b, &lst_p);
		if (!g.loop)
			ft_putstr("0 0\n");
		ft_strdel(&line);
	}
	return (0);
}