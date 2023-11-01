

/*

void setup() {
  // set up the LCD's number of columns and rows:
 
  // Print a message to the LCD.

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):


                        
}



void setup()
{

}
void loop() 
{
 
}
*/

//servo
#include <Servo.h>


  int buzzerPin = 7;
Servo myservo;
Servo mys; 
int pos = 0; 
 
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");  
  mlx.begin();

   lcd.begin(16, 2);
 myservo.attach(9);
 mys.attach(10);
  pinMode(buzzerPin, OUTPUT);
  

   
}
void loop() {
 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  delay(500);
  float temp = mlx.readObjectTempC();

  if(temp<29){
    lcd.setCursor(0, 0);
     lcd.print(temp);
     lcd.print("cold body");
      lcd.print(millis() / 1000);
  }  

  if(temp>=29.99 && temp <38){

    lcd.setCursor(0, 0);
    lcd.print("temp is ok");
    lcd.print(temp);
  lcd.print(millis() / 1000);
  //servo
     for (pos = 0; pos <= 90; pos += 1) {
    // in steps of 1 degree
    myservo.write(pos); 
       mys.write(pos);            
    delay(60);                       
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);  
    mys.write(pos);          
    delay(60);    
                       
  } 

   } 
  
  if (temp>38){
  
      
    lcd.setCursor(0, 0);
    lcd.print("temp is hot");
  lcd.print(millis() / 1000); 
   digitalWrite(buzzerPin, HIGH);   
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  delay(50);


  }
}

/*


 void setup{


}
void loop{
   for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);             
    delay(60);                       
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);            
    delay(60);                       
  }
}*/