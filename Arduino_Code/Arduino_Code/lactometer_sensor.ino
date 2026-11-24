// FOR ARDUINO CONNECT SDA TO A4 AND SCL TO A5
// for arduino connect frequency input to pin 5
// MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 4

#include <SD.h>
#include <SPI.h>
#include <FreqCount.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the 16x2 LCD at I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

int i = 0;
unsigned long val[10], sum = 0, avg = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  
  // Format headers for PLX-DAQ Excel logging
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Date & Time, Frequency(Hz)");
  
  // Initialize and turn on the LCD screen
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Frequency in Hz");
  
  // Start the frequency counter on Pin 5 with a 1000ms gate time
  FreqCount.begin(1000);
  delay(3000);
  lcd.clear();
}

void loop() {
  if (FreqCount.available()) {
    // Capture data sequentially across genuine gate intervals
    val[i] = FreqCount.read();
    sum += val[i];
    i++;
    
    // Once 10 genuine sequential samples are captured (takes ~10 seconds)
    if (i >= 10) {
      avg = sum / 10;
      
      // Update the I2C LCD Display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Avg Freq:");
      lcd.setCursor(0, 1);
      lcd.print(avg);
      lcd.print(" Hz");
      
      // Send data out to the Serial Monitor / Excel logging
      Serial.print("DATA,TIME,");
      Serial.println(avg);
      
      // Reset averaging variables for the next cycle
      sum = 0;
      i = 0;
    }
  }
}
