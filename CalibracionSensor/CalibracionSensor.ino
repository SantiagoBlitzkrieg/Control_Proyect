//Basado en el video de PicaioVideos
#include <Wire.h>
#include "VL53L0X.h"

VL53L0X sensor;



void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);

  Wire.begin(21, 22);
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println(" Error: No se detecta");
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int distancia = sensor.readRangeSingleMillimeters();
  float distanciaCalibrada = distancia; 

  if (sensor.timeoutOccurred()){
    Serial.print("Timeout");

  }

  Serial.println("Distancia calibrada: ");
  Serial.print(distanciaCalibrada - 40);
  Serial.println(" mm");

  delay (500);

}
