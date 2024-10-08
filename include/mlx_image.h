/**
 * mlx_image.h
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
 * Functions to import, create, modify and display images.
 */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

# include "mlx3ds_typealiases.h"

/// @brief Create an image in memory.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param width Desired width of the image.
/// @param height Desired height of the image.
/// @return A reference to the image. NULL if failed.
t_image	mlx_new_image(void *mlx_ptr, int width, int height);

/// @brief Get an address containing all the pixel values of the image. The user
///        can then modify the image using this pointer directly.
///
/// @param img_ptr Image to use.
/// @param bits_per_pixel Will be filled with the number of bits used for each
///                       pixel. Can be NULL, result will always be 24.
/// @param size_line Will be filled with the number of bytes used to store
///                  a line of the image, aka 3 * width. Can be NULL.
/// @param endian Will be filled with the endianness of all color values.
///               1 for big endian, 0 for little endian. Can be NULL, result
///               will always be 1.
/// @return Address to the data of the image.
///         Use `data[y * size_line + x * 3]` to get the first color value (red)
///         of a specific pixel.
char	*mlx_get_data_addr(t_image img_ptr, int *bits_per_pixel,
			int *size_line, int *endian);

/// @brief Draw an image on the window.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param win_ptr Window to affect.
/// @param img_ptr Image to use.
/// @param x x position of the image to draw.
/// @param y y position of the image to draw.
/// @return Unused.
int		mlx_put_image_to_window(t_mlx mlx_ptr, t_win win_ptr, t_image img_ptr,
			int x, int y);

// ??? TODO docs
// width & height CAN be null (check please :3)
t_image	mlx_xpm_to_image(t_mlx mlx_ptr, const char **xpm_data,
			int *width, int *height);

// ???
// width & height CAN be null (check please :3)
t_image	_mlx_xpm_file_to_image(t_mlx mlx_ptr, char *filename,
			int *width, int *height);

/// @brief Destroy an image.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param img_ptr Image to destroy.
/// @return Unused.
int		mlx_destroy_image(t_mlx mlx_ptr, t_image img_ptr);

#endif
