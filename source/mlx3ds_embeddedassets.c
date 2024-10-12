/**
 * mlx3ds_embeddedassets.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

#include "mlx3ds_embeddedassets.h"
#include <unistd.h>
#include <stdlib.h>

/// @brief Internal of a t_assetsocket.
typedef struct s_in_assetsocket
{
	/// @brief Asset used.
	const t_embeddedasset	*asset;
	/// @brief Index of the cursor.
	size_t					i;
}	t_in_assetsocket;

// This function is implemented in embedassets.sh
const t_embeddedasset	*mlx3ds_assets_get(const char *name);

t_assetsocket	mlx3ds_assets_open(const char *name)
{
	const t_embeddedasset	*asset;
	t_in_assetsocket		*r;

	asset = mlx3ds_assets_get(name);
	if (!asset)
		return (NULL);
	r = malloc(sizeof(t_in_assetsocket));
	if (!r)
		return (NULL);
	r->asset = asset;
	r->i = 0;
	return (r);
}

size_t	mlx3ds_assets_read(t_assetsocket asset, void *buf, size_t count)
{
	t_in_assetsocket	*asset_ = asset;

	if (count > asset_->asset->size - asset_->i)
		count = asset_->asset->size - asset_->i;

	memcpy(buf, asset_->asset->data + asset_->i, count);
	asset_->i += count;
	return (count);
}

void	mlx3ds_assets_close(t_assetsocket asset)
{
	free(asset);
}
