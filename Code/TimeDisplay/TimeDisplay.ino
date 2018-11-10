
  /*
      Group 7 - Jonas B., Signe, Thomas T & Tim
      Mercantec - Viborg College of Technology
      20/09-2018
  */

  //Working code for a concept of a clock on the LCD display.
 
  //------------------- Include the LiquidCrystal library --------------------//
  #include <LiquidCrystal.h>
  #include <Step.h>
  
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
  int ph = 200;         //skal være lig noget den ikke starter med

  //------------------- Create integers for customizing the clock --------------------//
  int secToMin = 60;
  int minToHour = 60;
  int hourToDay = 24;
  
  //------------------- Create variables for a timer --------------------//
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
      ph = h;
    }
    
    //------------------- Every time a day has passed, set h to zero --------------------//
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

  void moveP () {
    switch (m) {
      case 0:
        wipe(2) 
        draw(1,0);
        draw(2,0);
          break;
      case 1:
        wipe(1)
        draw(1,0);
        draw(2,1);
          break;
      case 2:
        wipe(1)
        draw(1,0);
        draw(2,2);
        motorReset(1);
        motorReset(2);
          break;
      case 3:
        wipe(1)
        draw(1,0);
        draw(2,3);
        motorReset(1);
        motorReset(2);
          break;
      case 4:
        wipe(1)
        draw(1,0);
        draw(2,4);
        motorReset(1);
        motorReset(2);
          break;
      case 5:
        wipe(1)
        draw(1,0);
        draw(2,5);
        motorReset(1);
        motorReset(2);
          break;
      case 6:
        wipe(1)
        draw(1,0);
        draw(2,6);
        motorReset(1);
        motorReset(2);
          break;
      case 7:
        wipe(1)
        draw(1,0);
        draw(2,7);
        motorReset(1);
        motorReset(2);
          break;
      case 8:
        wipe(1)
        draw(1,0);
        draw(2,8);
        motorReset(1);
        motorReset(2);
          break;
      case 9:
        wipe(1)
        draw(1,0);
        draw(2,9);
        motorReset(1);
        motorReset(2);
          break;
      case 10:
        wipe(1)
        draw(1,1);
        draw(2,0);
        motorReset(1);
        motorReset(2);
          break;
      case 11:
        wipe(1)
        draw(1,1);
        draw(2,1);
        motorReset(1);
        motorReset(2);
          break;
      case 12:
        wipe(1)
        draw(1,1);
        draw(2,2);
        motorReset(1);
        motorReset(2);
          break;
      case 13:
        wipe(1)
        draw(1,1);
        draw(2,3);
        motorReset(1);
        motorReset(2);
          break;
      case 14:
        wipe(1)
        draw(1,1);
        draw(2,4);
        motorReset(1);
        motorReset(2);
          break;
      case 15:
        wipe(1)
        draw(1,1);
        draw(2,5);
        motorReset(1);
        motorReset(2);
          break;
      case 16:
        wipe(1)
        draw(1,1);
        draw(2,6);
        motorReset(1);
        motorReset(2);
          break;
      case 17:
        wipe(1)
        draw(1,1);
        draw(2,7);
        motorReset(1);
        motorReset(2);
          break;
      case 18:
        wipe(1)
        draw(1,1);
        draw(2,8);
        motorReset(1);
        motorReset(2);
          break;
      case 19:
        wipe(1)
        draw(1,1);
        draw(2,9);
        motorReset(1);
        motorReset(2);
          break;
      case 20:
        wipe(1)
        draw(1,2);
        draw(2,0);
        motorReset(1);
        motorReset(2);
          break;
      case 21:
        wipe(1)
        draw(1,2);
        draw(2,1);
        motorReset(1);
        motorReset(2);
          break;
      case 22:
        wipe(1)
        draw(1,2);
        draw(2,2);
        motorReset(1);
        motorReset(2);
          break;
      case 23:
        wipe(1)
        draw(1,2);
        draw(2,3);
        motorReset(1);
        motorReset(2);
          break;
      case 24:
        wipe(1)
        draw(1,2);
        draw(2,4);
        motorReset(1);
        motorReset(2);
          break;
      case 25:
        wipe(1)
        draw(1,2);
        draw(2,5);
        motorReset(1);
        motorReset(2);
          break;
      case 26:
        wipe(1)
        draw(1,2);
        draw(2,6);
        motorReset(1);
        motorReset(2);
          break;
      case 27:
        wipe(1)
        draw(1,2);
        draw(2,7);
        motorReset(1);
        motorReset(2);
          break;
      case 28:
        wipe(1)
        draw(1,2);
        draw(2,8);
        motorReset(1);
        motorReset(2);
          break;
      case 29:
        wipe(1)
        draw(1,2);
        draw(2,9);
        motorReset(1);
        motorReset(2);
          break;
      case 30:
        wipe(1)
        draw(1,3);
        draw(2,0);
        motorReset(1);
        motorReset(2);
          break;
      case 31:
        wipe(1)
        draw(1,3);
        draw(2,1);
        motorReset(1);
        motorReset(2);
          break;
      case 32:
        wipe(1)
        draw(1,3);
        draw(2,2);
        motorReset(1);
        motorReset(2);
          break;
      case 33:
        wipe(1)
        draw(1,3);
        draw(2,3);
        motorReset(1);
        motorReset(2);
          break;
      case 34:
        wipe(1)
        draw(1,3);
        draw(2,4);
        motorReset(1);
        motorReset(2);
          break;
      case 35:
        wipe(1)
        draw(1,3);
        draw(2,5);
        motorReset(1);
        motorReset(2);
          break;
      case 36:
        wipe(1)
        draw(1,3);
        draw(2,6);
        motorReset(1);
        motorReset(2);
          break;
      case 37:
        wipe(1)
        draw(1,3);
        draw(2,7);
        motorReset(1);
        motorReset(2);
          break;
      case 38:
        wipe(1)
        draw(1,3);
        draw(2,8);
        motorReset(1);
        motorReset(2);
          break;
      case 39:
        wipe(1)
        draw(1,3);
        draw(2,9);
        motorReset(1);
        motorReset(2);
          break;
      case 40:
        wipe(1)
        draw(1,4);
        draw(2,0);
        motorReset(1);
        motorReset(2);
          break;
      case 41:
        wipe(1)
        draw(1,4);
        draw(2,1);
        motorReset(1);
        motorReset(2);
          break;
      case 42:
        wipe(1)
        draw(1,4);
        draw(2,2);
        motorReset(1);
        motorReset(2);
          break;
      case 43:
        wipe(1)
        draw(1,4);
        draw(2,3);
        motorReset(1);
        motorReset(2);
          break;
      case 44:
        wipe(1)
        draw(1,4);
        draw(2,4);
        motorReset(1);
        motorReset(2);
          break;
      case 45:
        wipe(1)
        draw(1,4);
        draw(2,5);
        motorReset(1);
        motorReset(2);
          break;
      case 46:
        wipe(1)
        draw(1,4);
        draw(2,6);
        motorReset(1);
        motorReset(2);
          break;
      case 47:
        wipe(1)
        draw(1,4);
        draw(2,7);
        motorReset(1);
        motorReset(2);
          break;
      case 48:
        wipe(1)
        draw(1,4);
        draw(2,8);
        motorReset(1);
        motorReset(2);
          break;
      case 49:
        wipe(1)
        draw(1,4);
        draw(2,9);
        motorReset(1);
        motorReset(2);
          break;
      case 50:
        wipe(1)
        draw(1,5);
        draw(2,0);
        motorReset(1);
        motorReset(2);
          break;
      case 51:
        wipe(1)
        draw(1,5);
        draw(2,1);
        motorReset(1);
        motorReset(2);
          break;
      case 52:
        wipe(1)
        draw(1,5);
        draw(2,2);
        motorReset(1);
        motorReset(2);
          break;
      case 53:
        wipe(1)
        draw(1,5);
        draw(2,3);
        motorReset(1);
        motorReset(2);
          break;
      case 54:
        wipe(1)
        draw(1,5);
        draw(2,4);
        motorReset(1);
        motorReset(2);
          break;
      case 55:
        wipe(1)
        draw(1,5);
        draw(2,5);
        motorReset(1);
        motorReset(2);
          break;
      case 56:
        wipe(1)
        draw(1,5);
        draw(2,6);
        motorReset(1);
        motorReset(2);
          break;
      case 57:
        wipe(1)
        draw(1,5);
        draw(2,7);
        motorReset(1);
        motorReset(2);
          break;
      case 58:
        wipe(1)
        draw(1,5);
        draw(2,8);
        motorReset(1);
        motorReset(2);
          break;
      case 59:
        wipe(1)
        draw(1,5);
        draw(2,9);
        motorReset(1);
        motorReset(2);
          break;
      default:
          break;
    }
    
  if(h != ph) {      
    switch (h) {
      case 0:
        draw(3,0);
        draw(4,0);
        motorReset(1);
        motorReset(2);
          break;
      case 1:
        draw(3,0);
        draw(4,1);
        motorReset(1);
        motorReset(2);
          break;
      case 2:
        draw(3,0);
        draw(4,2);
        motorReset(1);
        motorReset(2);
          break;
      case 3:
        draw(3,0);
        draw(4,3);
        motorReset(1);
        motorReset(2);
          break;
      case 4:
        
        draw(3,0);
        draw(4,4);
        motorReset(1);
        motorReset(2);
          break;
      case 5:
        draw(3,0);
        draw(4,5);
        motorReset(1);
        motorReset(2);
          break;
      case 6:
        draw(3,0);
        draw(4,6);
        motorReset(1);
        motorReset(2);
          break;
      case 7:
        draw(3,0);
        draw(4,7);
        motorReset(1);
        motorReset(2);
          break;
      case 8:
        draw(3,0);
        draw(4,8);
        motorReset(1);
        motorReset(2);
          break;
      case 9:
        draw(3,0);
        draw(4,9);
        motorReset(1);
        motorReset(2);
          break;
      case 10:
        draw(3,1);
        draw(4,0);
        motorReset(1);
        motorReset(2);
          break;
      case 11:
        draw(3,1);
        draw(4,1);
        motorReset(1);
        motorReset(2);
          break;
      case 12:
        draw(3,1);
        draw(4,2);
        motorReset(1);
        motorReset(2);
          break;
      case 13:
        draw(3,1);
        draw(4,3);
        motorReset(1);
        motorReset(2);
          break;
      case 14:
        draw(3,1);
        draw(4,4);
        motorReset(1);
        motorReset(2);
          break;
      case 15:
        draw(3,1);
        draw(4,5);
        motorReset(1);
        motorReset(2);
          break;
      case 16:
        draw(3,1);
        draw(4,6);
        motorReset(1);
        motorReset(2);
          break;
      case 17:
        draw(3,1);
        draw(4,7);
        motorReset(1);
        motorReset(2);
          break;
      case 18:
        draw(3,1);
        draw(4,8);
        motorReset(1);
        motorReset(2);
          break;
      case 19:
        draw(3,1);
        draw(4,9);
        motorReset(1);
        motorReset(2);
          break;
      case 20:
        draw(3,2);
        draw(4,0);
        motorReset(1);
        motorReset(2);
          break;
      case 21:
        draw(3,2);
        draw(4,1);
        motorReset(1);
        motorReset(2);
          break;
      case 22:
        draw(3,2);
        draw(4,2);
        motorReset(1);
        motorReset(2);
          break;
      case 23:
        draw(3,2);
        draw(4,3);
        motorReset(1);
        motorReset(2);
          break;
      default;
          break;
      }
    }   
  }