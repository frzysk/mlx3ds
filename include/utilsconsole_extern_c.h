/**
 * utilsconsole_extern_c.h
 *   by Zy
 */

/**
 * utilsconsole_extern_c.h (uc_*() functions)
 */

#ifndef UTILSCONSOLE_EXTERN_C_H
# define UTILSCONSOLE_EXTERN_C_H

/// @brief Blocks the program until the user presses A.
/// @details Will also return if aptMainLoop() becomes false.
void uc_pause(void);

/// @brief Show the 3DS keyboard to ask the user for a text.
/// @param def The default text to show the user.
/// @return A freeable address to the text prompted by the user. NULL if error.
char	*uc_keyboard(const char *def);

#endif
