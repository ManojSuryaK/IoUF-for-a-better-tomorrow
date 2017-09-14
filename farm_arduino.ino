#define smPin A0     //soil moisture input pin
#define lumPin A2    //ldr sensor input pin
#define tempPin A4   //temperature sensor input pin
#define light 13     //light output
int soil_moisture_level=0;//init the level
int light_threshold=700;//threshold that can be customized for any plant
int luminosity=0;//init the luminosity level
float temperature=0;

void setup() {
  Serial.begin(115200); //Serial object
  pinMode(light,OUTPUT);//init
  digitalWrite(light,LOW);//init
}

void soil_moisture_send()  //function to send soil moisture data serially to the main CU
{
  soil_moisture_level=analogRead(smPin);//ADC
  Serial.print("s");
  Serial.print("\t");
  Serial.print(soil_moisture_level);  //send in a pattern "s level"
  Serial.print("\n");
}

void luminosity_check()  //function to send ambient lighting conditions serially to the main CU
{
  luminosity=analogRead(lumPin);//ADC
  if (luminosity>light_threshold){//check for threshold(dim light or night)
    digitalWrite(light,HIGH);//Provide lighting for artificial photosynthesis
  }
  else{
    digitalWrite(light,LOW);
  }
  Serial.print("l");
  Serial.print("\t");
  Serial.print(luminosity);
  Serial.print("\n");//send in a pattern "l luminosity"
}

void temperature_send()  //sending temperature of the environment serially
{
  temperature=(analogRead(tempPin)*500)/1023;//calc temperature in *C from ADC
  Serial.print("t");
  Serial.print("\t");
  Serial.print(temperature);
  Serial.print("\n");//send in a pattern "t temperature"
}
void loop() {
  soil_moisture_send();//call to func soil_moisture_send()
  delay(10);
  luminosity_check();//call to func luminosity_check()
  delay(10);
  temperature_send();//call to func temperature_send()
  delay(100);//delay to stabilise stuff
}
