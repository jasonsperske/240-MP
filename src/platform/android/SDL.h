#pragma once
// Android stand-in for the slice of SDL2 that InputManager uses. On the desktop, SDL2 reads
// gamepads; on Android, Qt already receives gamepad and remote buttons as key events
// (MainActivity.kt maps them to the keys the views expect), and SDL's Android backend would
// need its own Java activity. So this header lets InputManager compile unchanged with SDL
// reporting itself unavailable: SDL_Init fails, InputManager logs "gamepad support disabled",
// and the keyboard, remap and hint paths work as on any machine without a pad.
//
// Only on the include path for Android builds (CMakeLists.txt).

#include <cstdint>

typedef int8_t   Sint8;
typedef uint8_t  Uint8;
typedef int16_t  Sint16;
typedef uint16_t Uint16;
typedef int32_t  Sint32;
typedef uint32_t Uint32;
typedef Sint32   SDL_JoystickID;

#define SDL_VERSION_ATLEAST(X, Y, Z) 0
#define SDL_INIT_GAMECONTROLLER 0x00002000u
#define SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS "SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS"
#define SDL_HINT_NO_SIGNAL_HANDLERS "SDL_NO_SIGNAL_HANDLERS"
#define SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS "SDL_GAMECONTROLLER_USE_BUTTON_LABELS"

typedef enum {
    SDL_CONTROLLER_BUTTON_INVALID = -1,
    SDL_CONTROLLER_BUTTON_A,
    SDL_CONTROLLER_BUTTON_B,
    SDL_CONTROLLER_BUTTON_X,
    SDL_CONTROLLER_BUTTON_Y,
    SDL_CONTROLLER_BUTTON_BACK,
    SDL_CONTROLLER_BUTTON_GUIDE,
    SDL_CONTROLLER_BUTTON_START,
    SDL_CONTROLLER_BUTTON_LEFTSTICK,
    SDL_CONTROLLER_BUTTON_RIGHTSTICK,
    SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
    SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
    SDL_CONTROLLER_BUTTON_DPAD_UP,
    SDL_CONTROLLER_BUTTON_DPAD_DOWN,
    SDL_CONTROLLER_BUTTON_DPAD_LEFT,
    SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
    SDL_CONTROLLER_BUTTON_MAX
} SDL_GameControllerButton;

typedef enum {
    SDL_CONTROLLER_AXIS_INVALID = -1,
    SDL_CONTROLLER_AXIS_LEFTX,
    SDL_CONTROLLER_AXIS_LEFTY,
    SDL_CONTROLLER_AXIS_RIGHTX,
    SDL_CONTROLLER_AXIS_RIGHTY,
    SDL_CONTROLLER_AXIS_TRIGGERLEFT,
    SDL_CONTROLLER_AXIS_TRIGGERRIGHT,
    SDL_CONTROLLER_AXIS_MAX
} SDL_GameControllerAxis;

typedef enum {
    SDL_CONTROLLER_TYPE_UNKNOWN = 0,
    SDL_CONTROLLER_TYPE_XBOX360,
    SDL_CONTROLLER_TYPE_XBOXONE,
    SDL_CONTROLLER_TYPE_PS3,
    SDL_CONTROLLER_TYPE_PS4,
    SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO,
    SDL_CONTROLLER_TYPE_VIRTUAL,
    SDL_CONTROLLER_TYPE_PS5,
    SDL_CONTROLLER_TYPE_AMAZON_LUNA,
    SDL_CONTROLLER_TYPE_GOOGLE_STADIA,
    SDL_CONTROLLER_TYPE_NVIDIA_SHIELD,
    SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_JOYCON_LEFT,
    SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT,
    SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_JOYCON_PAIR
} SDL_GameControllerType;

enum {
    SDL_CONTROLLERAXISMOTION = 0x650,
    SDL_CONTROLLERBUTTONDOWN,
    SDL_CONTROLLERBUTTONUP,
    SDL_CONTROLLERDEVICEADDED,
    SDL_CONTROLLERDEVICEREMOVED
};

typedef struct SDL_GameController SDL_GameController;
typedef struct SDL_Joystick SDL_Joystick;

typedef struct { Uint32 type; SDL_JoystickID which; Uint8 axis; Sint16 value; } SDL_ControllerAxisEvent;
typedef struct { Uint32 type; SDL_JoystickID which; Uint8 button; Uint8 state; } SDL_ControllerButtonEvent;
typedef struct { Uint32 type; Sint32 which; } SDL_ControllerDeviceEvent;
typedef union {
    Uint32 type;
    SDL_ControllerAxisEvent caxis;
    SDL_ControllerButtonEvent cbutton;
    SDL_ControllerDeviceEvent cdevice;
} SDL_Event;

inline int SDL_Init(Uint32) { return -1; }
inline void SDL_Quit() {}
inline const char *SDL_GetError() { return "SDL is not used on Android"; }
inline int SDL_SetHint(const char *, const char *) { return 0; }
inline int SDL_PollEvent(SDL_Event *) { return 0; }
inline int SDL_GameControllerAddMappingsFromFile(const char *) { return -1; }
inline SDL_GameController *SDL_GameControllerOpen(int) { return nullptr; }
inline void SDL_GameControllerClose(SDL_GameController *) {}
inline const char *SDL_GameControllerName(SDL_GameController *) { return ""; }
inline SDL_Joystick *SDL_GameControllerGetJoystick(SDL_GameController *) { return nullptr; }
inline SDL_JoystickID SDL_JoystickInstanceID(SDL_Joystick *) { return -1; }
inline SDL_GameControllerType SDL_GameControllerGetType(SDL_GameController *) { return SDL_CONTROLLER_TYPE_UNKNOWN; }
inline const char *SDL_GameControllerGetStringForButton(SDL_GameControllerButton) { return nullptr; }
inline SDL_GameControllerButton SDL_GameControllerGetButtonFromString(const char *) { return SDL_CONTROLLER_BUTTON_INVALID; }
inline SDL_GameControllerAxis SDL_GameControllerGetAxisFromString(const char *) { return SDL_CONTROLLER_AXIS_INVALID; }
