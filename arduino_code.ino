#define THRESHOLD
#define smPin A0
int soil_moisture_level=0;

bool isLess = false;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
soil_moisture_level=analogRead(smPin);
Serial.println(soil_moisture_level);
delay(200);
}
