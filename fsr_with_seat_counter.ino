bool seat_occupied = false;
int seat_counter = 0;      // Counter of the number of times the seat is used
bool buzzing     = false;  // Indicates whether piezo buzzer is active

const int seat_lim = 3;   // Number of times seat can be used (will begin to buzz ON the nth sit)
const int FSR_PIN  = A0;  // The FSR and 10K pulldown are connected to a0
const int BUZZ_PIN = 8;   // Piezo buzzer
const int LED_PIN1 = 9;   // Red
const int LED_PIN2 = 10;  // Blue
const int LED_PIN3 = 11;  // Green

void setup() {
  Serial.begin(9600);

  pinMode(FSR_PIN,  INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);

  analogWrite(LED_PIN1, 0); // Set LED to green initially
  analogWrite(LED_PIN2, 255);
  analogWrite(LED_PIN3, 0);
}

void loop() {
  bool weight_detected = analogRead(FSR_PIN) >= 400; // Get analog reading from the FSR resistor divider

  if (seat_counter >= seat_lim && weight_detected) {
    if (!buzzing && !seat_occupied) {
      tone(BUZZ_PIN, 200);
      buzzing = true;      
      seat_counter++;
      Serial.print("Seat counter: ");
      Serial.println(seat_counter);      
    }
  }

  else if (weight_detected && !seat_occupied) {
    analogWrite(LED_PIN1, 255); // Set LED to red
    analogWrite(LED_PIN2, 0);
    seat_counter++;
    Serial.print("Seat counter: ");
    Serial.println(seat_counter);
    seat_occupied = true;
  } 
  
  else if (!weight_detected) {
    seat_occupied = false;
    if (buzzing) {
      noTone(BUZZ_PIN);
      buzzing = false;
    }
    else if (seat_counter < seat_lim) { 
      int red_quant = 255;
      while (red_quant > 0) { // Slowly fade-out the red pin
        red_quant--;
        analogWrite(LED_PIN1, red_quant);
        delay(10);

        if (red_quant == 0)
          analogWrite(LED_PIN2, 255); // Set LED to green
      }
    }
  }
  delay(1000);
}
