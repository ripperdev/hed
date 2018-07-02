#ifndef HED_TYPES_H
#define HED_TYPES_H

#include <stdint.h>

// Key enumeration, returned by utils_read_key().
enum key_codes {
    KEY_NULL      = 0,
    KEY_CTRL_C    = 0x03,
    KEY_CTRL_D    = 0x04,
    KEY_CTRL_H    = 0x08,
    KEY_TAB       = 0x09,
    KEY_CTRL_Q    = 0x11,
    KEY_CTRL_R    = 0x12,
    KEY_CTRL_S    = 0x13,
    KEY_CTRL_U    = 0x15,
    KEY_ESC       = 0x1b,
    KEY_ENTER     = 0x0d,
    KEY_BACKSPACE = 0x7f,

    KEY_UP      = 0x400,// [A
    KEY_DOWN,           // [B
    KEY_RIGHT,          // [C
    KEY_LEFT,           // [D
    KEY_DEL,            // . = 1b, [ = 5b, 3 = 33, ~ = 7e,
    KEY_HOME,           // [H
    KEY_END,            // [F
    KEY_PAGEUP,         // ??
    KEY_PAGEDOWN,       // ??
};

typedef struct {
    uint8_t o; // Original
    uint8_t c; // Current
    int g; // Grammar index
} byte_t;

enum action_type {
    ACTION_BASE, // Used as the base of actions
    ACTION_REPLACE,
    ACTION_INSERT,
    ACTION_DELETE,
    ACTION_APPEND
};

static const char* action_names[] = {
        "base",
        "replace",
        "insert",
        "delete",
        "append"
};

typedef struct action_t{
    struct action_t *prev;
    struct action_t *next;

    enum action_type type;
    unsigned int offset;

    byte_t b; // Changed/modified byte (original)

}HEAction;

typedef struct {
    HEAction *first;
    HEAction *last;
    HEAction *current; // So we can redo

}HEActionList;

#endif