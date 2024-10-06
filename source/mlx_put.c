/**
 * mlx_put.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

#include "mlx_put.h"

#include "mlx_internal.h"
#include "mlx_inline.c"

int	mlx_pixel_put(t_mlx mlx_ptr, t_win win_ptr, int x, int y, int color)
{
	u8	*frame;

	mlx3ds_internal_drawstart(mlx_ptr, win_ptr);

	if (x < 0 || x >= ((t_internal_win *)win_ptr)->framebuffer_width
		|| y < 0 || y >= ((t_internal_win *)win_ptr)->framebuffer_height)
		return (0);
	frame = ((t_internal_win *)win_ptr)->framebuffer;
	mlx_inline_drawcolor(
		frame + 3 * (
			(x + 1) * ((t_internal_win *)win_ptr)->framebuffer_height - y - 1
			),
		(u8 *)&color);

	mlx3ds_internal_drawend(mlx_ptr, win_ptr);

	return (0);
}
