#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR_PIN 11  // Change if needed

OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);

DeviceAddress tempDeviceAddress;

void setup() {
  Serial.begin(115200);
  sensors.begin();

  Serial.println("Scanning for DS18B20 sensors...");
  Serial.print("Number of sensors found: ");
  Serial.println(sensors.getDeviceCount());
  Serial.println();
}

void loop() {

  // Ask all sensors to measure temperature
  sensors.requestTemperatures();

  for (uint8_t i = 0; i < sensors.getDeviceCount(); i++) {
    if (sensors.getAddress(tempDeviceAddress, i)) {

      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(" ID: {");

      for (uint8_t j = 0; j < 8; j++) {
        Serial.print("0x");
        if (tempDeviceAddress[j] < 16) Serial.print("0");
        Serial.print(tempDeviceAddress[j], HEX);
        if (j < 7) Serial.print(", ");
      }
      Serial.print("}");

      // Read temperature of this sensor
      float tempC = sensors.getTempC(tempDeviceAddress);

      Serial.print("  |  Temperature: ");

      if (tempC == DEVICE_DISCONNECTED_C) {
        Serial.println("Error");
      } else {
        Serial.print(tempC);
        Serial.println(" °C");
      }

    } else {
      Serial.print("Unable to find address for sensor ");
      Serial.println(i);
    }
  }

  Serial.println("--------------------------------");
  delay(1000); // read every 5 seconds
}
