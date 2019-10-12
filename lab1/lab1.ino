#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Buzzer buzzer(PIN_BUZZER);

int i = 1;
int notes[] = {NOTE_G4,NOTE_G4,NOTE_G4,NOTE_DS4,NOTE_AS4,NOTE_G4,NOTE_DS4,NOTE_AS4,NOTE_G4,
               NOTE_D5,NOTE_D5,NOTE_D5,NOTE_DS5,NOTE_AS4,NOTE_G4,NOTE_DS4,NOTE_AS4,NOTE_G4,
               NOTE_G5,NOTE_G4,NOTE_G4, NOTE_G5,NOTE_FS5,NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_E5,
               NOTE_GS4,NOTE_CS5,NOTE_C5,NOTE_B4,NOTE_AS4,NOTE_A4,NOTE_AS4,
               NOTE_DS4,NOTE_FS4,NOTE_DS4,NOTE_AS4,NOTE_G4};
double durations[] = {350,350,350,250,100,350,250,100,700,
                      350,350,350,250,100,350,250,100,700,
                      784,392,392,784,739,698,659,622,659,
                      415,554,523,493,466,440,466,
                      311,350,250,100,750};
int melodyLength = 4;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
    if (buttonMelodyOne.wasPressed())
    {   
       for (i=1; i<5; i++){
         tone(PIN_BUZZER, notes[0]);
         delay (500);
         noTone(PIN_BUZZER);
         delay (5000);
        }
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
    }
}
