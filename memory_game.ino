int buttons[] = {13, 12, 11}; 
int leds[] = {4, 3, 2};

int memory[11];
int length;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 3; i++)
    pinMode(buttons[i], INPUT_PULLUP);
  for(int i = 0; i < 3; i++)
    pinMode(leds[i], OUTPUT);
  
  randomSeed(analogRead(0));
  generateGame();
}

void loop() {
  showSequence();
  
  if(checkInput()) {
    flashSuccess();
    delay(2000);
    generateGame();
  } else {
    flashFailure();
    delay(2000);
    generateGame();
  }
}

void generateGame(){
  length = random(1, 11);
  
  for(int i = 0; i < length; i++) {
    memory[i] = random(0, 3);
  }
  
  Serial.print("Length: ");
  Serial.println(length);
  Serial.print("Sequence: ");
  for(int i = 0; i < length; i++) {
    Serial.print(memory[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void showSequence() {
  delay(1000);
  for(int i = 0; i < length; i++) {
    digitalWrite(leds[memory[i]], HIGH);
    delay(500);
    digitalWrite(leds[memory[i]], LOW);
    delay(300);
  }
}

bool checkInput() {
  for(int i = 0; i < length; i++) {
    int pressed = waitForButton();
    
    Serial.print("Button pressed: ");
    Serial.print(pressed);
    Serial.print(" Expected: ");
    Serial.println(memory[i]);
    
    if(pressed != memory[i]) {
      return false;
    }
    
    digitalWrite(leds[pressed], HIGH);
    delay(300);
    digitalWrite(leds[pressed], LOW);
    delay(200);
  }
  return true;
}

int waitForButton() {
  while(true) {
    for(int i = 0; i < 3; i++) {
      if(digitalRead(buttons[i]) == LOW) {
        delay(50);
        while(digitalRead(buttons[i]) == LOW);
        return i;
      }
    }
  }
}

void flashSuccess() {
  for(int j = 0; j < 3; j++) {
    for(int i = 0; i < 3; i++)
      digitalWrite(leds[i], HIGH);
    delay(200);
    for(int i = 0; i < 3; i++)
      digitalWrite(leds[i], LOW);
    delay(200);
  }
}

void flashFailure() {
  for(int j = 0; j < 5; j++) {
    for(int i = 0; i < 3; i++)
      digitalWrite(leds[i], HIGH);
    delay(100);
    for(int i = 0; i < 3; i++)
      digitalWrite(leds[i], LOW);
    delay(100);
  }
}