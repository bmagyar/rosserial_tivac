#ifndef ROS_TIVA_HARDWARE_H_
#define ROS_TIVA_HARDWARE_H_

#include <Arduino.h>  // Arduino 1.0
#include <Energia.h>

#include <HardwareSerial.h>
#define SERIAL_CLASS HardwareSerial

class TivaHardware {
  public:
    TivaHardware(SERIAL_CLASS* io , long baud= 57600)
    {
      iostream = io;
      baud_ = baud;
    }

    TivaHardware()
    {
      iostream = &Serial;
      baud_ = 57600;
    }
    TivaHardware(TivaHardware& h){
      this->iostream = iostream;
      this->baud_ = h.baud_;
    }
  
    void setBaud(long baud)
    {
      this->baud_= baud;
    }
  
    int getBaud(){return baud_;}

    void init(){
#if defined(USE_USBCON)
      // Startup delay as a fail-safe to upload a new sketch
      delay(3000); 
#endif
      iostream->begin(baud_);
    }

    int read()
    {
      return iostream->read();
    }

    void write(uint8_t* data, int length){
      for(int i=0; i<length; i++)
        iostream->write(data[i]);
    }

    unsigned long time(){return millis();}

  protected:
    SERIAL_CLASS* iostream;
    long baud_;
};

#endif
