
#include <Keypad.h>
//creates four columns and four rows

const byte row = 4;
const byte columns = 4;
//creates an array representing the keypad
char num_keys[row][columns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  
};
// rows and columns must be attached to certain pins

byte rowPins[row] = {5, 4, 3, 2}; 
byte colPins[columns] = {9, 7, 8, 6}; 
//maps the keypad and keys together
Keypad keypad = Keypad( makeKeymap(num_keys), rowPins, colPins, row, columns );
//serial output setup
void setup(){
  Serial.begin(9600);
}
  //serial output
void loop(){
  char num_key = keypad.getKey();
  
  if (num_key){
    Serial.println(num_key);
  }
}
