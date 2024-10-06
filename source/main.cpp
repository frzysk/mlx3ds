extern "C" {
#include "mlx.h"
#include "3ds.h"
}
#include <iostream>
#include <string.h>
#include "utilsconsole.hpp"

using namespace std;

static void draw_rainbow_image(t_mlx mlx, t_win win, int x, int y)
{
	cout << "Draw rainbow image at (" << x << "," << y << ")..." << endl;
	uc_pause();
	{
		static const u32 red = 0xFF0000;
		static const u32 green = 0x00FF00;
		static const u32 blue = 0x0000FF;
		t_image img = mlx_new_image(mlx, 30, 30);
		char *img_data = mlx_get_data_addr(img, NULL, NULL, NULL);
		for (int x = 0; x < 30; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				if (x < 10)
					memcpy(img_data + 3 * (y * 30 + x), &red, 3);
				else if (x < 20)
					memcpy(img_data + 3 * (y * 30 + x), &green, 3);
				else
					memcpy(img_data + 3 * (y * 30 + x), &blue, 3);
			}
		}
		mlx_put_image_to_window(mlx, win, img, x, y);
		mlx_destroy_image(mlx, img);
	}
}

int main(void) {
	void *const mlx = mlx_init();
	void *win;

	// MENU
	{
		switch (uc_menu_quick("pixels", "images", "quit", NULL))
		{
		case 0:
			goto pixels;
			break;
		case 1:
			goto images;
			break;
		}
		goto end;
	}

pixels:
	cout << "create window..." << endl;
	uc_pause();
	win = mlx_new_window(mlx, 400, 240, "hey");

	cout << "clear window..." << endl;
	uc_pause();
	mlx_clear_window(mlx, win);

	cout
		<< "Put pixels for red green and blue" << endl
		<< "at the top-left corner..." << endl;
	uc_pause();
	{
		int block_y = 20;
		for (
			int block_x = 20, color = 0xFF0000;
			block_x <= 60;
			block_x += 20, color = color >> 8
		)
			for (int x = 0; x < 10; x++)
				for (int y = 0; y < 10; y++)
					mlx_pixel_put(mlx, win, block_x + x, block_y + y, color);
	}

	cout << "clear window..." << endl;
	uc_pause();
	mlx_clear_window(mlx, win);

	cout << "destroy window..." << endl;
	uc_pause();
	mlx_destroy_window(mlx, win);

	goto end;

images:
	cout << "create window..." << endl;
	uc_pause();
	win = mlx_new_window(mlx, 400, 240, "hoi");

	cout << "clear window..." << endl;
	uc_pause();
	mlx_clear_window(mlx, win);

	draw_rainbow_image(mlx, win, 185, 110);
	draw_rainbow_image(mlx, win, -15, 100);
	draw_rainbow_image(mlx, win, 385, 120);
	draw_rainbow_image(mlx, win, 170, -10);
	draw_rainbow_image(mlx, win, 200, 230);
	draw_rainbow_image(mlx, win, -15, -10);
	draw_rainbow_image(mlx, win, 385, -10);
	draw_rainbow_image(mlx, win, -15, 230);
	draw_rainbow_image(mlx, win, 385, 230);

	cout << "Draw RG image at (20,10)..." << endl;
	uc_pause();
	{
		t_image img = mlx_new_image(mlx, 30, 20);
		char *img_data = mlx_get_data_addr(img, NULL, NULL, NULL);
		for (int x = 0; x < 30; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				u32 color =
					((0xFF0000 * x / 30) & 0xFF0000)
					| ((0x00FF00 * y / 20) & 0x00FF00);
				memcpy(img_data + 3 * (y * 30 + x), &color, 3);
			}
		}
		mlx_put_image_to_window(mlx, win, img, 20, 10);
		mlx_destroy_image(mlx, img);
	}

	cout << "Draw GB image at (50,0)..." << endl;
	uc_pause();
	{
		t_image img = mlx_new_image(mlx, 10, 50);
		char *img_data = mlx_get_data_addr(img, NULL, NULL, NULL);
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 50; y++)
			{
				u32 color =
					((0x00FF00 * x / 10) & 0x00FF00)
					| ((0x0000FF * y / 50) & 0x0000FF);
				memcpy(img_data + 3 * (y * 10 + x), &color, 3);
			}
		}
		mlx_put_image_to_window(mlx, win, img, 50, 0);
		mlx_destroy_image(mlx, img);
	}

	cout << "Draw BR image at (200,100)..." << endl;
	uc_pause();
	{
		t_image img = mlx_new_image(mlx, 100, 100);
		char *img_data = mlx_get_data_addr(img, NULL, NULL, NULL);
		for (int x = 0; x < 100; x++)
		{
			for (int y = 0; y < 100; y++)
			{
				u32 color =
					((0x0000FF * x / 100) & 0x0000FF)
					| ((0xFF0000 * y / 100) & 0xFF0000);
				memcpy(img_data + 3 * (y * 100 + x), &color, 3);
			}
		}
		mlx_put_image_to_window(mlx, win, img, 200, 100);
		mlx_destroy_image(mlx, img);
	}

	cout << "clear window..." << endl;
	uc_pause();
	mlx_clear_window(mlx, win);

	cout << "destroy window..." << endl;
	uc_pause();
	mlx_destroy_window(mlx, win);

	goto end;

end:
	cout << "Exit..." << endl;
	uc_pause();

	gfxExit();
}
