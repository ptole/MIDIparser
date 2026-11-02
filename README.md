# MIDIparser
C library for parsing messages to MIDI format.

The parser takes in reference to a midi type struct and an uint8 buffer.
Returns -1 if MSB was missing.


### List of commands and aliases 
```
NOTE_OFF 0x80
NOTE_ON 0x90
POLY_PRESSURE 0xA0
CONTROL_CHANGE 0xB0
PROGRAM_CHANGE 0xC0
CHANNEL_PRESSURE 0xD0
PITCH_BEND 0xE0
SYSTEM_EXCLUSIVE 0xF0
SYSTEM_COMMON 0xF1
SYSTEM_MTC 0xF1
SYSTEM_SONG_POSITION 0xF2
SYSTEM_SONG_SELECT 0xF3
SYSTEM_TUNE_REQUEST 0xF6
SYSTEM_END_OF_EXCLUSIVE 0xF7
SYSTEM_REALTIME 0xF8
SYSTEM_START 0xFA
SYSTEM_CONTINUE 0xFB
SYSTEM_STOP 0xFC
SYSTEM_ACTIVE_SENSING 0xFE
SYSTEM_RESET 0xFF

note, velocity
poly_note, pressure
controller, data
program
aftertouch_pressure
lsb, msb,
pitch
```
### Example
After parsing the message you can easily just compare the messages type to provided list of commands and pass the message to your own functions.

For example:
```
midi_msg_t msg;
parse_midi(&msg, your_buffer);
if( msg.type == NOTE_ON ){
    play_note( msg.channel, msg.note, msg.velocity );
}
```