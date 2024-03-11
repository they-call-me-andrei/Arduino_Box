#include <Servo.h>                        

Servo mana;                         
Servo capac;

int pozitieSwitch=0, action=1, vot, randNumber=0;
int x = 1,servopos = 0;
int SwitchPin = 2;


#define  grave          40
#define  largo          46
#define  lento          52
#define  adagio         56
#define  larghetto      60
#define  adagietto      66
#define  andante        72
#define  andantino      80
#define  maestroso      88
#define  moderato      100
#define  allegretto    104
#define  animato       120
#define  allegro       132
#define  allegro_assai 144
#define  vivace        160
#define  presto        184
#define  prestissimo   208




#define note_G3  196
#define note_A3  220
#define note_B3  247
#define note_C4  262 
#define note_D4  294
#define note_E4  330
#define note_FS4 370
#define note_G4  392
#define note_A4  440
#define note_B4  494
#define note_C5  523
#define note_D5  587



#define speaker 11    

float default_tempo = float(prestissimo); 
float current_tempo = default_tempo;
float timings[7];                 


#define semib       timings[0] // semi briev       - 4 beats
#define minim       timings[2] // minim            - 2 beats
#define crot        timings[3] // crotchet         - 1 beat
#define quav        timings[4] // quaver           - 1/2 beat


#define num_carols  10

void we_wish_you_a_merry_christmas();
void jingle_bells();



void (*play_list[num_carols])() = {
  we_wish_you_a_merry_christmas,
  jingle_bells
};


void wait(float duration) {
  uint32_t start;
  start    = millis();
  duration = duration * 1000; 
  do {
  } while (millis() - start <= duration);
}


void set_tempo(float new_tempo) {
  float crotchet_duration;
  current_tempo = new_tempo;           // keep current tempo up to date in case it needs to be queried
  crotchet_duration = 60 / new_tempo;  // timing in seconds for 1 beat
  semib      = crotchet_duration * 4;  // semibrieve, 4 beats
  minim      = crotchet_duration * 2;  // minim, 2 beats
  crot       = crotchet_duration;      // crotchet, 1 beat
  quav       = crotchet_duration / 2;  // quaver, 1/2 beat

}

void play(int note, float note_duration) {
  tone(speaker, note, note_duration * 1000);
  wait(note_duration);                      
}


void rest(float rest_duration) {
  noTone(speaker);      
  wait(rest_duration);  
}

void setup()
{
  Serial.begin(9600);
  capac.write(0);
  mana.write(180);
  mana.attach(5);
  capac.attach(6);
  pinMode(speaker, OUTPUT);
  set_tempo(default_tempo);
}


void loop()
{
  pozitieSwitch = digitalRead(2);
  if(pozitieSwitch == HIGH){
   // if(action == 1){
        for (int i = 0; i <= 80; i++){
          capac.write(i);
          delay(6);
        }
        delay(550);
        mana.write(0);
        delay(550);
        mana.write(180);
        delay(550);
        capac.write(0);
        delay(1500);
        for (int i = 0; i <= 80; i++){
          capac.write(i);
          delay(6);
        }
        delay(3000);
        capac.write(0);
        action++;
    //}
  }


}
void we_wish_you_a_merry_christmas() {
  set_tempo(default_tempo);

  for (uint8_t repeat = 1; repeat <= 2; repeat++) {

    play(note_D4, crot);

    play(note_G4, crot);
    play(note_G4, quav);
    play(note_A4, quav);
    play(note_G4, quav);
    play(note_FS4, quav);

    play(note_E4, crot);
    play(note_E4, crot);
    play(note_E4, crot);

    play(note_A4, crot);
    play(note_A4, quav);
    play(note_B4, quav);
    play(note_A4, quav);
    play(note_G4, quav);

    play(note_FS4, crot);
    play(note_D4, crot);
    play(note_D4, crot);

    play(note_B4, crot);
    play(note_B4, quav);
    play(note_C5, quav);
    play(note_B4, quav);
    play(note_A4, quav);

    play(note_G4, crot);
    play(note_E4, crot);
    play(note_D4, quav);
    play(note_D4, quav);

    play(note_E4, crot);
    play(note_A4, crot);
    play(note_FS4, crot);

    play(note_G4, minim);
    play(note_D4, crot);
    
    play(note_G4, crot);
    play(note_G4, crot);
    play(note_G4, crot);

    play(note_FS4, minim);
    play(note_FS4, crot);

    play(note_G4, crot);
    play(note_FS4, crot);
    play(note_E4, crot);

    play(note_D4, minim);
    play(note_A4, crot);

    play(note_B4, crot);
    play(note_A4, crot);
    play(note_G4, crot);

    play(note_D5, crot);
    play(note_D4, crot);
    play(note_D4, quav);
    play(note_D4, quav);

    play(note_E4, crot);
    play(note_A4, crot);
    play(note_FS4, crot);

    play(note_G4, minim);
    rest(crot);
  }
}

void jingle_bells() {
  set_tempo(default_tempo * 2);

  rest(minim);
  for (uint8_t repeat = 1; repeat <= 2; repeat++) {

    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);

    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);

    play(note_B3, crot);
    play(note_D4, crot);
    play(note_G3, crot);
    play(note_A3, crot);

    play(note_B3, semib);

    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);

    play(note_C4, crot);
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, crot);

    play(note_B3, crot);
    play(note_A3, crot);
    play(note_A3, crot);
    play(note_B3, crot);

    play(note_A3, minim);
    play(note_D4, minim);

    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);

    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, minim);

    play(note_B3, crot);
    play(note_D4, crot);
    play(note_G3, crot);
    play(note_A3, crot);

    play(note_B3, semib);

    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);
    play(note_C4, crot);

    play(note_C4, crot);
    play(note_B3, crot);
    play(note_B3, crot);
    play(note_B3, crot);

    play(note_D4, crot);
    play(note_D4, crot);
    play(note_C4, crot);
    play(note_A3, crot);

    play(note_G3, semib);
  }
}
