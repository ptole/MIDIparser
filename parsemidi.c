#include "parsemidi.h"

int parse_midi( midi_msg_t *msg, uint8_t *buffer ) {

    if((buffer[0] & 0x80) == 0) {
        return -1; // Invalid MIDI message
    }

    msg->type = buffer[0] & 0xF0;
    msg->channel = buffer[0] & 0x0F;

    msg->data1 = buffer[1];
    msg->data2 = buffer[2];

    return 0;
}