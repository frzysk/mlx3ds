/*
** mlx_int.h for mlx in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:45:48 2000 Charlie Root
** Last update Wed May 25 16:44:16 2011 Olivier Crouzet
*/

/*
** Internal settings for MiniLibX
*/

/**
 * Modified by Zy to work with the MinilibX For 3DS project
 * (at https://github.com/frzysk/mlx3ds).
 */

// TODO: from mlx xpm: clean

#ifndef MLX_INT_H

# define MLX_INT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>


# define MLX_TYPE_SHM_PIXMAP 3
# define MLX_TYPE_SHM 2
# define MLX_TYPE_XIMAGE 1

# define MLX_MAX_EVENT LASTEvent


# define ENV_DISPLAY "DISPLAY"
# define LOCALHOST "localhost"
# define ERR_NO_TRUECOLOR "MinilibX Error : No TrueColor Visual available.\n"
# define WARN_SHM_ATTACH "MinilibX Warning : X server can't attach shared memory.\n"

// [USED] [FULL]
typedef	struct	s_xpm_col
{
	int		name;
	int		col;
}				t_xpm_col;


struct	s_col_name
{
	char	*name;
	int		color;
};

typedef struct	s_event_list
{
	int		mask;
	int		(*hook)();
	void	*param;
}				t_event_list;

int				mlx_int_do_nothing();
int				mlx_get_color_value();
int				mlx_int_get_good_color();
int				mlx_int_find_in_pcm();
int				mlx_int_anti_resize_win();
int				mlx_int_wait_first_expose();
int				mlx_int_rgb_conversion();
int				mlx_int_deal_shm();
void			*mlx_int_new_xshm_image();
// [USED] [FULL]...
char			**mlx_int_str_to_wordtab();
void			*mlx_new_image();
int				shm_att_pb();
// [USED] [FULL]...
int				mlx_int_str_str_cote(char *str,char *find,int len);
// [USED] [FULL]...
int				mlx_int_str_str(char *str,char *find,int len);


#endif
