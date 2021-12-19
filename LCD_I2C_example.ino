//******************************************************************************
//I2C demo code
//author: Josip Prpić
//This code is open source, you can use it as you wish in any of your projects :)
//IMPORTANT INFO:
//   - you have to install LCD I2C library.
//   - I2C address of the LCD [File -> Examples -> Wire -> I2C scanner]
//******************************************************************************

#include <LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#define BACKLIGHT_PIN     13


void setup() {
  // switch backlight on
  pinMode(BACKLIGHT_PIN, OUTPUT);
  digitalWrite(BACKLIGHT_PIN, HIGH);

  //initialize lcd
  lcd.begin(16,2);
  lcd.home();
  lcd.print("Hello World");
  lcd.setCursor(0,1); //lcd.setCursor(column, line);
  lcd.print("MicroChips INFO");
}

//function to create blinking aniamtion
void do_animation(){
  //initialize lcd
  lcd.home();
  //do an infinite loop
  while(true){
    //set cursor to 14th position in first line, wirte "*" character and wait 1000 ms
    lcd.setCursor(14,0);
    lcd.print("*");
    delay(1000);
    //set cursor to 14th position in first line and write nothing to create blinking animation and wait 1000 ms
    lcd.setCursor(14,0);
    lcd.print(" ");
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //little animation of blinking star in the right corner
  do_animation();

}
