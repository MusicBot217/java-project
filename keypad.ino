const byte R = 4; //R represents rows
const byte C = 4; //C represents columns
char keys[R][C] = {
  {'1','2','3','A'},  //the keypad has 4 rows and 4 columns
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte RP[R] = {2, 3, 4, 5}; //RP represents row pinouts 
byte CP[C] = {6,7,8,9}; //CP represents column pinouts

Keypad keypad = Keypad( makeKeymap(keys), RP, CP, R, C );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.println(key);
  } 
}
