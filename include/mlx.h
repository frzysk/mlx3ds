/**
 * mlx.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 * 
 * The content of this file and all /include/mlx_*.h files from the root of the
 * repository come from the original mlx.h at:
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
 * This header file includes all the mlx_* functions.
 * These are all the functions that already exist in the original MinilibX.
 * 
 * Functions that start with '_' aren't yet implemented.
 * TODO Implement _*() functions.
 */

#ifndef MLX_H
# define MLX_H

# include "mlx3ds_typealiases.h"
# include "mlx_init.h"
# include "mlx_window.h"
# include "mlx_put.h"
# include "mlx_image.h"
# include "mlx_hook.h"
# include "mlx_unknown.h"

#endif
