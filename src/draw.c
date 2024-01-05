/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:22:35 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/05 10:50:40 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life_game.h"

void	draw_images(char **map, t_data *data, int i, int j)
{
	if (map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.full.image, data->x, data->y);
	if (map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.empty.image, data->x, data->y);
}

void	draw_map(char **map, t_data *data)
{
	int		i;
	int		j;
	data->x = 0;
	data->y = 0;

	i = 0;
	while (map[i])
	{
		j = 0;
		data->x = 0;
		while (map[i][j])
		{
			draw_images(map, data, i, j);
			j++;
			data->x += 16;
		}
		data->y += 16;
		i++;
	}
}