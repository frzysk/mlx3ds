/**
 * mlx_internal.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

/**
 * This file contains internal utils.
 */

#ifndef MLX_INTERNAL_H
# define MLX_INTERNAL_H

# include <stdbool.h>
# include "3ds.h"
# include "mlx_events.h"

/// @brief Write an error message and exit the program.
///
/// @param msg Message to write. Must use less than 38 colons.
void	mlx3ds_internal_fatalerror(const char *msg);

struct	s_internal_win;

/// @brief Content of the mlx connection identifier.
typedef struct s_internal_mlx
{
	/// @brief is true after mlx_init() was called, is false before.
	bool					is_init_called;
	/// @brief Window displayed on the top screen.
	struct s_internal_win	*top_window;
	/// @brief Function called in loop by mlx_loop().
	int						(*hook_loop_function)(void *param);
	/// @brief Parameter given to hook_loop_function.
	void					*hook_loop_param;
	/// @brief Set to false to break the loop of mlx_loop().
	bool					loop;
}	t_internal_mlx;

// TODO docs
typedef struct s_internal_win_hook
{
	int		(*hook)();
	void	*param;
}	t_internal_win_hook;

/// @brief Represents a window.
typedef struct s_internal_win
{
	/// @brief mlx connection identifier
	t_internal_mlx		*mlx;
	/// @brief Width of the window
	int					width;
	/// @brief Height of the window
	int					height;
	/// @brief Buffer of the screen.
	u8					*framebuffer;
	/// @brief Width of the screen (on x).
	u16					framebuffer_width;
	/// @brief Height of the screen (on y).
	u16					framebuffer_height;
	// TODO docs
	t_internal_win_hook	hooks[LASTEvent];
}	t_internal_win;

/// @brief Represents an image in memory.
typedef struct s_internal_image
{
	/// @brief Width of the image
	int				width;
	/// @brief Height of the image
	int				height;
	/// @brief Address of the image data. Returned by mlx_get_data_addr().
	u8				*data;
}	t_internal_image;

/// @brief To call before drawing. Init winptr->framebuffer.
///
/// @param mlx_ptr mlx connection identifier
/// @param win_ptr Reference to the window to draw on.
void	mlx3ds_internal_drawstart(
			t_internal_mlx *mlx_ptr, t_internal_win *win_ptr);

/// @brief To call when finish drawing. Flush and swap buffers.
///
/// @param mlx_ptr mlx connection identifier
/// @param win_ptr Reference to the window to draw on.
void	mlx3ds_internal_drawend(
			t_internal_mlx *mlx_ptr, t_internal_win *win_ptr);

#endif
