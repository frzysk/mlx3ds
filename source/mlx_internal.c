/**
 * mlx_internal.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

// TODO mlx_internal.c: embed uc_pause()

#include "utilsconsole.h"
#include "mlx_internal.h"
#include "3ds.h"
#include <stdio.h>

void	mlx3ds_internal_fatalerror(const char *msg)
{
	consoleInit(GFX_BOTTOM, NULL);
	printf("\e[0;31m[mlx3ds] Fatal error:\e[0m\n%s\n", msg);
	uc_pause();
}

void	mlx3ds_internal_drawstart(
			t_internal_mlx *mlx_ptr, t_internal_win *win_ptr)
{
	win_ptr->framebuffer = gfxGetFramebuffer(GFX_TOP, GFX_LEFT,
			&win_ptr->framebuffer_height, &win_ptr->framebuffer_width);
	gspWaitForVBlank();
}

void	mlx3ds_internal_drawend(
			t_internal_mlx *mlx_ptr, t_internal_win *win_ptr)
{
	gfxFlushBuffers();
	gfxSwapBuffers();
}
