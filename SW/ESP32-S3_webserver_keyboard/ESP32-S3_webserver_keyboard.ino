/* Webserver to emulate keyboard on USB port of ESP32-S3
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "USB.h"
#include "USBHIDKeyboard.h"
#include "page.h"

const char *host = "espkeyboard"; // Connect to http://espkeyboard.local

const char ssid[] = "YourSSID";		// your network SSID (name)
const char pass[] = "YourPassword"; // your network password

// Set web server port number to 80
WebServer server(80);

USBHIDKeyboard Keyboard;

void handleRoot()
{
	server.send_P(200, "text/html", index_html);
}

void handleSubmit()
{
	if (server.argName(0) == "Input")
	{
		char text[100] = {0};
		Keyboard.print(server.arg(0));
	}
	if (server.argName(1) == "Enter")
	{
		Keyboard.println();
	}
	handleRoot();
}

void handleNotFound()
{
	String message = "Error\n\n";
	message += "URI: ";
	message += server.uri();
	message += "\nMethod: ";
	message += (server.method() == HTTP_GET) ? "GET" : "POST";
	message += "\nArguments: ";
	message += server.args();
	message += "\n";
	for (uint8_t i = 0; i < server.args(); i++)
	{
		message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
	}
	server.send(404, "text/plain", message);
}

void DNS_setup()
{
	if (MDNS.begin(host))
	{
		MDNS.addService("http", "tcp", 80);
		Serial.println("MDNS responder started");
		Serial.print("You can now connect to http://");
		Serial.print(host);
		Serial.println(".local");
	}
}

void WifiSetup()
{
	Serial.print("Connecting to...");
	Serial.println(ssid);
	WiFi.begin(ssid, pass);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(1000);
		Serial.println(".");
	}
	Serial.println("");
}

void setup()
{
	Serial.begin(115200);

	WifiSetup();

	DNS_setup();

	server.on("/", handleRoot); // Main page

	server.on("/get", handleSubmit); // Function done on GET request

	server.onNotFound(handleNotFound); // Function done when hangle is not found

	server.begin();
	Serial.println("HTTP server started");

	Keyboard.begin();
	USB.begin();
}

void loop()
{
	server.handleClient();
	delay(2); // allow the cpu to switch to other tasks
}