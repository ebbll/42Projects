/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:01:16 by eunji             #+#    #+#             */
/*   Updated: 2021/02/22 15:39:02 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include "key_macos.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define PI 3.1415926535897
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct		s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
}					t_ray;

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
}					t_sprite;

typedef struct		s_ray_sprite
{
	double			relative_dist_x;
	double			relative_dist_y;
	double			inverse_determinant;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				sprite_screen_x;
}					t_ray_sprite;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_ray			ray;
	int				screen_width;
	int				screen_height;
	int				map_width;
	int				map_height;
	t_player		player;
	int				fd;
	char			**map;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*west_texture_path;
	char			*east_texture_path;
	char			*sprite_texture_path;
	int				direction;
	int				floor_color;
	int				ceiling_color;
	int				sprite_num;
	int				**texture;
	int				**buf;
	t_sprite		*sprite;
	t_ray_sprite	ray_sprite;
	double			*z_buf;
	char			*line;
}					t_info;

typedef struct		s_cub_count
{
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				f;
	int				c;
}					t_cub_count;

// main.c
void				check_arguments(int argc, char *option, int *save_option);
void				open_cub(char *file, t_info *info);
void				start_raycasting(t_info *info);
void				get_bmp(t_info *info);
int					main(int argc, char **argv);

// get_cub_info.c
void				get_cub_info(t_info *info, t_cub_count *cub_count);
int					cub_info_read(t_info *info, char *line,
					t_cub_count *cub_count);
void				get_screen_size(t_info *info, int count, char *line);
void				get_texture(t_info *info, int count, char *path,
					char *comp);
void				get_color(t_info *info, int count, char *line, int comp);

// get_cub_info_util.c
int					digit_check(char **size);
int					check_digit_color(char **ptr);
char				*get_delete_space(char *rgb);
int					search_format(char *file, char *format);

// check_cub_info.c
void				check_cub_info(t_info *info, t_cub_count *cub_count);

// get_map_info.c
void				get_map_info(t_info *info, char *line);
void				map_init(t_info *info, t_list *lst);
void				map_fill(t_info *info, t_list *lst);
void				set_sprite(t_info *info);

// get_map_info_util.c
void				set_player_location(t_info *info, int i, int j,
					int *player_num);
void				set_player_direction(t_player *player, double radian);
int					get_max_line_size(t_list *lst);
int					is_map_part(int c);
int					is_direction_part(int c);

// check_map_info.c
void				check_map_info(t_info *info);

// check_map_info_util.c
void				check_map_top(t_info *info);
void				check_map_left(t_info *info, int i, int j);
void				check_map_right(t_info *info, int i, int j);
void				check_map_middle(t_info *info, int i, int j);
void				check_map_bottom(t_info *info, int i);

// bmp.c
void				bmp_save(t_info *info);
void				bmp_header_set(t_info *info, int fd, int pad);
void				bmp_data_set(t_info *info, int fd, int pad);
void				input_int_to_char(unsigned char *array, int value);

// main_loop.c
void				calc_raycasting(t_info *info);
void				calc_sprite(t_info *info);
int					main_loop(t_info *info);

// calc_raycasting.c
void				set_ray_item(t_info *info, int x);
void				calc_step_direction(t_info *info);
void				perform_dda(t_info *info);
void				calc_wall(t_info *info);
void				calc_texture(t_info *info, int x);

// calc_sprite.c
void				sort_sprite(t_info *info);
void				translate_sprite(t_info *info, int i);
void				calc_sprite_height_width(t_info *info);
void				get_sprite(t_info *info, int sprite);

// draw.c
void				draw_floor_ceiling(t_info *info);
void				draw(t_info *info);

// init.c
void				init_info(t_info *info);
void				init_cub_count(t_cub_count *cub_count);
void				init_buffer(t_info *info);
void				init_texture(t_info *info);

// load_texture.c
void				load_image(t_info *info, int *texture, char *path,
					t_img *img);
void				load_texture(t_info *info);

// key_press.c
void				move_player_f_b(int key, t_info *info);
void				move_player_l_r(int key, t_info *info);
void				rotate_left_player(t_info *info);
void				rotate_right_player(t_info *info);
int					key_press(int key, t_info *info);

// exit_free.c
void				ft_free(void *s);
int					ft_exit(int ret);
void				str_exit(char *str);
void				free_double_ptr(char **str);
void				all_free(t_info *info);

// ft_putstr.c
void				ft_putstr(char *str);

#endif
