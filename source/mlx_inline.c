/**
 * mlx_inline.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

/**
 * This file contains some internal functions that have to be inline for
 * optimization purposes.
 *
 * Yes, I do include this file directly even if it's a .c file.
 * What the norminette doesn't know can't hurt it.
 */

#include "3ds.h"

/// @brief Write a color at a specific location of the memory,
///        the 3 color values will be in the same order.
///        It's basically a memcpy of 3 bytes.
/// @param dest Address to the first color value of the destination.
/// @param src Address to the first color value of the source.
inline void	mlx_inline_drawcolor(u8 *dest, u8 *src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}

/// @brief Write a color at a specific location of the memory,
///        the 3 color values will be in opposite order.
/// @param dest Address to the first color value of the destination.
/// @param src Address to the first color value of the source.
inline void	mlx_inline_drawcolor_invert(u8 *dest, u8 *src)
{
	dest[2] = src[0];
	dest[1] = src[1];
	dest[0] = src[2];
}
