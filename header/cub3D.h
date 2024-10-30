/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:22:59 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/30 15:20:04 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../src/0_Libft_extended/include/libft.h"
# include <unistd.h>		/* For open, close, read, write */
# include <sys/time.h>		/* For gettimeofday */
# include <fcntl.h>			/* For file access (O_RDONLY, O_WRONLY, etc.) */
# include <stdio.h>			/* For printf, perror */
# include <string.h>		/* For strerror */
# include <stdlib.h>		/* For exit, malloc, free */
# include <math.h>			/* For all math functions like sqrt, sin, pow */
# include "../MLX42/include/MLX42/MLX42.h"	// For MLX42 functions */
# ifdef MUSIC
#  include "../miniaudio/miniaudio.h"	/* For music */
# else
#  define MUSIC 0
# endif
# ifndef BONUS
#  define BONUS 0
# endif
# define PI				3.14159265
# define WIDTH			800
# define HEIGHT			600
# define STEP			0.03
# define TURN			0.01
# define CHAR_F_W		"01"
# define CHAR_MAP		"01NSEWX "
# define CHAR_MAP_B		"01NSEWXDPC "
# define CHAR_FILL		"NSEW"
# define IS_FILLED		"1X"
# define PRE_FLOOR		45 /* '-' */
# define CHAR_FLOOR		48 /* '0' */
# define CHAR_WALL		49 /* '1' */
# define IS_CHECKED		88 /* 'X' */
# define IS_WEST		87 /* 'W' */
# define IS_SOUTH		83 /* 'S' */
# define IS_EAST		69 /* 'E' */
# define IS_NORTH		78 /* 'N' */
# define IS_PUMPKIN		80 /* 'P' */
# define IS_CANDY		67 /* 'C' */
# define IS_DOOR		68 /* 'D' */
# define IS_OPEN_DOOR	79 /* 'O' */
# define IS_SPACE		32
# define WALL_DST		0.5
# define MAX_WIDTH		800
# define MAX_HEIGHT		600
# define MAX_DOORS		10
# define MAX_ENEMY		10

/* Red color for player on minimap */
# define MINIMAP_PLAYER_COLOR		0x000000FF
/* White color for walls on minimap */
# define MINIMAP_WALL_COLOR			0x80888888
/* Black color for floor on minimap */
# define MINIMAP_FLOOR_COLOR		0x80000000
/* Under color on minimap (Transparent black) */
# define MINIMAP_UNDER_FLOOR		0x00000000
/* Bright red color */
# define MINIMAP_DIRECTION_COLOR	0xFF0000FF
/* HALF red color */
# define MINIMAP_ENEMY_COLOR		0xFF000088
/* HALF red color */
# define MINIMAP_CANDY_COLOR		0xFF008800
/* Almost Black color for door on minimap */
# define MINIMAP_DOOR_COLOR			0xFF222222
/* Almost Black color for door on minimap */
# define MINIMAP_OPEN_DOOR_COLOR	0x95000000	
# define MAX_LIFE					25
/* https://pixabay.com/music/search/halloween/ */

# if BONUS == 0
#  define WAV_MUSIC "./music/Fight.wav"
# else
#  define WAV_MUSIC "./music/Halloween.wav"
# endif
# define MINI_IMG_SIZE				8
# define MINI_CHARACTER_SIZE		2

/**
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame
 * 						and the current frame.
 */
/* 
typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;
 */
/**
 * Player struct for position and direction data.
 * 
 * @param[in] p_x x-position of the player inside the map.
 * @param[in] p_y y-position of the player inside the map.
 * @param[in] dir_angle View angle in radiand (not degree)
 * @param[in] dir_x resulting x-view vector
 * @param[in] dir_y resulting y-view vector
 * @param[in] action 1 if player moved, else 0
 * @param[in] side horizontal movement (+1 right, -1 left)
 * @param[in] front vertical movement (+1 forward, -1 backward)
 * */
typedef struct s_player
{
	double		x;
	double		y;
	double		dir_angle;
	double		dir_x;
	double		dir_y;
	double		turn;
	char		side;
	char		front;
	uint32_t	life;
}	t_player;

/* player position move or not */
typedef struct s_walls
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor_row;
	uint32_t	floor_color;
	char		*ceiling_row;
	uint32_t	ceiling_color;
}	t_walls;

/**
 * Ray struct for data in raytracing.
 * 
 * @param[in] slice Number of the width-slice that will be calculated.
 * @param[in] x x-vector component of the ray direction.
 * @param[in] y y-vector component of the ray direction.
 * @param[in] delta_x Way needed to cross one x.
 * @param[in] delta_y Way needed to cross one y.
 * @param[in] dist_x horizontal way to last crossed x 
 * @param[in] dist_y vertical way to last crossed y 
 * @param[in] hit_x x squares to hit a wall.
 * @param[in] hit_y y squares to hit a wall.
 * @param[in] x_dir 1 on positive x-direction of ray, -1 else
 * @param[in] y_dir 1 on positive y-direction of ray, -1 else
 * @param[in] dist distance to the hit wall
 * @param[in] hit_portion x-portion of the hit texture [between 0 and 1]
 * @param[in] texture_x Resulting x-coordinate of the hit texture
 * @param[in] hit_texture pointer to the texture that was hit
 * @param[in] slice_height resulting view height of hit texture-slice
 */
