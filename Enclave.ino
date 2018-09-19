/*
 * Arduinoで動作するVFD管時計。
 * 
  */
#include <SPI.h>
#include <Wire.h>
#include <DS3231.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306_STM32.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


DS3231 Clock;
bool Century=false;
bool h12;
bool PM;


void setup() {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.display();

  // Wire.begin();
  
  Clock.setSecond(50);//Set the second 
  Clock.setMinute(59);//Set the minute 
  Clock.setHour(23);  //Set the hour 
  Clock.setDoW(5);    //Set the day of the week
  Clock.setDate(31);  //Set the date of the month
  Clock.setMonth(5);  //Set the month of the year
  Clock.setYear(13);  //Set the year (Last two digits of the year)
 
}

void ReadDS3231()
{
  int second,minute,hour,date,month,year,temperature; 
  second=Clock.getSecond();
  minute=Clock.getMinute();
  hour=Clock.getHour(h12, PM);
  date=Clock.getDate();
  month=Clock.getMonth(Century);
  year=Clock.getYear();
  
  temperature=Clock.getTemperature();

  /*
  Serial.print("20");
  Serial.print(year,DEC);
  Serial.print('-');
  Serial.print(month,DEC);
  Serial.print('-');
  Serial.print(date,DEC);
  Serial.print(' ');
  Serial.print(hour,DEC);
  Serial.print(':');
  Serial.print(minute,DEC);
  Serial.print(':');
  Serial.print(second,DEC);
  Serial.print('\n');
  Serial.print("Temperature=");
  Serial.print(temperature); 
  Serial.print('\n');
  */

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("20" + String(year,DEC) + "-" + String(month,DEC) + "-" + String(date,DEC) + "-" + String(hour,DEC) + "-" + String(minute,DEC) + "-" + String(second,DEC));
  display.display();

  /*
  int BEAT = 500;
  tone(PA8,330,BEAT) ;  // ミ
  delay(BEAT) ;
  tone(PA8,262,BEAT) ;  // ド
  delay(BEAT) ;
  tone(PA8,330,BEAT) ;  // ミ
  delay(BEAT) ;
  tone(PA8,262,BEAT) ;  // ド
  delay(BEAT) ;
  tone(PA8,330,BEAT/2) ;  // ミ
  delay(BEAT/2) ;
  tone(PA8,262,BEAT/2) ;  // ド
  delay(BEAT/2) ;
  tone(PA8,330,BEAT/2) ;  // ミ
  delay(BEAT/2) ;
  tone(PA8,262,BEAT/2) ;  // ド
  delay(BEAT/2) ;
  tone(PA8,330,BEAT) ;  // ミ
  delay(BEAT) ;
  tone(PA8,262,BEAT) ;  // ド
  delay(BEAT) ;
  tone(PA8,392,BEAT) ;
  delay(BEAT) ;
  tone(PA8,440,BEAT) ;  // ド
  delay(BEAT) ;
  tone(PA8,392,BEAT) ;  // ド
  delay(BEAT) ;
  tone(PA8,349,BEAT) ;  // ド
  delay(BEAT) ;
  tone(PA8,330,BEAT) ;  // ド
  delay(BEAT) ;
  tone(PA8,294,BEAT*2) ;  // ド
  delay(BEAT*2) ;
  */
     
}

void loop() {     
  ReadDS3231();
  delay(10);
}
