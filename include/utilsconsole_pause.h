/**
 * utilsconsole_pause.h
 *   by Zy
 */

/**
 * utilsconsole_pause.h (uc_pause() function)
 */

#ifndef UTILSCONSOLE_PAUSE_H
# define UTILSCONSOLE_PAUSE_H

/// @brief Blocks the program until the user presses A.
/// @details Will also return if aptMainLoop() becomes false.
void uc_pause(void);

#endif
