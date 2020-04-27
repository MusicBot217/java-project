void setup(void)
 {
  startFingerprintSensor();
  display.begin();
  displayLockScreen(); 
}


void loop() {

  FPID = getFPID(); //FPID represents fingerprintID
  delay(40);
  if(FPID == 1)
  {
    display.drawBitmap(30,35,icon,60,65,GREEN);
    delay(3000);
    displayUnlockedScreen();
    displaySAM();
    delay(4000);
    display.fillScreen(BLACK);
    displayLockScreen();
  }
  if(fingerprintID == 2)
  {
    display.drawBitmap(30,35,icon,60,65,GREEN);
    delay(3000);
    displayUnlockedScreen();
    displayMOHAMMAD();
    delay(4000);
    display.fillScreen(BLACK);
    displayLockScreen();
  }
  if(fingerprintID == 3)
  {
    display.drawBitmap(30,35,icon,60,65,GREEN);
    delay(3000);
    displayUnlockedScreen();
    displayNAHI();
    delay(4000);
    display.fillScreen(BLACK);
    displayLockScreen();
  }
  if(fingerprintID == 4)
  {
    display.drawBitmap(30,35,icon,60,65,GREEN);
    delay(3000);
    displayUnlockedScreen();
    displayALEXI();
    delay(4000);
    display.fillScreen(BLACK);
    displayLockScreen();
  }
  if(fingerprintID == 5)
  {
    display.drawBitmap(30,35,icon,60,65,GREEN);
    delay(3000);
    displayUnlockedScreen();
    displayDALTON();
    delay(4000);
    display.fillScreen(BLACK);
    displayLockScreen();
  }
}
