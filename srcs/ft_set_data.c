#include "filler.h"

void	ft_set_id_player(t_game *g, char *str)
{
	int		i;

	i = 0;
	if (str[0] && str[0] == '$' && ft_strstr(str, "/filler]"))
	{
		if (ft_strlen(str) >= 12)
			str += 10;
		g->id_player = str[0];
	}
}