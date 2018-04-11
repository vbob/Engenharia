#include <Arduino.h>
#include <TM1637Display.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define CLOCK 16       // TM1637 Clock Pin
#define DISPLAY 5      // TM1637 DIO Pin
#define INCREMENT D4   // Increment Count Buton Pin
#define RESET D0       // Reset Count Button Pint
#define WIFION_BTN D2  // Start WiFi Server Pin
#define WIFION_LED D14 // WiFi On LED

// Starts the Display
TM1637Display display(CLOCK, DISPLAY);

// Counter
int value = 0;

// Server Information
const char *ssid = "Contador";
const char *password = "123";
int wifiOn = 0;
ESP8266WebServer server(80);

void setup()
{
    pinMode(INCREMENT, INPUT);
    pinMode(RESET, INPUT);
    pinMode(WIFION_BTN, INPUT);
    pinMode(WIFION_LED, OUTPUT);
}

void handleRoot()
{
    server.send(200, "text/html", "<h1>You are connected</h1>");
}

void loop()
{
    if (digitalState(INCREMENT))
    {
        value++;
        display.showNumberDec(value);
        while (digitalState(INCREMENT))
        {
        }
    }
    if (digitalState(RESET))
    {
        value = 0;
        display.showNumberDec(value);
        while (digitalState(INCREMENT))
        {
        }
    }
    if (digitalState(WIFION_BTN))
    {
        if (!wifiOn)
        {
            digitalWrite(WIFION_LED, HIGH);
            WiFi.forceSleepWake();
            WiFi.softAP(ssid, password);
            IPAddress myIP = WiFi.softAPIP();
            server.on("/", handleRoot);
            server.begin();
        }
        else
        {
            digitalWrite(WIFION_LED, LOW);
            WiFi.disconnect();
            WiFi.mode(WIFI_OFF);
            WiFi.forceSleepBegin();
        }
    }

    if (wifiOn)
    {
        server.handleClient();
    }
}
