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

#ifndef MLX3DS_ASSETS_H
# define MLX3DS_ASSETS_H

# include <string.h>

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

// TODO add mlx3ds_assets_open()

#endif
