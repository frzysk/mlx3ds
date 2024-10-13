/**
 * mlx_hook.c
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

#include "mlx_hook.h"

#include "mlx_internal.h"

int	mlx_mouse_hook(t_win win_ptr, int (*funct_ptr)(), void *param)
{
	(void)win_ptr;
	(void)funct_ptr;
	(void)param;

	// ╮(︶▽︶)╭
	return (0);
}

int		mlx_key_hook(t_win win_ptr,
			int (*funct_ptr)(int keycode, void *param), void *param)
{
	((t_internal_win *)win_ptr)->hooks[KeyRelease].hook = funct_ptr;
	((t_internal_win *)win_ptr)->hooks[KeyRelease].param = param;
	return (0);
}

int		mlx_expose_hook(t_win win_ptr,
			int (*funct_ptr)(void *param), void *param)
{
	// TODO use expose hook?
	((t_internal_win *)win_ptr)->hooks[Expose].hook = funct_ptr;
	((t_internal_win *)win_ptr)->hooks[Expose].param = param;
	return (0);
}
#include <stdlib.h> // remove debug TODO
#include <stdio.h>
#include "utilsconsole.h"

int		mlx_loop_hook(t_mlx mlx_ptr,
			int (*funct_ptr)(void *param), void *param)
{
	((t_internal_mlx *)mlx_ptr)->hook_loop_function = funct_ptr;
	((t_internal_mlx *)mlx_ptr)->hook_loop_param = param;
	return (0);
}

int		mlx_hook(t_win win_ptr, int x_event, int x_mask,
			int (*funct)(), void *param)
{
	(void)x_mask;
	((t_internal_win *)win_ptr)->hooks[x_event].hook = funct;
	((t_internal_win *)win_ptr)->hooks[x_event].param = param;
	return (0);
}

typedef struct
{
	u32	held;
	u32	down;
	u32	up;
}	t_keys_status;

static t_keys_status	keys_events(void)
{
	static u32		last_held;
	static u32		real_last_held;
	t_keys_status	r;
	u32 real_held = hidKeysHeld();

	hidScanInput();
	r.held = real_held | real_last_held;
	r.up = last_held & ~r.held;
	r.down = ~last_held & r.held;
	last_held = r.held;
	real_last_held = real_held;
	return (r);
}

static void	call_events(t_internal_win *win, t_keys_status keys)
{
	if (win->hooks[KeyRelease].hook && keys.up)
		for (int i = 0; i < 32; i++)
			if ((keys.up >> i) & 1)
				win->hooks[KeyRelease].hook(
						1 << i, win->hooks[KeyRelease].param);
	if (win->hooks[KeyPress].hook && keys.down)
		for (int i = 0; i < 32; i++)
			if ((keys.down >> i) & 1)
				win->hooks[KeyPress].hook(
						1 << i, win->hooks[KeyPress].param);
}

static void	call_start_events(t_internal_win *win)
{
	if (win->hooks[CreateNotify].hook)
		win->hooks[CreateNotify].hook(win->hooks[CreateNotify].param);
}

static void	call_end_events(t_internal_win *win)
{
	if (win->hooks[DestroyNotify].hook)
		win->hooks[DestroyNotify].hook(win->hooks[DestroyNotify].param);
}

int		mlx_loop(t_mlx mlx_ptr)
{
	t_internal_mlx *mlx = mlx_ptr;

	mlx->loop = true;
	if (mlx->top_window)
		call_start_events(mlx->top_window);
	while (aptMainLoop() && mlx->loop)
	{
		t_keys_status	keys = keys_events();
		if (mlx->top_window)
			call_events(mlx->top_window, keys);
		if (mlx->hook_loop_function)
			mlx->hook_loop_function(mlx->hook_loop_param);
		gfxFlushBuffers(); // aptMainLoop() doesn't work without that
	}
	if (!aptMainLoop())
		if (mlx->top_window)
			call_end_events(mlx->top_window);
	mlx->loop = false;
	return (0);
}

int		mlx_loop_end(t_mlx mlx_ptr)
{
	((t_internal_mlx *)mlx_ptr)->loop = false;
	return (0);
}
