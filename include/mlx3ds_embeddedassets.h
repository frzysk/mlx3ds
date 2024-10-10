/**
 * mlx3ds_embeddedassets.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

// TODO docs

#ifndef MLX3DS_ASSETS_H
# define MLX3DS_ASSETS_H

# include <string.h>

// TODO docs
typedef struct s_embeddedasset
{
    const char	*name;
    size_t		size;
    const char	*data;
}	t_embeddedasset;

// TODO docs
const t_embeddedasset	*mlx3ds_assets_get(const char *name);

#endif
