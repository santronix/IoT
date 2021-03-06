/*******************************************************
 * SANTRONIX <info@santronix.in>
 * 
 * This file is part of SANTRONIX Mediatek LinkIt Tutorials Project.
 * 
 * SANTRONIX Mediatek LinkIt Tutorials Project can not be copied and/or distributed without the express
 * permission of SANTRONIX
 *******************************************************/

#define WetSoilValue        3200
#define SensorPin           A0
#define MotorPin            7
#define PublishInterval     5000

int WetSoilValueReached = false;
unsigned long LastTextTime = 0;

void setup() {
    pinMode(SensorPin, INPUT);
    pinMode(MotorPin, OUTPUT);
}

void loop() {
    if(analogRead(SensorPin) < WetSoilValue){
        WetSoilValueReached = true;
        digitalWrite(MotorPin, LOW);
        
        unsigned long now = millis();
        
        if (now - LastTextTime >= PublishInterval) { 
            Particle.publish("Soil moisture low, turning on sprinklers!");
        }
    }else{
        WetSoilValueReached = false;
        digitalWrite(MotorPin, HIGH);
    }
    delay(5000);
}
