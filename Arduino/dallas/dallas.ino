
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define Resolution 9
#define HIGH_CELSIUS 25
#define LOW_CELSIUS 20

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress deviceaddress;
int celsius;

void setup(void)
{
      Serial.begin(115200);
      Serial.println("Dallas Temperature IC Control Library Demo");

      sensors.begin();
      sensors.setResolution(Resolution);

      if(!sensors.getAddress(deviceaddress,0))//센서 주소 오류
      {
            Serial.println("Can't get deviceaddress");
      }
      sensors.setHighAlarmTemp(deviceaddress, HIGH_CELSIUS);
      sensors.setLowAlarmTemp(deviceaddress, LOW_CELSIUS);
}

void loop(void)
{
      Serial.print("Requesting temperatures...");
      sensors.requestTemperatures(); // Send the command to get temperatures
      Serial.println("DONE");
      Serial.print("Temperature for the device 1 (index 0) is: ");
      Serial.println(sensors.getTempCByIndex(0));

      Serial.print("Dallas Temperature Resolution : ");
      Serial.print(sensors.getResolution());
      Serial.print("bit");
      Serial.println();

      Serial.print("High Alarm Temperature : ");
      Serial.print(sensors.getHighAlarmTemp(deviceaddress));
      Serial.println();

      Serial.print("Low Alarm Temperature : ");
      Serial.print(sensors.getLowAlarmTemp(deviceaddress));
      Serial.println();
      
      Serial.print("Within Setting Alarm Range : ");
      Serial.println(sensors.hasAlarm());
      Serial.println();
}