#include <inttypes.h>
#include "midi.h"

static uint8_t last_written_status = 0x0;

void resetStatus() {
   last_written_status = 0x0;
}

// Write status uint8_t (support running status)
void writeChannelStatus(uint8_t status) {
   if (status != last_written_status) {
      Serial.write(status);
      last_written_status = status;
   }
}

/* Send control-change
 *  
 * Channel = [1..16]
 */
void sendControlChange(uint8_t channel, uint8_t ctrl, uint8_t value) {
   writeChannelStatus(0xB0 | (channel-1));
   Serial.write(ctrl);
   Serial.write(value);
}

/* Envoie un Program Change
 *  
 * Channel = [1..16]
 */
void sendProgramChange(uint8_t channel, uint8_t value) {
   writeChannelStatus(0xC0 | (channel-1));
   Serial.write(value);
}

void sendNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
   writeChannelStatus(0x80 | (channel-1));
   Serial.write(note);
   Serial.write(velocity);
}

void sendNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
   writeChannelStatus(0x90 | (channel-1));
   Serial.write(note);
   Serial.write(velocity);
}

void sendKeyAfterTouch(uint8_t channel, uint8_t note, uint8_t pressure) {
   writeChannelStatus(0xA0 | (channel-1));
   Serial.write(note);
   Serial.write(pressure);
}

void sendChannelAfterTouch(uint8_t channel, uint8_t pressure) {
   writeChannelStatus(0xD0 | (channel-1));
   Serial.write(pressure);
}

void sendPitchBend(uint8_t channel, uint16_t bend) {
   writeChannelStatus(0xE0 | (channel-1));
   Serial.write(bend & 0xFF);
   Serial.write(bend >> 8);
}

void sendRealtimeMessage(uint8_t status) {
   Serial.write(status);
   resetStatus();
}


void setPatch(uint8_t channel, uint8_t bank0, uint8_t bank1, uint8_t patch) {
   sendControlChange(channel, 0, bank0);
   sendControlChange(channel, 32, bank1);
   sendProgramChange(channel, patch);
}

void midiStart() {
   sendRealtimeMessage(0x0A);
};

void midiContinue() {
   sendRealtimeMessage(0x0B);
};

void midiStop() {
   sendRealtimeMessage(0x0C);
};
