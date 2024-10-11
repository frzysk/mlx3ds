/**
 * mlx_window.h
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
 */

/**
 * This file contains functions to manage windows.
 */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "mlx3ds_typealiases.h"

/// @brief Create a window. It isn't really a window but a way to draw on the
///        top screen of the 3DS. Only one window can be opened at a time.
///
/// @param mlx_ptr The mlx connection identifier returned by mlx_init().
/// @param size_x Width of the window.
///               Maximum 400 to be able to adapt to the top screen of the 3DS.
/// @param size_y Height of the window.
///               Maximum 240 to be able to adapt to the top screen of the 3DS.
/// @param title  The title of the window. Unused in the 3DS.
/// @return A reference to the window. NULL if failed.
t_win	mlx_new_window(t_mlx mlx_ptr, int size_x, int size_y,
			const char *title);

/// @brief Clear the window in black.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param win_ptr Window to affect.
/// @return Unused.
int		mlx_clear_window(t_mlx mlx_ptr, t_win win_ptr);

/// @brief Destroy a window.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param win_ptr Window to destroy.
/// @return Unused.
int		mlx_destroy_window(t_mlx mlx_ptr, t_win win_ptr);

#endif
