unsigned long timing =0;

#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Buzzer buzzer(PIN_BUZZER);

int i = 1;
int notes[] = {NOTE_G5,NOTE_G4,NOTE_G4, NOTE_G5,NOTE_FS5,NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_E5,
               NOTE_GS4,NOTE_CS5,NOTE_C5,NOTE_B4,NOTE_AS4,NOTE_A4,NOTE_AS4,
               NOTE_DS4,NOTE_FS4,NOTE_DS4,NOTE_AS4,NOTE_G4};
double durations[] = {7,3,3,7,7,6,6,6,6,
                      4,5,5,4,4,4,4,
                      3,3,2,1,7};
int melodyLength = 21;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn(); 

}

void loop()
{
       if (buttonMelodyOne.wasPressed())
    {   
       for (i = 1; i < 5; i++)
       {
         tone(PIN_BUZZER, notes[0]);
         delay (500);
         noTone(PIN_BUZZER);
         delay (5000);
        }
    
        while (timing = 5000)
        {
        buzzer.playSound();
        timing = millis();
        }
        //buzzer.turnSoundOff(); 
    }
}
