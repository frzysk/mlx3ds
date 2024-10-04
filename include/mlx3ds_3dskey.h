/**
 * mlx3ds_3dskey.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 */

/**
 * Enum of all the keys of the 3ds.
 * 
 * These are the same constants defined in hid.h from devkitPro,
 * but with documentation that basically repeat what the name
 * of the constants already say.
 */

#ifndef MLX3DS_3DSKEY_H
# define MLX3DS_3DSKEY_H

# define BIT(n) 1U << n

/// @brief Represents a key of the 3DS.
typedef enum e_3dskey
{
	/* BUTTONS */

	/// @brief A button
	KEY_A = BIT(0),
	/// @brief B button
	KEY_B = BIT(1),
	/// @brief X button
	KEY_X = BIT(10),
	/// @brief Y button
	KEY_Y = BIT(11),
	/// @brief Select button
	KEY_SELECT = BIT(2),
	/// @brief Start button
	KEY_START = BIT(3),
	/// @brief R button
	KEY_R = BIT(8),
	/// @brief L button
	KEY_L = BIT(9),

	/* DIRECTIONS */

	/// @brief D-Pad Right
	KEY_DRIGHT = BIT(4),
	/// @brief D-Pad Left
	KEY_DLEFT = BIT(5),
	/// @brief D-Pad Up
	KEY_DUP = BIT(6),
	/// @brief D-Pad Down
	KEY_DDOWN = BIT(7),
	/// @brief C-Pad Right
	KEY_CPAD_RIGHT= BIT(28),
	/// @brief C-Pad Left
	KEY_CPAD_LEFT = BIT(29),
	/// @brief C-Pad Up
	KEY_CPAD_UP = BIT(30),
	/// @brief C-Pad Down
	KEY_CPAD_DOWN = BIT(31),

	/* TOUCH */

	// ??? unsure what KEY_TOUCH is... TODO
	KEY_TOUCH = BIT(20),

	/* New 3DS */

	/// @brief C-Stick Right (only for New 3DS)
	KEY_CSTICK_RIGHT = BIT(24),
	/// @brief C-Stick Left (only for New 3DS)
	KEY_CSTICK_LEFT = BIT(25),
	/// @brief C-Stick Up (only for New 3DS)
	KEY_CSTICK_UP = BIT(26),
	/// @brief C-Stick Down (only for New 3DS)
	KEY_CSTICK_DOWN = BIT(27),
	/// @brief ZL button (only for New 3DS)
	KEY_ZL = BIT(14),
	/// @brief ZR button (only for New 3DS)
	KEY_ZR = BIT(15),

	// TODO implement catch-all directions?
	/*
	// ???
	KEY_UP    = KEY_DUP    | KEY_CPAD_UP,    ///< D-Pad Up or Circle Pad Up
	// ???
	KEY_DOWN  = KEY_DDOWN  | KEY_CPAD_DOWN,  ///< D-Pad Down or Circle Pad Down
	// ???
	KEY_LEFT  = KEY_DLEFT  | KEY_CPAD_LEFT,  ///< D-Pad Left or Circle Pad Left
	// ???
	KEY_RIGHT = KEY_DRIGHT | KEY_CPAD_RIGHT, ///< D-Pad Right or Circle PadRight
	*/
}	t_3dskey;

#endif