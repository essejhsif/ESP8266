/**
 * @example ESP8266_example1.inp
 * @brief Exmple ESP8266 w/ WeeESP8266 library.
 * @author Jesse Fish <jessefish@gmail.com> 
 * @date 2015.09.13
 */
#include "ESP8266.h"
#include <SoftwareSerial.h>
 
SoftwareSerial Serial1(2,3);

#define SSID        "ssid"
#define PASSWORD    "password"

ESP8266 wifi(Serial1);

void setup(void)
{
    Serial.begin(9600);
    Serial.print("Beginning Setup...\r\n");
    Serial.print("Baud rate: 9600\r\n");

    Serial.print("FW Version: ");
    Serial.println(wifi.getVersion().c_str());
    
    
    if (wifi.setOprToStation()) {
        Serial.print("To station: OK\r\n");
    } else {
        Serial.print("To station: ERR\r\n");
    }

    Serial.print("Joining AP...\r\n");
    Serial.print("SSID: " + SSID + "\t" + "PASSWORD: " + PASSWORD + "\r\n");
    
    if (wifi.joinAP(SSID, PASSWORD)) {
        Serial.print("SUCCESS\r\n");
        Serial.print("IP: ");       
        Serial.println(wifi.getLocalIP().c_str());
    } else {
        Serial.print("FAIL\r\n");
    }
    
    Serial.print("Setup completed.\r\n");
}

void loop(void)
{
}

