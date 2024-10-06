/**
 * utilsconsole.hpp
 *   by Zy
 */

/**
 * utilsconsole.hpp (uc_*() functions)
 * Utility functions for the 3DS console.
 */

#pragma once

#include <string>
#include <vector>

using namespace std;

/// @brief To use with uc_menu(): Represent an element of the menu.
typedef struct { 
    /// @brief Displayed name.
    string name;
    /// @brief true if this button can be used to change the value of a number.
    bool is_number_prompt;
    /// @brief Only if is_number_prompt is true: the number to change.
    int *value;
    /// @brief Only if is_number_prompt is true: the minimum value possible for
    ///        value.
    int min;
    /// @brief Only if is_number_prompt is true: the maximum value possible for
    ///        value.
    int max;
} s_uc_menu_element;

/// @brief Display a menu with several items in the console.
/// @details
/// Non-blocking function, must be called in loop.
/// Only one menu can work at the same time. 'elements' must not change in
/// address.
/// @param elements A pointer to a vector of all the elements of the menu.
/// @return The index of the confirmed element. If none, return -1.
int uc_menu(vector<s_uc_menu_element> &elements);

/// @brief Display a menu quickly using only confirm buttons.
/// @details
/// Blocking function. Will return -1 if aptMainLoop() becomes false.
/// @param str Text representing each element. The last parameter must be NULL.
/// @return The index of the confirmed element.
int uc_menu_quick(const char *str, ...);

/// @brief Blocks the program until the user presses A.
/// @details Will also return if aptMainLoop() becomes false.
void uc_pause(void);
