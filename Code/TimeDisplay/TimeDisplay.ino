
  /*
      Group 7 - Jonas B., Signe, Thomas T & Tim
      Mercantec - Viborg College of Technology
      20/09-2018
  */

  //Working code for a concept of a clock on the LCD display.
  
//------------------------------------------------------------------- START OF CODE -------------------------------------------------------------------//
  
  //------------------- Include the LiquidCrystal library (LC lib)--------------------//
  #include <LiquidCrystal.h>
  
  //------------------- Create integers for holding LCD pins --------------------//
  int RS = 1;
  int EN = 2;
  int D4 = 4;
  int D5 = 5;
  int D6 = 6;
  int D7 = 7;
  
  //------------------- Create integers for holding time --------------------//
  int s = 0;
  int m = 10;
  int h = 11;

  //------------------- Create integers for customizing the clock --------------------//
  int secToMin = 60;
  int minToHour = 60;
  int hourToDay = 24;
  
  //------------------- Create variables for a timer. --------------------//
  long startMillis;
  long currentMillis;
  long clockMillis;
  long colonMillis;
  const int second = 1000;
  
  //------------------- Create an LCD object using the LC lib --------------------//
  LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
  
  //------------------- Everything that needs to be run once, goes here --------------------//
  void setup() {
    lcd.begin(16, 2);
  }
  
  //------------------- Everything in here is run once every frame --------------------//
  void loop() {
    currentMillis = millis();
    calculateTime();
    displayTime();
  }
  
  //------------------- Function for calculating time passing --------------------//
  void calculateTime() {
    
    //------------------- Every time a second has passed, add one to the s variable --------------------//
    if (currentMillis - clockMillis >= second) {
      s++;
      lcd.setCursor(2, 0);
      lcd.print(":");
      //------------------- Blinking colon --------------------//
      if (currentMillis - colonMillis >= 2 * second) {
        lcd.setCursor(2, 0);
        lcd.print(" ");
        colonMillis = currentMillis;
      }
      clockMillis = currentMillis;
    }
    
    //------------------- Every time a minute has passed, add one to the m variable --------------------//
    if (s == secToMin) {
      lcd.clear();
      s = 0;
      m++;
    }
    
    //------------------- Every time an hour has passed, add one to the h variable --------------------//
    if (m == minToHour) {
      m = 0;
      h++;
    }
    
    //------------------- Every time a day has passed, set h to zero. --------------------//
    if (h == hourToDay) {
      h = 0;
    }
  }

  //------------------- Function for displaying the current time --------------------//
  void displayTime() {
    
    //------------------- Display hours --------------------//
    if (h < 10) {
      lcd.setCursor(0, 0);
      lcd.print("0");
      lcd.setCursor(1, 0);
      lcd.print(h);
    } else if (h >= 10) {
      lcd.setCursor(0, 0);
      lcd.print(h);
    }
    
    //------------------- Display minutes --------------------//
    if (m < 10) {
      lcd.setCursor(3, 0);
      lcd.print("0");
      lcd.setCursor(4, 0);
      lcd.print(m);
    } else if (m >= 10) {
      lcd.setCursor(3, 0);
      lcd.print(m);
    }
  }
  
//------------------------------------------------------------------- END OF CODE -------------------------------------------------------------------//
  
