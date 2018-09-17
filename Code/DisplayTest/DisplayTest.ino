/*
    Group 7 - Jonas B., Signe, Thomas T & Tim
    Mercantec - Viborg College of Technology
    17/09-2018
*/

  //First piece of code for the LCD display, tested, works.

  // Includes the LiquidCrystal Library 
  #include <LiquidCrystal.h> 

  // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
  LiquidCrystal lcd(1, 2, 4, 5, 6, 7);  

  // Initialize the LCD interface  and specifies dimensions of the display.
  void setup() { 
   lcd.begin(16,2); } 
  }
  
  void loop() { 
   // Displays text message, waits, clears, then waits.
   lcd.print("Group 7");
   delay(500); // 3 seconds delay 
   lcd.setCursor(2,1);
   lcd.print("LCD Display Test"); 
   delay(5000); 
   lcd.clear();
   delay(500);
  }
