/*******************************************************
 * SANTRONIX <info@santronix.in>
 * 
 * This file is part of SANTRONIX Mediatek LinkIt Tutorials Project.
 * 
 * SANTRONIX Mediatek LinkIt Tutorials Project can not be copied and/or distributed without the express
 * permission of SANTRONIX
 *******************************************************/

#include <math.h>
#include <Wire.h>
#include <SeeedOLED.h>

const int analogSensor = A0;
const int digitalSensor = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display

  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode

  pinMode(digitalSensor, INPUT);
}

void loop() {
    
    int a = analogRead(analogSensor);
    int b = digitalRead(digitalSensor);
    
    SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
    SeeedOled.putString("Analog:  "); //Print the String
    SeeedOled.putNumber(a);
    SeeedOled.setTextXY(4,0);
    SeeedOled.putString("Digital:  ");
    if(b == HIGH)
    {
      SeeedOled.putString("HIGH");
    }else{
      SeeedOled.putString("LOW ");
    }

    delay(100);
}
