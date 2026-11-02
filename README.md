# MIDIparser
C library for parsing messages to MIDI format.

The parser takes in reference to a midi type struct and an uint8 buffer.
Returns -1 if MSB was missing.


### List of commands
```
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
```
### Example
After parsing the message you can easily just compare the messages type to provided list of commands and pass the message to your own functions.

For example:
```
midi_msg_t msg;
parse_midi(&msg, &your_buffer);
if( msg.type == NOTE_ON ){
    play_note( msg.channel, msg.note, msg.velocity );
}
```