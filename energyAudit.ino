#define SAMPLES 300
#define CURRENT_PIN A1

float highPeak;
float lowPeak;

float ampsPeakToPeak;
float ampsRms;

//function to obtain the peak-to-peak reading off the current pin
void readAmps(){
  int counter;

  highPeak = 0;
  lowPeak = 100;

for(counter = 0; counter<SAMPLES; counter++){
  int ampsInput = analogRead(CURRENT_PIN);
  ampsInput = map(ampsInput, 0, 1024, 0, 60);
  
  if (ampsInput > highPeak){
    highPeak = ampsInput;
    }

  if(ampsInput < highPeak){
    lowPeak = ampsInput;
    } 
  }
ampsPeakToPeak = highPeak - lowPeak;
}

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(CURRENT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readAmps();

  ampsRms = ampsPeakToPeak*0.3536;

  Serial.print("Current Rms = ");
  Serial.println(ampsRms);

  delay(3000);

}
