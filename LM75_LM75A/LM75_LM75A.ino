
#include <LM75A.h>  //https://github.com/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library
#define  LED 3
// Create I2C LM75A instance
LM75A lm75a_sensor(false,  //A0 LM75A pin state
                   false,  //A1 LM75A pin state
                   false); //A2 LM75A pin state
float temperature_in_degrees ;
float tmpF;
void setup(void)
{
  Serial.begin(9600);
  Serial.println("LM75A Test");
  pinMode(LED,OUTPUT);

}

void loop()
{
   // Robojax.com LM75A Test
     temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();

  if (temperature_in_degrees == INVALID_LM75A_TEMPERATURE) {
    Serial.println("Error while getting temperature");
  } else {
    Serial.print("   Temp: ");
    Serial.print(temperature_in_degrees);
    Serial.print(" C ");
    tmpF = LM75A::degreesToFahrenheit(temperature_in_degrees);
//    Serial.print(tmpF);
//    Serial.println(" F)");
             
  }
    if(temperature_in_degrees>=40){
      digitalWrite(LED,HIGH);
      Serial.print("\t : เปิด\n");
      
      }
    else{
       digitalWrite(LED,LOW);
       Serial.print("\t : ปิด\n");
      
      }

  
}
