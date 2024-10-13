/**
 * mlx_events.h
 *   for the project "MinilibX for 3DS"
 *   by Zy
 *   at https://github.com/frzysk/mlx3ds
 *
 * The content of this file comes from "X.h".
 */

/**
 * This file contains the event and mask values to use with mlx_hook().
 * The mask values are here for compatibility, they aren't used for the 3DS.
 */

#ifndef MLX_EVENTS_H
# define MLX_EVENTS_H

// TODO docs mlx_events.h
// TODO add function prototypes.

/// @brief Sent when a key starts to be pressed.
///        Hook prototype: `int keypress_hook(int keycode, void *param);`
# define KeyPress			2
/// @brief Sent when a key ends being pressed.
///        Hook prototype: `int keyrelease_hook(int keycode, void *param);`
# define KeyRelease			3
/// @brief Sent when the window was just created, before all other events.
///        Hook prototype: `int create_hook(void *param);`
# define CreateNotify		16
/// @brief Sent to all the windows when the software is quitting, after all
///        the other events.
///        Hook prototype: `int destroy_hook(void *param);`
# define DestroyNotify		17

# define ButtonPress		4 // Unused, this event will never be sent.
# define ButtonRelease		5 // Unused, this event will never be sent.
# define MotionNotify		6 // Unused, this event will never be sent.
# define EnterNotify		7 // Unused, this event will never be sent.
# define LeaveNotify		8 // Unused, this event will never be sent.
# define FocusIn			9 // Unused, this event will never be sent.
# define FocusOut			10 // Unused, this event will never be sent.
# define KeymapNotify		11 // Unused, this event will never be sent.
# define Expose				12 // Unused, this event will never be sent.
# define GraphicsExpose		13 // Unused, this event will never be sent.
# define NoExpose			14 // Unused, this event will never be sent.
# define VisibilityNotify	15 // Unused, this event will never be sent.
# define UnmapNotify		18 // Unused, this event will never be sent.
# define MapNotify			19 // Unused, this event will never be sent.
# define MapRequest			20 // Unused, this event will never be sent.
# define ReparentNotify		21 // Unused, this event will never be sent.
# define ConfigureNotify	22 // Unused, this event will never be sent.
# define ConfigureRequest	23 // Unused, this event will never be sent.
# define GravityNotify		24 // Unused, this event will never be sent.
# define ResizeRequest		25 // Unused, this event will never be sent.
# define CirculateNotify	26 // Unused, this event will never be sent.
# define CirculateRequest	27 // Unused, this event will never be sent.
# define PropertyNotify		28 // Unused, this event will never be sent.
# define SelectionClear		29 // Unused, this event will never be sent.
# define SelectionRequest	30 // Unused, this event will never be sent.
# define SelectionNotify	31 // Unused, this event will never be sent.
# define ColormapNotify		32 // Unused, this event will never be sent.
# define ClientMessage		33 // Unused, this event will never be sent.
# define MappingNotify		34 // Unused, this event will never be sent.
# define GenericEvent		35 // Unused, this event will never be sent.
# define LASTEvent			36 // A number bigger that all event values.

// Unused, the MinilibX for 3DS doesn't use event masks.
# define NoEventMask				0L
// Unused, the MinilibX for 3DS doesn't use event masks.
# define KeyPressMask				(1L<<0)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define KeyReleaseMask				(1L<<1)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define ButtonPressMask			(1L<<2)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define ButtonReleaseMask			(1L<<3)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define EnterWindowMask			(1L<<4)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define LeaveWindowMask			(1L<<5)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define PointerMotionMask			(1L<<6)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define PointerMotionHintMask		(1L<<7)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define Button1MotionMask			(1L<<8)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define Button2MotionMask			(1L<<9)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define Button3MotionMask			(1L<<10)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define Button4MotionMask			(1L<<11)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define Button5MotionMask			(1L<<12)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define ButtonMotionMask			(1L<<13)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define KeymapStateMask			(1L<<14)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define ExposureMask				(1L<<15)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define VisibilityChangeMask		(1L<<16)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define StructureNotifyMask		(1L<<17)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define ResizeRedirectMask			(1L<<18)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define SubstructureNotifyMask		(1L<<19)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define SubstructureRedirectMask	(1L<<20)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define FocusChangeMask			(1L<<21)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define PropertyChangeMask			(1L<<22)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define ColormapChangeMask			(1L<<23)
// Unused, the MinilibX for 3DS doesn't use event masks.
# define OwnerGrabButtonMask		(1L<<24)

#endif
