#include "wolf.h"

void			init_tiles(t_data *data)
{
	int i;

	i = 0;
	while (i < data->map.w * data->map.h)
	{
		data->map.tiles[i / data->map.w][i % data->map.w].z = 0;
		data->map.tiles[i / data->map.w][i % data->map.w].texture = WOOD;
		data->map.tiles[i / data->map.w][i % data->map.w].entity = NONE;
		i++;
	}
}
