int buz=7,ledR=6,ledG=3,ledB=5; //declare pins for buzzer and LEDs 
const char* notesN[]={" ","B0","C1","C#1","D1","D#1","E1","F1","F#1","G1","G#1","A1","A#1","B1","C2","C#2","D2","D#2","E2","F2","F#2","G2","G#2","A2","A#2","B2","C3","C#3","D3","D#3","E3","F3","F#3","G3","G#3","A3","A#3","B3","C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4","C5","C#5","D5","D#5","E5","F5","F#5","G5","G#5","A5","A#5","B5","C6","C#6","D6","D#6","E6","F6","F#6","G6","G#6","A6","A#6","B6","C7","C#7","D7","D#7","E7","F7","F#7","G7","G#7","A7","A#7","C8","C#8","D8","D#8","E8","F8","F#8","G8","G#8","A8","A#8","B8","C9","C#9","D9","D#9","E9","F9","F#9","G9","G#9","A9","A#9","B9"}; // array to store all musical notes
const double notesFq[]={0,31,32.703,34.648,36.708,38.891,41.203,43.654,46.249,48.999,51.913,55,58.27,61.735,65.406,69.296,73.416,77.782,82.407,87.307,92.499,97.999,103.826,110,116.541,123.471,130.813,138.591,146.832,155.563,164.814,174.614,184.997,195.998,207.652,220,233.082,246.942,261.626,277.183,293.665,311.127,329.628,349.228,369.994,391.995,415.305,440,466.164,493.883,523.251,554.365,587.33,622.254,659.255,698.456,739.989,783.991,830.609,880,932.328,987.767,1046.502,1108.731,1174.659,1244.508,1318.51,1396.913,1479.978,1567.982,1661.219,1760,1864.655,1975.533,2093.005,2217.461,2349.318,2489.016,2637.021,2793.826,2959.955,3135.964,3322.438,3520,3729.31,3951.066,4186.009,4434.922,4698.636,4978.032,5274.042,5587.652,5919.91,6271.928,6644.876,7040,7458.62,7902.132,8372.018,8869.844,9397.272,9956.064,10548.084,11175.304,11839.82,12543.856,13289.752,14080,14917.24,15804.264}; //array to store the frequency of the respective note
int ch,dur; 
int lenN=sizeof(notesN)/sizeof(char);
int lenFq=sizeof(notesFq)/sizeof(double);

void setup()
{
  pinMode(buz,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
  tone(buz,0,0);
  Serial.begin(9600);
}
double durCalc(int fq) //to calculate time duration of each frequency
{
  int t=1000/(2*fq);
  return t;
}
void loop()
{
 noTone(buz);
  Serial.println();
  Serial.println("Enter your choice in 5 sec.");
  Serial.println("1.Play Fur Elise by Beethoven");
  ch=Serial.parseInt();
  delay(5000);
 
  
  int L1;
  
  switch(ch)
  {
    case 1: Serial.println("Playing Fur Elise by Beethoven");
            char* notesFE[]={"E5","D#5","E5","D#5","E5","B4","D5","C5","A4","A3"," "," ","C4","E4","A4","B4","E3"," ","E4","G#4","B4","C5","A3"," ","E4","E5","D#5","E5","D#5","E5","B4","D5","C5","A4","A3"," ","C4","E4","A4","B4","E3","E4","C5","B4","A4","A3"," ","B4","C5","D5","C4","E5","G4","F5","E5","B3","D5"," ","F4","E5","D5","C5","A3"," ","E4","D5","C5","B4","G#3","E5","D#5","E5","D#5","E5","B4","D5","C5","A4","A3"," ","C4","E4","A4","B4","E3","E4","G#4","B4","C5","A3","E4","E5","D#5","E5","D#5","E5","B4","D5","C5","A4","A3"," ","C4","E4","A4","B4","E3"," ","E4","C5","B4","E4","A4","A3"," ","E4","C5","B4","E4","A4","A3"," "," "}; 
            L1=sizeof(notesFE)/sizeof(char);
            for(int i=0;i<L1;i++)
            {
              for(int j=0;j<lenN;j++)
              {
                if(notesFE[i]==notesN[j])
              {
                dur= durCalc(notesFq[i]);
                  Serial.print(notesFE[i]);
                  Serial.println();
                      analogWrite(ledR,200);
                 analogWrite(ledB,100); 
                analogWrite(ledG,10);
                 delay(15);
                analogWrite(ledB,200); 
                  analogWrite(ledG,100);
                 analogWrite(ledR,10);
                  delay(15);
                  analogWrite(ledG,200);
                 analogWrite(ledB,100);
                  analogWrite(ledR,10);
                 delay(10);
                tone(buz,notesFq[j],525);
                 delay(175);
                
            
               }
            } 
         }
            delay(10000);
         break;
   }
}


                     
  
