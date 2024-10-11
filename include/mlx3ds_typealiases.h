/**
 * mlx3ds_typealiases.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

/**
 * This file contains different typedefs for void*, to differenciate between
 * the different void* used by the MLX functions.
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
