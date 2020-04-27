


#include <Adafruit_Fingerprint.h>


//optical pin outs
SoftwareSerial pins(10, 11);
//fingerprint is set to the new check
Adafruit_Fingerprint new_check = Adafruit_Fingerprint(&pins);

void setup()  {
  //begins outputing to serial monitor
  Serial.begin(9600);
  while (!Serial); 
  delay(100);
  Serial.println("\n\nFingerprint detection testing");

  //checks for the sensor and outputs whether found or not
  new_check.begin(57600);
  delay(5);
  if (new_check.verifyPassword()) {
    Serial.println("Sensor found");
  } else {
    Serial.println("Sensor not found:(");
    while (1) { delay(1); }
  }
  //checks how many templates exist
  new_check.getTemplateCount();
  Serial.print("there are  "); 
  Serial.print(new_check.templateCount); 
  Serial.println(" acquired fingerprints");
  //time for some user input
  Serial.println("Place finger on tester");
}

void loop()                    
{
  findNewFingerprint();
  delay(50);            
}
//checks to see if the fingerprint exists in the system or not
//also displays why it wasnt found if it can be discerned
uint8_t getFingerprintID() {
  uint8_t x= new_check.getImage();
  switch (x) {
    case FINGERPRINT_OK:
      Serial.println("Aquired image");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("Finger Does Not Exist");
      return x;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Problem Communicating");
      return x;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Problem taking image");
      return x;
    default:
      Serial.println("error not found");
      return x;
  }

  

  x= new_check.image2Tz();
  switch (x) {
    case FINGERPRINT_OK:
      Serial.println("Finger acquired");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Finger smudged");
      return x;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error not found");
      return x;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("is this a fingerprint?");
      return x;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("is this a fingerprint?");
      return x;
    default:
      Serial.println("error not found");
      return x;
  }
  
//searches for image and displays whether or not t is foud
  x= new_check.fingerFastSearch();
  if (x== FINGERPRINT_OK) {
    Serial.println("We have a match");
  } else if (x== FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("error communicating");
    return x;
  } else if (x== FINGERPRINT_NOTFOUND) {
    Serial.println("we don't have a match");
    return x;
  } else {
    Serial.println("unfounded error");
    return x;
  }   
  // makes a targeted statement and displays how many checks were made on the fingerprint 
  Serial.print("We found You "); Serial.print(new_check.fingerID); 
  Serial.print(" with a certainty counted to "); Serial.println(new_check.confidence); 

  return new_check.fingerID;
}
//returns for image search
int findNewFingerprint() {
  uint8_t b= new_check.getImage();
  if (b!= FINGERPRINT_OK)  return -1;

  b= new_check.image2Tz();
  if (b!= FINGERPRINT_OK)  return -1;

  b= new_check.fingerFastSearch();
  if (b!= FINGERPRINT_OK)  return -1;
   
  Serial.print("We found You "); Serial.print(new_check.fingerID); 
  Serial.print(" with a certainty counted to "); Serial.println(new_check.confidence);
  return new_check.fingerID; 
}
