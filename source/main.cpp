extern "C" {
#include "mlx.h"
#include "3ds.h"
#include "mlx3ds.h"
#include "utilsconsole.h"
}
#include <iostream>
#include "firsk.xpm"
#include <string.h>
#include <sys/dirent.h>
#include <fcntl.h>
#include <unistd.h>

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
		switch (uc_menu_quick("pixels", "images", "xpm", "files",
			"navigate", "assets", "quit", NULL))
		{
		case 0:
			goto pixels;
			break;
		case 1:
			goto images;
			break;
		case 2:
			goto xpm;
			break;
		case 3:
			goto files;
			break;
		case 4:
			goto navigate;
			break;
		case 5:
			goto assets;
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

xpm:
	cout << "create window..." << endl;
	uc_pause();
	win = mlx_new_window(mlx, 400, 240, "hey");

	cout << "Show XPM image..." << endl;
	uc_pause();
	{
		static const char *xpm[] = {
			"4 3 3 2",
			"r  c red",
			"g  c green",
			"b  c blue",
			"r g b r ",
			"g b r g ",
			"b r g b ",
		};
		t_image img = mlx_xpm_to_image(mlx, xpm, NULL, NULL);
		if (img)
			mlx_put_image_to_window(mlx, win, img, 10, 10);
		else
			cout << "error :(" << endl;
	}

	cout << "Show bigger XPM image..." << endl;
	uc_pause();
	{
		/* XPM */
		static const char *xpm[] = {
		/* plaid pixmap
		* width height ncolors chars_per_pixel */
		"22 22 4 2",
		/* colors */
		"r  c red",
		"Y  c green",
		"+  c yellow",
		"x  c black",
		/* pixels */
		"x r x r x x x r x r x x x x x x + x x x x x ",
		"r x r x r x r x r x r x x x x x x x x x x x ",
		"x r x r x x x r x r x x x x x x + x x x x x ",
		"r x r x r x r x r x r x x x x x x x x x x x ",
		"x r x r x x x r x r x x x x x x + x x x x x ",
		"Y Y Y Y Y x Y Y Y Y Y + x + x + x + x + x + ",
		"x r x r x x x r x r x x x x x x + x x x x x ",
		"r x r x r x r x r x r x x x x x x x x x x x ",
		"x r x r x x x r x r x x x x x x + x x x x x ",
		"r x r x r x r x r x r x x x x x x x x x x x ",
		"x r x r x x x r x r x x x x x x + x x x x x ",
		"r r r r r x r r r r r x r x r x Y x r x r x ",
		"r r r r r x r r r r r r x r x r Y r x r x r ",
		"r r r r r x r r r r r x r x r x Y x r x r x ",
		"r r r r r x r r r r r r x r x r Y r x r x r ",
		"r r r r r x r r r r r x r x r x Y x r x r x ",
		"x x x x x x x x x x x x x x x x x x x x x x ",
		"r r r r r x r r r r r x r x r x Y x r x r x ",
		"r r r r r x r r r r r r x r x r Y r x r x r ",
		"r r r r r x r r r r r x r x r x Y x r x r x ",
		"r r r r r x r r r r r r x r x r Y r x r x r ",
		"r r r r r x r r r r r x r x r x Y x r x r x "
		};
		t_image img = mlx_xpm_to_image(mlx, xpm, NULL, NULL);
		if (img)
			mlx_put_image_to_window(mlx, win, img, 20, 10);
		else
			cout << "error :(" << endl;
	}

	cout << "Show firsk..." << endl;
	uc_pause();
	{
		t_image img = mlx_xpm_to_image(mlx, firsk, NULL, NULL);
		if (img)
			mlx_put_image_to_window(mlx, win, img, 100, 10);
		else
			cout << "error :(" << endl;
	}

	cout << "destroy window..." << endl;
	uc_pause();
	mlx_destroy_window(mlx, win);

	goto end;

files:
	cout << "Current working directory: " << getcwd(NULL, 0) << endl;
	uc_pause();

	cout << "List of files in /:" << endl;
	{
		DIR *dir = opendir("/");
		dirent *dir_in;
		do
		{
			dir_in = readdir(dir);
			if (!dir_in)
				break;
			cout << "> " << dir_in->d_name << endl;
		} while (dir_in);
		closedir(dir);
	}
	uc_pause();

	cout << "Read file abc.txt..." << endl;
	{
		int f = 0;
		f = open("/abc.txt", O_RDONLY);
		if (!f)
		{
			cout << "open() error :(" << endl;
			goto file_read_end;
		}
		char buf[1000];
		{
			cout << "file content:" << endl << "\"";
			int n = 1;
			while (n)
			{
				n = read(f, buf, 1000);
				if (n < 0)
				{
					cout << "read() error :(" << endl;
					goto file_read_end;
				}
				if (n > 0)
					write(1, buf, n);
			}
			cout << "\"" << endl;
		}

	file_read_end:
		if (f)
			close(f);
	}
	uc_pause();

	cout << "Write \"hello :3\" in abc.txt..." << endl;
	{
		int f = 0;
		f = open("/abc.txt", O_WRONLY | O_CREAT);
		if (!f)
		{
			cout << "open() error :(" << endl;
			goto file_write_end;
		}
		if (write(f, "hello :3", 8) < 0)
			cout << "write() error :(" << endl;
		else
			cout << "write() success :)" << endl;

	file_write_end:
		if (f)
			close(f);
	}
	uc_pause();

	cout << "Read file abc.txt again..." << endl;
	{
		int f = 0;
		f = open("/abc.txt", O_RDONLY);
		if (!f)
		{
			cout << "open() error :(" << endl;
			goto file_read2_end;
		}
		char buf[1000];
		{
			cout << "file content:" << endl << "\"";
			int n = 1;
			while (n)
			{
				n = read(f, buf, 1000);
				if (n < 0)
				{
					cout << "read() error :(" << endl;
					goto file_read2_end;
				}
				if (n > 0)
					write(1, buf, n);
			}
			cout << "\"" << endl;
		}

	file_read2_end:
		if (f)
			close(f);
	}
	uc_pause();

	goto end;

navigate:
	{
		char *last = new char[2];
		last[0] = '/';
		last[1] = '\n';
		while (true)
		{
			cout << "Write a file path or a directory path toshow it." << endl;
			cout << "Put an empty text to return." << endl;
			uc_pause();
			char *name = NULL;
			if (aptMainLoop())
				name = uc_keyboard(last);
			if (!name || !strcmp(name, ""))
				break;
			cout << "\e[7m" << name << "\e[0m" << endl;
			cout << "Try to open as directory..." << endl;
			DIR *dir = opendir(name);
			if (dir)
			{
				cout << "Directory opened!" << endl;
				uc_pause();
				cout << "Files:" << endl;
				dirent *dir_in;
				do {
					dir_in = readdir(dir);
					if (dir_in)
						cout << "> " << dir_in->d_name << endl;
				} while (dir_in);
				closedir(dir);
			}
			else {
				cout << "Can't open as directory." << endl;
				cout << "Try to open as file..." << endl;
				int file = open(name, O_RDONLY);
				if (file)
				{
					cout << "File opened!" << endl;
					uc_pause();
					cout << "Content:" << endl;
					int n = 1;
					char buf[1000];
					while (n > 0)
					{
						n = read(file, buf, 1000);
						if (n < 0)
							cout << "read() error :(" << endl;
						else if (n > 0)
							write(1, buf, n);
					}
					cout << "[EOF]" << endl;
					close(file);
				}
				else
				{
					cout << "Can't either." << endl;
					cout << "Seems nothing works." << endl;
					cout << "That is sad." << endl;
					cout << "Anyway," << endl;
				}
			}
			delete [] last;
			last = name;
			uc_pause();
		}
		delete [] last;
	}
	goto end;

assets:
	{
		const t_embeddedasset *asset;

		cout << "Read asset \"hello\"..." << endl;
		asset = mlx3ds_assets_get("hello");
		if (asset)
			cout << "Content (" << asset->size << "): \""
				<< asset->data << "\"" << endl;
		else
			cout << "No asset" << endl;
		uc_pause();
		cout << "Read asset \"bonjour\"..." << endl;
		asset = mlx3ds_assets_get("bonjour");
		if (asset)
			cout << "Content (" << asset->size << "): \""
				<< asset->data << "\"" << endl;
		else
			cout << "No asset" << endl;
		uc_pause();
		cout << "Read asset \"hola\"..." << endl;
		asset = mlx3ds_assets_get("hola");
		if (asset)
			cout << "Content (" << asset->size << "): \""
				<< asset->data << "\"" << endl;
		else
			cout << "No asset" << endl;
		uc_pause();
		cout << "Read asset \"sous/fichier\"..." << endl;
		asset = mlx3ds_assets_get("sous/fichier");
		if (asset)
			cout << "Content (" << asset->size << "): \""
				<< asset->data << "\"" << endl;
		else
			cout << "No asset" << endl;
		uc_pause();
		cout << "Read asset \"sous/sous/fichier\"..." << endl;
		asset = mlx3ds_assets_get("sous/sous/fichier");
		if (asset)
			cout << "Content (" << asset->size << "): \""
				<< asset->data << "\"" << endl;
		else
			cout << "No asset" << endl;
		uc_pause();
		{
			char buf[10];
			cout
				<< "Read asset \"sous/sous/fichier\"" << endl
				<< "from mlx3ds_assets_open()..." << endl
				<< "(buf[10])" << endl;
			t_assetsocket asset = mlx3ds_assets_open("sous/sous/fichier");
			if (!asset)
				cout << "Error" << endl;
			else {
				cout << "Content: \"";
				int n;
				do {
					n = mlx3ds_assets_read(asset, buf, 10);
					if (n < 0) {
						cout << "read error :/" << endl;
						break;
					}
					if (n > 0)
						write(1, buf, n);
				} while (n);
				cout << "\"" << endl;
				mlx3ds_assets_close(asset);
			}
		}
		uc_pause();
		{
			char buf[100];
			cout
				<< "Read asset \"sous/sous/fichier\"" << endl
				<< "from mlx3ds_assets_open()..." << endl
				<< "(buf[100])" << endl;
			t_assetsocket asset = mlx3ds_assets_open("sous/sous/fichier");
			if (!asset)
				cout << "Error" << endl;
			else {
				cout << "Content: \"";
				int n;
				do {
					n = mlx3ds_assets_read(asset, buf, 100);
					if (n < 0) {
						cout << "read error :/" << endl;
						break;
					}
					if (n > 0)
						write(1, buf, n);
				} while (n);
				cout << "\"" << endl;
				mlx3ds_assets_close(asset);
			}
		}
		uc_pause();
	}
	goto end;

end:
	cout << "Exit..." << endl;
	uc_pause();

	gfxExit();
}
