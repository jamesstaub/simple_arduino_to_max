// Flex sensor test program

// Mike Grusin, SFE, 2011
// This program is free, use it however you wish!

// HARDWARE:
// Make the following connections between the Arduino and the flex sensor
// Note that the flex sensor pins are interchangeable

// Sensor pin - GND
// Sensor pin - Analog In 0, with 10K resistor to +5V

// INSTRUCTIONS:
// Upload this sketch to your Arduino, then activate the Serial Monitor
// (set the Serial Monitor to 9600 baud)

//#include <Firmata.h>


/*==============================================================================
 * GLOBAL VARIABLES
 *============================================================================*/
 
int analogInputsToReport = 0; // bitwise array to store pin reporting
int analogPin = 0; // counter for reading analog pins
/* timer variables */
//unsigned long currentMillis;     // store the current value from millis()
//unsigned long previousMillis;    // for comparison with currentMillis



/*==============================================================================
 * FUNCTIONS
 *============================================================================*/


void setup()
{
    // initialize serial communications
    Serial.begin(9600); 

}

void loop()
{
    int pressure, light;

    // read the voltage from the voltage divider (sensor plus resistor)
    pressure = analogRead(0);
    light = analogRead(1);

//   scale and clip values to be 3 digets, allowing for easy parsing in Max
    int pressureVal = map(pressure, 888, 0, 100, 999);
    pressureVal = constrain(pressureVal, 100, 999);
    
    int lightVal = map(light, 0, 256, 100, 999);
    lightVal = constrain(lightVal, 100, 999);

    // print out the result
    Serial.print("pressure ");
    
    Serial.print(pressureVal,DEC);
    
    Serial.print(" light ");
    
    Serial.println(lightVal, DEC);

    // pause before taking the next reading
    delay(100); 
}


