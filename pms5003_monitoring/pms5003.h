#ifndef PMS5003_H
#define PMS5003_H

struct config{
  static const uint32_t responseWait = 5000;

  static const int setPin = 6;
  static const int rstPin = 7;
};

void pmsStartup(void);
void pmsRead(void);

#endif