/**
 * mlx_put.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 * 
 * The content of this file, all /include/mlx_*.h files and /include/mlx.h from
 * the root of the repository come from the original mlx.h at:
 *     https://github.com/42Paris/minilibx-linux (commit 7dc5314)
 * 
 * Those files are functionally the same as the original mlx.h file, the changes
 * are mostly on the documentation and the organization. This documentation
 * explains how to use the library for the 3DS, so some things won't be explain
 * since they aren't used in this implementation.
 * 
 * Some arguments are marked as "unused", it means that changing their value
 * doesn't do anything. The returned values marked as "unused" are undefined.
 * Both are kept as is to stay as compatible as possible with project using the
 * original MinilibX implementation.
 * 
 * When using a x,y couple to define a position, the origin (0,0) is always at
 * the top-left corner of the image.
 */

/**
 * Functions to draw specific things on the window.
 * 
 * Note that mlx_put_image_to_window() is in mlx_image.h
 */

#ifndef MLX_PUT_H
# define MLX_PUT_H

# include "mlx3ds_typealiases.h"

/// @brief Draws a pixel on the window.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param win_ptr Window to affect.
/// @param x x position of the pixel to set.
/// @param y y position of the pixel to set.
/// @param color Color to use in 0x00RRGGBB format.
/// @return Unused.
int		_mlx_pixel_put(t_mlx mlx_ptr, t_win win_ptr, int x, int y, int color);

/// @brief Print text on the window.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param win_ptr Window to affect.
/// @param x x position of the text to draw.
/// @param y y position of the text to draw.
/// @param color Color to use in 0x00RRGGBB format.
/// @return Unused.
int		_mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
			char *string);

// ???
void	_mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);

#endif