#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define DHT sensor type and pin
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address can vary

// Timer for sending data (every 5 seconds)
unsigned long previousMillis = 0;
const long interval = 10000;  // 5 seconds

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned long currentMillis = millis();
  
  
    
    // Read temperature and humidity
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    
    // Check if any reads failed
    /*if (isnan(humidity) || isnan(temperature)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Error reading");
      lcd.setCursor(0, 1);
      lcd.print("sensor data");
      return;
    }*/

    // Send data to Serial (to be captured by Python script)
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" *C");
    }

    // Display data on the LCD
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
    
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print(" %");
}
