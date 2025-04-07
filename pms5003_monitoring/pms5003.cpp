#include "PMS.h"
#include "SoftwareSerial.h"

#include "pms5003.h"

PMS pmsSerial(Serial);
PMS::DATA dataObj;

config param;

void pmsStartup(void){
  Serial.begin(115200);            

  // Set to read in low-power mode
  pmsSerial.passiveMode();
}

void pmsRead(){
  pmsSerial.activeMode();
  pmsSerial.requestRead(); // Send data read request
  Serial.print("Printing Air Quality Data...\n");
  if(pmsSerial.readUntil(dataObj, param.responseWait)){
    
    Serial.print("PMS5003 Sensor Values");
    Serial.println("---------------------");

    Serial.print("PM 1.0 (ug/m^3): ");
    Serial.println(dataObj.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m^3): ");
    Serial.println(dataObj.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m^3): ");
    Serial.println(dataObj.PM_AE_UG_10_0);

    Serial.println();
  }

  else{
    Serial.println("Data not retrieved.");
  }
}
