/**
 * mlx_image.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

#include "mlx_image.h"

#include <stdlib.h>
#include "mlx_internal.h"
#include "mlx_inline.c"

t_image	mlx_new_image(void *mlx_ptr, int width, int height)
{
	t_internal_image	*r;

	(void)mlx_ptr;
	r = NULL;
	r = malloc(sizeof(t_internal_image));
	if (!r)
		goto error;
	r->data = NULL;
	r->data = malloc(width * height * 3 * sizeof(u8));
	if (!r->data)
		goto error;
	r->width = width;
	r->height = height;
	return (r);

	error:
	free(r);
	return (NULL);
}

int	mlx_destroy_image(t_mlx mlx_ptr, t_image img_ptr)
{
	(void)mlx_ptr;
	if (img_ptr)
		free(((t_internal_image *)img_ptr)->data);
	free(img_ptr);
	return (0);
}

char	*mlx_get_data_addr(t_image img_ptr, int *bits_per_pixel,
			int *size_line, int *endian)
{
	if (bits_per_pixel)
		*bits_per_pixel = 24;
	if (size_line)
		*size_line = 3 * ((t_internal_image *)img_ptr)->width;
	if (endian)
		*endian = 1;
	return ((char *)((t_internal_image *)img_ptr)->data);
}

/// @brief Return the minimum between a and b.
/// @param a Number a.
/// @param b Number b.
/// @return The result.
static inline int	min(int a, int b)
{
	return (a < b ? a : b);
}

/// @brief Return the maximum between a and b.
/// @param a Number a.
/// @param b Number b.
/// @return The result.
static inline int	max(int a, int b)
{
	return (a > b ? a : b);
}

int	mlx_put_image_to_window(t_mlx mlx_ptr, t_win win_ptr, t_image img_ptr,
			int x, int y)
{
	// buffers
	u8	*frame_data, *img_data;
	int	// dimensions
		frame_width, frame_height, img_width, img_height,
		// interval of pixels to draw, to avoid drawing outside of the buffer
		min_x_on_screen, max_x_on_screen, min_y_on_screen, max_y_on_screen,
		// position relative to frame
		x_on_screen, y_on_screen;
	// variables that contain results of constant expressions
	int	a, b;
	u8	*c, *d, *e, *f;

	mlx3ds_internal_drawstart(mlx_ptr, win_ptr);
	frame_data = ((t_internal_win *)win_ptr)->framebuffer;
	frame_width = ((t_internal_win *)win_ptr)->framebuffer_width;
	frame_height = ((t_internal_win *)win_ptr)->framebuffer_height;
	img_data = ((t_internal_image *)img_ptr)->data;
	img_width = ((t_internal_image *)img_ptr)->width;
	img_height = ((t_internal_image *)img_ptr)->height;
	min_x_on_screen = max(x, 0);
	max_x_on_screen = min(x + img_width, frame_width);
	min_y_on_screen = max(y, 0);
	max_y_on_screen = min(y + img_height, frame_height);
	a = 3 * img_width;
	b = 3 * frame_height;
	c = img_data - 3 * x - a * y;
	d = frame_data - 3 + b;

	x_on_screen = min_x_on_screen;
	while (x_on_screen < max_x_on_screen)
	{
		e = c + 3 * x_on_screen;
		f = d + b * x_on_screen;

		y_on_screen = min_y_on_screen;
		while (y_on_screen < max_y_on_screen)
		{
			mlx_inline_drawcolor(
				f - 3 * y_on_screen,
				e + a * y_on_screen);
			y_on_screen++;
		}
		x_on_screen++;
	}
	mlx3ds_internal_drawend(mlx_ptr, win_ptr);
	return (0);
}
