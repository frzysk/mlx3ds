/**
 * mlx_hook.h
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
 * Functions to manage window events.
 */

#ifndef MLX_HOOK_H
# define MLX_HOOK_H

# include "mlx3ds_typealiases.h"

/// @brief Doesn't do anything, the 3DS doesn't have a mouse.
///
/// @param win_ptr Unused.
/// @param funct_ptr Unused
/// @param param Unused.
/// @return Unused.
int		_mlx_mouse_hook(t_win win_ptr, int (*funct_ptr)(), void *param);

/// @brief Assign a function to a key event. When a key is pressed, the function
///        will be called.
///
/// @param win_ptr Window to affect.
/// @param funct_ptr Function to call when the event occurs. `keycode` is the
///                  key pressed (note that they are obviously different than
///                  the keyboard ones, use the KEY_* constants from hid.h)).
///                  (TODO what was the name of the key constants use with mlx?)
///                  `param` is set as the address given to mlx_key_hook().
///                  The return value is unused.
/// @param param Address to pass to the function every time it is called. 
/// @return Unused.
int		_mlx_key_hook(t_win win_ptr,
			int (*funct_ptr)(int keycode, void *param), void *param);

/// @brief Assign a function which will be called when the window should be
///        redrawn.
///        TODO is mlx_expose_hook() needed for the 3DS?
///
/// @param win_ptr Window to affect.
/// @param funct_ptr Function to call when the event occurs. `param` is set as
///                  the address given to mlx_key_hook(). The return value is
///                  unused.
/// @param param Address to pass to the function every time it is called.
/// @return Unused.
int		_mlx_expose_hook(t_win win_ptr,
			int (*funct_ptr)(void *param), void *param);

/// @brief Assign a function which will be called in loop non-stop.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @param funct_ptr Function to call when the event occurs. `param` is set as
///                  the address given to mlx_key_hook(). The return value is
///                  unused.
/// @param param Address to pass to the function every time it is called.
/// @return Unused.
int		_mlx_loop_hook(t_mlx mlx_ptr,
			int (*funct_ptr)(void *param), void *param);

/// @brief Loop indefinitely and wait for events to occurs to call the
///        corresponding functions.
///
/// @param mlx_ptr mlx connection identifier returned by mlx_init().
/// @return This function never returns. 
int		_mlx_loop(void *mlx_ptr);

// ???
int		_mlx_loop_end(void *mlx_ptr);

// god
int		_mlx_hook(t_mlx win_ptr, int x_event, int x_mask,
			int (*funct)(), void *param);

#endif
