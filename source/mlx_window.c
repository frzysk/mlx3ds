/**
 * mlx_window.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

#include "mlx_window.h"

#include "3ds.h"
#include "mlx_internal.h"
#include <stdlib.h>

t_win	mlx_new_window(t_mlx mlx_ptr, int size_x, int size_y, const char *title)
{
	t_internal_win	*r;

	(void)title;
	if (size_x > GSP_SCREEN_HEIGHT_TOP || size_y > GSP_SCREEN_WIDTH)
		mlx3ds_internal_fatalerror("Window too big for the screen");
	r = malloc(sizeof(t_internal_win));
	if (!r)
		return (NULL);
	r->mlx = mlx_ptr;
	r->width = size_x;
	r->height = size_y;
	r->framebuffer = NULL;
	return (r);
}

int	mlx_clear_window(t_mlx mlx_ptr, t_win win_ptr)
{
	u8	*frame_i;
	u8	*frame;

	mlx3ds_internal_drawstart(mlx_ptr, win_ptr);
	frame = ((t_internal_win *)win_ptr)->framebuffer;
	frame_i = frame
		+ 3 * ((t_internal_win *)win_ptr)->framebuffer_width
		* ((t_internal_win *)win_ptr)->framebuffer_height;
	while (--frame_i >= frame)
		*frame_i = 0x00;
	mlx3ds_internal_drawend(mlx_ptr, win_ptr);
	return (0);
}

int	mlx_destroy_window(t_mlx mlx_ptr, t_win win_ptr)
{
	((t_internal_mlx *)mlx_ptr)->top_window = NULL;
	free(win_ptr);
	return (0);
}