typedef struct s_ray
{
	uint32_t		slice;
	double			shift_factor;
	double			x;
	double			y;
	double			delta_x;
	double			delta_y;
	double			dist_x;
	double			dist_y;
	int				hit_x;
	int				hit_y;
	int				x_dir;
	int				y_dir;
	double			wall_dist[WIDTH];
	double			hit_portion;
	uint32_t		texture_x;
	mlx_texture_t	*hit_texture;
	uint32_t		slice_height;
}	t_ray;

/* textures which are used */
typedef struct s_texture
{
	mlx_texture_t	*nord;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_texture_t	*south;
	mlx_texture_t	*candy[6];
	mlx_texture_t	*pumpkin[6];
	mlx_texture_t	*life[6];
	mlx_texture_t	*wall[6];
	mlx_texture_t	*closed_door;
}	t_texture;

typedef struct s_enemy
{
	char			visible;
	double			x;
	double			y;
	double			mov_x;
	double			mov_y;
	double			dist;
	double			angle;
	int32_t			slice;
	double			last_hit;
	uint32_t		damage;
	mlx_texture_t	**appearance;
}	t_enemy;

// Pointers to textures which are animated
typedef struct s_anim
{
	mlx_texture_t	*pumpkin;
	mlx_texture_t	*candy;
	mlx_texture_t	*wall;
}	t_anim;

/* bonus part */
typedef struct s_door
{
	uint32_t	x;
	uint32_t	y;
}	t_door;

typedef struct s_anim_help
{
	int32_t			x_wr;
	int32_t			y_wr;
	int32_t			x_max;
	int32_t			y_max;
	uint32_t		color;
	int32_t			x_0;
	uint32_t		y_0;
	uint32_t		tex_x;
	uint32_t		tex_y;
	double			distance;
	mlx_texture_t	*appearance;
}	t_anim_help;

typedef struct s_player_dir
{
	int	px;
	int	py;
	int	ex;
	int	ey;
}	t_player_dir;

typedef struct s_player_dir_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_player_dir_line;

/**
 * cub3D data struct.
 * 
 * @param[in] mlx pointer to the used mlx-instance
 * @param[in] fov_factor Size of th view field
 * @param[in] map map[y][x] which was read in at start
 */
typedef struct s_data
{
	mlx_t				*mlx;
	double				fov_factor;
	double				shift_dist;
	uint32_t			map_width;
	uint32_t			map_height;
	char				**map;
	int					fd;
	t_player			player;
	t_walls				walls;
	t_ray				ray;
	mlx_image_t			*image;
	t_texture			textures;
	mlx_image_t			*mini_img;
	double				mini_img_size;
	double				mini_map_player;
	int					enemy_size;
	t_anim				anim;
	t_anim_help			help;
	t_enemy				enemy[MAX_ENEMY];
	double				heart_scaling;
	uint32_t			offset;
	uint32_t			scaled_heart_width;
	uint32_t			scaled_heart_height;
	int					door_count;
	int					enemy_count;
	t_door				doors[MAX_DOORS];
	mlx_image_t			*mini_life;
	t_player_dir		player_dir;
	t_player_dir_line	player_dir_line;
}	t_data;

/* Functions: */
/* 1_Parse_init: */
int			init_game(t_data *data, char **av);
int			init_data(t_data *data);
void		init_image(t_data *data);
void		init_map(t_data *data);
void		init_zone(t_data *data);
void		init_door(t_data *data, uint32_t x, uint32_t y);
/* 1_Parse_init bonus: */

/* 2_Ray_casting: */
void		raycasting(t_data *data);

/* 3_Hooks: */
void		close_window(void *param);
void		mouse_callback(double xpos, double ypos, void *param);
void		key_press(mlx_key_data_t keydata, void *param);
void		get_new_frame(void *param);

/* 4_Graphics: */
int			load_textures(t_data *data);
int			load_bonus_textures(t_data *data);
void		draw_current_slice(t_data *data);

/* 5_Colors: */
uint32_t	mix_pixel_color(int32_t r, int32_t g, int32_t b, int32_t a);
uint32_t	get_pixel_color(mlx_texture_t *texture, uint32_t x, uint32_t y);
void		color_pixel(mlx_image_t *image, uint32_t x, \
				uint32_t y, uint32_t color);

/* 6_others: */
void		clean_up(t_data *data);
void		clean_up_bonus(t_data *data);
void		ft_error_general(t_data *data, char *msg);
void		ft_error_and_free_map(char *msg, t_data *data);
void		check_argument(int ac, char **av);
void		ft_free_map(t_data *data, char **target);
void		ft_free_walls(t_data *data);
void		free_tex_slice(mlx_texture_t **tex_slice, size_t size);
void		check_forbidden_chars(t_data *data, char *line, int flag);
char		*check_emtpy_file(t_data *data, char *line);

/* 7_bonus */
void		init_minimap(t_data *data);
void		draw_minimap(t_data *data);
void		draw_player_direction(t_data *data);
void		init_pumpkin(t_data *data, uint32_t x, uint32_t y);
void		init_candy(t_data *data, uint32_t x, uint32_t y);
void		render(void *param);
void		put_door_on_map(t_data *data);
void		knock_door(t_data *data);
void		init_life(t_data *data);
void		damage_life(t_data *data, uint32_t damage);
void		show_life_hearts(t_data *data);

/* 8_Animation */
void		animate(void *param);
void		enemy_to_image(t_data *d, t_enemy *enemy);

#endif
