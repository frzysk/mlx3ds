/**
 * mlx_init.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

#include "mlx_init.h"

#include "mlx_internal.h"
#include <stdlib.h>
#include "3ds.h"

static t_internal_mlx	g_internal_mlx;

t_mlx	mlx_init(void)
{
	if (g_internal_mlx.is_init_called)
		mlx3ds_internal_fatalerror("mlx_init() must be called only once");
	g_internal_mlx.is_init_called = true;
	gfxInitDefault();
	gfxSetDoubleBuffering(GFX_TOP, false);
	gfxSetDoubleBuffering(GFX_BOTTOM, false);
	consoleInit(GFX_BOTTOM, NULL);
	return (&g_internal_mlx);
}
