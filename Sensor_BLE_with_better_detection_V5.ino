char val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if( Serial.available() )
  {
    val = Serial.read();
  }
  if( val == 'S' )
  {
    // RUN DATA COLLECTION HERE
    runScan();
    Serial.println("EndOfScan");
    Serial.flush(); //clear the serial cache 
  }
  delay(300); //300 ms Refresh
}

void runScan() {
 
  int lowRangeCounter = 0;
  int midRangeCounter = 0;
  int highRangeCounter = 0;
  int youreDeadCounter = 0;
  int low = 0;
  int mid = 0;
  int high = 0;
  int dead = 0;
  int air1 = 0;
  int air2 = 0;
  int air3 = 0;

  Serial.println("please put your hand on the sensor");
  delay(2000);
  
  
  air1 = analogRead(0);
  Serial.println(air1);
 air2 = analogRead(1);
Serial.println(air2);
 air3 = analogRead(2);
Serial.println(air3);
 
  for(int i; i < 40; i++){
     delay(30);
    int a = analogRead(0);
  Serial.println(a);
    
    if(a >= 800 - air1){
      youreDeadCounter++;
    }
    else if(a < (800 - air1) && a >= 500 - air1){
      highRangeCounter++;
    }
    else if(a < (500 - air1)&& a >= (300-air1)){
      midRangeCounter++;
    }
    else {
      lowRangeCounter++;
    }
  }
   
  if(lowRangeCounter > 25){

    low = low + 1;
  }
  else if(midRangeCounter > 25){

    mid = mid + 1;
  }
  else if(highRangeCounter > 25){

    high = high + 1;
  }
  else if(youreDeadCounter > 25){

    dead = dead + 1;
  }
  delay(1000);
  
 

 
 
  for(int i; i < 40; i++){
     delay(30);
    int a = analogRead(1);
    Serial.println(a);
    
    if(a >= 800-air2){
      youreDeadCounter++;
    }
    else if(a < (800-air2) && a >= (500-air2)){
      highRangeCounter++;
    }
    else if(a < (500-air2) && a >= (300-air2)){
      midRangeCounter++;
    }
    else {
      lowRangeCounter++;
    }
  }
   
  if(lowRangeCounter > 25){

    low = low + 1;
  }
  else if(midRangeCounter > 25){

    mid = mid + 1;
  }
  else if(highRangeCounter > 25){
 
    high = high + 1;
  }
  else if(youreDeadCounter > 25){

    dead = dead + 1;
  }
  delay(1000);


 
 
  for(int i; i < 40; i++){
     delay(30);
    int a = analogRead(2);
    Serial.println(a);
   
    if(a >= 800-air3){
      youreDeadCounter++;
      
    }
    else if(a < (800-air3) && a >= (500-air3)){
      highRangeCounter++;
      
    }
    else if(a < (500-air3) && a >= (300-air3)){
      midRangeCounter++;
      
    }
    else {
      lowRangeCounter++;
      
    }
  }
    
   
   
  if(lowRangeCounter > 25){

    low = low + 1;
  }
  else if(midRangeCounter > 25){

    mid = mid + 1;
  }
  else if(highRangeCounter > 25){

    high = high + 1;
  }
  else if(youreDeadCounter > 25){

    dead = dead + 1;
  }
  delay(1000);
  if(dead == 3){
    Serial.println("You are Dead");
    Serial.println("H");
    }else if (high ==3 ) {
      Serial.println("Please dont drive");
       Serial.println("H");

    }else if (mid == 3){
      Serial.println("questionalble");
      Serial.println("M");

      }else if (low == 3){
        Serial.println("Your Good");
        Serial.println("L");

        }else {
          Serial.println("Null");
    }
}




