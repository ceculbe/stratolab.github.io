#define BOARD_LED 18
#define RED_LED 6
#define YEL_LED 5
#define GRN_LED 4
#define USER_BTN 0

void setup() {
  pinMode(BOARD_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YEL_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(USER_BTN, INPUT);
}

void loop() {
  // normal state: light is green, no walk signal
  digitalWrite(RED_LED, LOW);  
  digitalWrite(YEL_LED, LOW);  
  digitalWrite(GRN_LED, HIGH);
  digitalWrite(BOARD_LED, LOW);
  if (digitalRead(USER_BTN) == 0){
    // when button is pressed, light changes to yellow
    digitalWrite(GRN_LED, LOW);  
    digitalWrite(YEL_LED, HIGH);  
    delay(1000);   
    // then light changes to red with walk signal on
    digitalWrite(RED_LED, HIGH);  
    digitalWrite(YEL_LED, LOW);  
    digitalWrite(BOARD_LED, HIGH);
    delay(5000);   
  }
  // then return to the top of the loop and the normal state
}
