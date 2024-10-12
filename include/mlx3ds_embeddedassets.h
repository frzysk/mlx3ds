/**
 * mlx3ds_embeddedassets.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

/**
 * This file contains functions to use the assets embedded with the program
 * with embedassets.sh.
 */

#ifndef MLX3DS_EMBEDDEDASSETS_H
# define MLX3DS_EMBEDDEDASSETS_H

# include <string.h>

/// @brief Socket to an asset. Equivalent to a file descriptor.
typedef void	*t_assetsocket;

/// @brief Represents a file embedded with the program.
typedef struct s_embeddedasset
{
	/// @brief Path of the file, relative to the assets directory (`.+(/.+)+`).
	const char	*name;
	/// @brief Size of the file content.
	size_t		size;
	/// @brief Content of the file. NUL-terminated (data[size] is '\0').
	const char	*data;
}	t_embeddedasset;

/// @brief Get an reference to the t_embeddedasset from its name.
///
/// @param name Name of the asset to get.
/// @return A reference to the asset. NULL if the asset doesn't exist.
const t_embeddedasset	*mlx3ds_assets_get(const char *name);

/// @brief Create a t_assetsocket from an asset.
///
/// @param name Name of the asset to open.
/// @return A socket to the asset. NULL if error.
t_assetsocket			mlx3ds_assets_open(const char *name);

/// @brief Reads up to 'count' bytes of the asset content and write it in 'buf'.
///
/// @param asset The asset to read.
/// @param buf The buffer to write the content to.
///            Its size must be at least 'count' bytes.
/// @param count The number of bytes to read.
/// @return The number of bytes actually read. Can be lower than 'count'.
///         0 if EOF reached.
size_t					mlx3ds_assets_read(
							t_assetsocket asset, void *buf, size_t count);

/// @brief Close the asset socket to avoid leaks.
///
/// @param asset Asset to close.
void					mlx3ds_assets_close(t_assetsocket asset);

#endif
