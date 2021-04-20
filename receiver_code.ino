//#include <SoftwareSerial.h>
//SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
#include <SPI.h>
#include <SD.h>

const byte csSD = 13;   //SPI chip select pin

String incoming;
File myFile;

void setup() {
  Serial.begin(9600);             // Serial port to computer
//  HC12.begin(9600);               // Serial port to HC12
  Serial.println("starting");
  initSD();
}


void loop() 
{

//  while (HC12.available()) {             // If HC-12 has data
  while (Serial.available()) {             // If HC-12 has data
//    incomingByte = HC12.read();          // Store each icoming byte from HC-12
    incoming = Serial.readStringUntil('\n');          // Store each icoming byte from HC-12
    Serial.println(incoming);
    delay(5);
    myFile = SD.open("test.txt", FILE_WRITE);
      if (myFile)
      {
         Serial.print("Writing to test.txt...");
         myFile.println(incoming);        
         myFile.close();
         Serial.println("done.");
      }
      else
      {
         // if the file didn't open, print an error:
         Serial.println("error opening test.txt");
      }
      }
//
}


void initSD()
{
   Serial.print("Initializing SD card...");
   if (!SD.begin(csSD))
   {
      Serial.println("initialization failed!");
      while (1);
   }
   Serial.println("initialization done.");
}
