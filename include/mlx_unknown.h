/**
 * mlx_unknown.h
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
 *     Here lies
 * all the functions
 *       that i
 *    have no idea
 *   what they does
 *      so that
 *      i can't
 *        yet
 *      organize
 *        but
 *      i shall
 *      someday
 *       allow
 *       myself
 *      TODO it      (organize the unknown functions)
 */

#ifndef MLX_UNKNOWN_H
# define MLX_UNKNOWN_H

# include "mlx3ds_typealiases.h"

// ???
int		_mlx_get_color_value(void *mlx_ptr, int color);
// ???
int		_mlx_destroy_display(t_mlx mlx_ptr);
// ???
int		_mlx_do_sync(t_mlx mlx_ptr);
// ???
int		_mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
// ???
int		_mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
// ???
int		_mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
// ???
int		_mlx_mouse_show(void *mlx_ptr, void *win_ptr);
// ???
int		_mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
// ???
int		_mlx_do_key_autorepeatoff(t_mlx mlx_ptr);
// ???
int		_mlx_do_key_autorepeaton(t_mlx mlx_ptr);

#endif