#ifndef ML_ALG_READ_H
#define ML_ALG_READ_H

#include "SoftwareSerial.h"
#include "pms5003.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class DataSubset{
  public:
    DataSubset();
    ~DataSubset();

    uint16_t getPM(int selection);
    int getTemp();
    int getHumidity();

    void collectPM(uint16_t pm1, uint16_t pm2, uint16_t pm3);
    void collectTemp(int tempVal);
    void collectHumidity(int humidityVal);

  private:
    std::vector<int> pmValues; // change w/ individual uint16_t values

    int temp;
    int humidity;
};

int predictAQ(DataSubset collectedData);
void classifyAQ(DataSubset collectedData);

#endif