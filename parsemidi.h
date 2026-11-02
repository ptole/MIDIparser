#include <stdint.h>

#define NOTE_OFF 0x80
#define NOTE_ON 0x90
#define POLY_PRESSURE 0xA0
#define CONTROL_CHANGE 0xB0
#define PROGRAM_CHANGE 0xC0
#define CHANNEL_PRESSURE 0xD0
#define PITCH_BEND 0xE0
#define SYSTEM_EXCLUSIVE 0xF0
#define SYSTEM_COMMON 0xF1
#define SYSTEM_MTC 0xF1
#define SYSTEM_SONG_POSITION 0xF2
#define SYSTEM_SONG_SELECT 0xF3
#define SYSTEM_TUNE_REQUEST 0xF6
#define SYSTEM_END_OF_EXCLUSIVE 0xF7
#define SYSTEM_REALTIME 0xF8
#define SYSTEM_START 0xFA
#define SYSTEM_CONTINUE 0xFB
#define SYSTEM_STOP 0xFC
#define SYSTEM_ACTIVE_SENSING 0xFE
#define SYSTEM_RESET 0xFF


typedef struct {
    uint8_t type;
    uint8_t channel;

    union {
        struct { uint8_t data1, data2; };
        struct { uint8_t note, velocity; };
        struct { uint8_t poly_note, pressure; };
        struct { uint8_t controller, data; };
        struct { uint8_t program, unused0; };
        struct { uint8_t aftertouch_pressure, unused1; };
        struct { uint8_t lsb, msb; };
        struct { uint16_t pitch; };
        };
} midi_msg_t;


int parse_midi( midi_msg_t *msg, uint8_t *buffer );