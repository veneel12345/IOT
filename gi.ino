 int val = 0 ;  
 //connect vcc pin to vin pin
  //connect gnd pin to gnd pin
   //connect out pin to  pin
 void setup()  
 {  
   Serial.begin(9600); // sensor buart rate  
   pinMode(14,HIGH);  // Led Pin Connected To D5 Pin    
 }  
 void loop()   
 {  
  val = digitalRead(5); // IR Sensor output pin connected to D1  
  Serial.println(val);  // see the value in serial m0nitor in Arduino IDE  
  delay(100);      // for timer  
  if(val == 1 )  
  {  
   digitalWrite(14,HIGH); // LED ON  
  }  
  else  
  {  
   digitalWrite(14,LOW); // LED OFF  
  }  
  }