#include <ArduinoOSCWiFi.h>
#include <U8g2lib.h>
#include <Wire.h>

const char* ssid = "BELL397";
const char* pwd = "3FC3F43A4E65";

const char* sendIPaddress = "192.168.2.17.";
const char* myMessageTag = "/arduino1";
const int mySendPort = 8000;
const int myReceivePort = 9000;


int inMouseX;
int inMouseY;

U8G2_SH1106_128X64_NONAME_F_HW_I2C oled(U8G2_R0, /* reset=*/U8X8_PIN_NONE);



void setup() {
    Serial.begin(9600);

  //initialize the oled object and clear the buffer
  oled.begin();
  oled.clearBuffer();  // clear the internal memory
  oled.setFont(u8g2_font_helvB08_tr);

   oled.drawStr(0,10,"FILL ME!!");

  
    WiFi.begin(ssid, pwd);

    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.print(".");
    oled.sendBuffer();

        delay(500);
    }

  
    oled.sendBuffer();


OscWiFi.subscribe(myReceivePort, "/person1", inMouseX, inMouseY);

}

void loop() 
{
    
    
 

oled.drawDisc(inMouseX/10,inMouseY/10,5);


  
  
  oled.sendBuffer();  
  Serial.print(inMouseX);
  Serial.print('\t');  
  Serial.println(inMouseY);  
    
    OscWiFi.update();  // should be called to receive + send osc
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc

}


String IpAddress2String(const IPAddress& address)
{
  return String() + address[0] + "." + address[1] + "." + address[2] + "." + address[3];
}

