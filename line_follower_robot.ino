#include <LiquidCrystal_I2C.h> // liquid crystal library.

LiquidCrystal_I2C lcd(0x27, 16, 2); // specifies how to reference the lcd and it's characteristics.

// sets the motor pins to their respective pins.
int motor1pin1 = 1;
int motor1pin2 = 2;
int motor2pin1 = 3;
int motor2pin2 = 4;
int enb = 9;

int ir_left_pin = 5; // sets left ir sensor to pin 5. (has black tape)+
int ir_right_pin = 6; // sets right ir sensor to pin 6.
int lcd_pin = 7; // sets lcd to pin 7.
int lcd_prev = 99; // helps to update the lcd's previous state.
int lcd_cur = 100; // helps to update the lcd's current state.

void setup() {
  // configure the motor pins as output.
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(enb, OUTPUT);

  lcd.init(); // initializes lcd.
  lcd.backlight(); // turn on backlight.
  pinMode(lcd_pin, OUTPUT); // lcd initialized as output.
  lcd.setCursor(0, 0); // set cursor at top left.
  lcd.print ("Robot State:    "); // prints the written statement onto the lcd display.
  
  pinMode(ir_left_pin, INPUT); // left ir sensor initialized as input.
  pinMode(ir_right_pin, INPUT); // right ir sensor initialized as input.

}

void loop() {
  digitalWrite(enb, HIGH);
  
  // create a current and previous state of the lcd so that the lcd only changes
  // when the value of both are not equal.
  lcd_prev = lcd_cur;
  int ir_left = digitalRead(ir_left_pin);
  int ir_right = digitalRead(ir_right_pin);

  // if both sensors detect a white surface, move forward and print "FORWARD".
  if (ir_left == 0 && ir_right == 0) {
    lcd_cur = 1;
    
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    if (lcd_prev != lcd_cur) {
      lcd.setCursor(0, 1);
      lcd.print("FORWARD         ");
      delay(10);
    }
  }
   // if only the right sensor detects a black surface, move to the right and print "RIGHT".
   else if (ir_left == 1 && ir_right == 0) {
    lcd_cur = 2;
    
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    if (lcd_prev != lcd_cur) {
      lcd.setCursor(0, 1);
      lcd.print("RIGHT           ");
      delay(10);
    }
   }
   // if only the left sensor detects a black surface, move to the left and print "LEFT".
   else if (ir_left == 0 && ir_right == 1) {
    lcd_cur = 3;
    
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    if (lcd_prev != lcd_cur) {
      lcd.setCursor(0, 1);
      lcd.print("LEFT            ");
      delay(10);
    }    
   }
   // if both sensors detect a black surface, stop the robot and print "STOP".
   else {
    lcd_cur = 4;
    
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    if (lcd_prev != lcd_cur) {
      lcd.setCursor(0, 1);
      lcd.print("STOP            ");
      delay(10);
    }
   }
  }
