/**
 * mlx_init.h
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
 * Function which initialize everything for the mlx3ds.
 */

#ifndef MLX_INIT_H
# define MLX_INIT_H

# include "mlx3ds_typealiases.h"

/// @brief Call this function before anything else.
///
/// @return The mlx connection identifier to use for all other functions.
///         NULL if failed.
t_mlx	mlx_init(void); // TODO should call this before REALLY anything else?

// TODO a mlx_end() necessary?

#endif
