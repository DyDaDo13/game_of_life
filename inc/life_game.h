#ifndef LIFE_GAME_H
# define LIFE_GAME_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

typedef struct s_image
{
	void	*image;
	char	*image_pix;
	int		bits_per;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_sprites
{
	t_image	empty;
	t_image full;
}	t_sprites;

typedef struct s_point
{
	int		x;
	int		y;
}t_point;

typedef struct s_data
{
	char			**map;
	char			**map_cpy;
	void			*mlx;
	void			*win;
	int				i_x;
	int				i_y;
	int				m_x;
	int				m_y;
	int				b_x;
	int				b_y;
	int				x;
	int				y;
	int				gen;
	int				map_height;
	int				map_width;
	t_map			*map_char;
	t_sprites		sprites;
}t_data;

char	**init_map(int fd, t_data *data);
int		ft_lstsize(t_map *lst);
t_map	*ft_lstnew(void *content);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **lst, t_map *new);
void	map_size_x_y(t_data *data);
void	free_map(t_data *data);
void	free_list(t_map **map);
void	free_all(t_data *data);
void	destroy_all_images(t_data *data);
void	draw_images(t_data *data, int i, int j);
void	init_images(t_data *data);
void	get_m_x_y(t_data *data, int x, int y);
int		algorithm(t_data *data);

#endif
