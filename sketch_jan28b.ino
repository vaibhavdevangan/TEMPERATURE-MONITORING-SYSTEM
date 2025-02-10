 

#define sensor_pin 34    // Pin,to which the Sensor is connected 

int n_res = 10000;       //Nominal resistance at 25⁰C 
int n_temp = 25;         // temperature for nominal resistance (almost always 25⁰ C) 
int beta = 3950;         // The beta coefficient or the B value of the thermistor (usually 3000-4000) check the datasheet for the accurate value. 
int Rref = 10000;        //Value of  resistor used for the voltage divider 

void setup() { 
 
  Serial.begin(9600); 

} 
void loop(void) { 

  float average; 
  average = analogRead(sensor_pin); 

  // Calculate NTC resistance 
  average = 4095 / average - 1; 
  average = Rref / average; 

  float temperature; 
  temperature = average / n_res;     // (R/Ro) 
  temperature = log(temperature);                 // ln(R/Ro) 
  temperature /= beta;                   // 1/B * ln(R/Ro) 
  temperature += 1.0 / (n_temp + 273.15); // + (1/To) 
  temperature = 1.0 / temperature;                // Invert 
  temperature -= 273.15;                          // convert absolute temp to C 
  Serial.print("Temperature "); 
  Serial.print(temperature); 
  Serial.println(" *C"); 

   delay(2000); 
}
