/**
 * mlx3ds_typealiases.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

/**
 * Define different type aliases for the different void* values used with
 * the mlx_ functions.
 */
#ifndef MLX3DS_TYPEALIASES_H
# define MLX3DS_TYPEALIASES_H

/// @brief An mlx connection identifier returned by mlx_init().
typedef void	*t_mlx;

/// @brief Reference to a window.
typedef void	*t_win;

/// @brief Reference to an image in memory.
typedef void	*t_image;

#endif