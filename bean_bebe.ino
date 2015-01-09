bool babyAwake = false;

void setup(){
  Serial.begin(57600);
}

void checkIfBabyAwake(){
  int16_t y = Bean.getAccelerationY();
  if(abs(y) > 100) {
    if(babyAwake) {
      return;
    }

    babyAwake = true;
  } else {
    if(!babyAwake) {
      return;
    }

    babyAwake = false;
  }

  Bean.setScratchNumber(1, babyAwake);
}

void loop(){
  checkIfBabyAwake();
  Bean.sleep(1000);
}
