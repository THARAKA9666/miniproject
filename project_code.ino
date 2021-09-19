#include <Adafruit_GFX.h>

#include <gfxfont.h>

#include <TouchScreen.h>

#include<MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;


#define LCD_CS A3

#define LCD_CD A2

#define LCD_WR A1

#define LCD_RD A0

#define LCD_RESET A4


#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin



TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);


#define TS_MINX 20

#define TS_MINY 120

#define TS_MAXX 200

#define TS_MAXY 940


#define  BLACK   0x0000

#define BLUE    0x001F

#define RED     0xF800

#define GREEN   0x07E0

#define CYAN    0x07FF

#define MAGENTA 0xF81F

#define YELLOW  0xFFE0

#define WHITE   0xFFFF


uint16_t g_identifier;

void setup(void) 
{

  Serial.begin(9600);

  pinMode(13, OUTPUT);

  pinMode(12, OUTPUT);
  
  pinMode(19, OUTPUT);
  
  tft.reset();

  delay(10);

//Making a home automation system using 2.4 inch TFT touch display controlling led interfacing with Arduino uno - KT900
//2.4" TFT LCD Shield touch screen module for Arduino Uno


  g_identifier = tft.readID(); // some times tft.begin(0x9341); will also used but for tft like this won't work with this command.(www.mcufriend.com)


  tft.begin(g_identifier);
  tft.fillScreen(WHITE);
  tft.setRotation(0);
  tft.setTextSize(3);
  tft.setTextColor(BLACK);
  tft.setCursor(20, 15);
  tft.println("LIGHT - FAN");

  //tft.setRotation(0);

  tft.setTextSize(3);
  tft.setTextColor(BLUE);
  tft.setCursor(10, 240);
  tft.println("2.4' TFT LCD ");

  tft.setTextSize(2);
  tft.setTextColor(BLUE);
  tft.setCursor(10, 280);
  tft.println("Touch Screen Home");

  //ON-BUTTONS-TEMPLATE
  tft.fillCircle(40, 90, 25, GREEN);   // tft.sahpe( x, y, w, h, colour)
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.setCursor(10, 83);
  tft.println("  1");

  tft.fillCircle(40, 150, 25, GREEN);   // tft.sahpe( x, y, w, h, colour)
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.setCursor(10, 143);
  tft.println("  2");
  
  tft.fillCircle(40, 210, 25, GREEN);   // tft.sahpe( x, y, w, h, colour)
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.setCursor(10, 200);
  tft.println("  3");

  //OFF-BUTTONS-TEMPLATE

  tft.fillCircle(120, 90, 25, RED);
  tft.setTextColor(BLACK);
  tft.setCursor(90, 83);
  tft.println("  1");

  tft.fillCircle(120, 150, 25, RED);
  tft.setTextColor(BLACK);
  tft.setCursor(90, 143);
  tft.println("  2");

  tft.fillCircle(120, 210, 25, RED);
  tft.setTextColor(BLACK);
  tft.setCursor(90, 200);
  tft.println("  3");
}


#define MINPRESSURE 10

#define MAXPRESSURE 1000


void loop()

{


  TSPoint p = ts.getPoint();

  pinMode(XM, OUTPUT);

  pinMode(YP, OUTPUT);

  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);

  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);


  if (p.z > MINPRESSURE && p.z < MAXPRESSURE)

  {


  }


  if (p.z > 0)

  {

    //this part will read the x,y coordinated of your tft display brought from (www.mcufriend.com)

    Serial.print("\tY = "); Serial.print(p.y);

    Serial.print("\tX = "); Serial.print(p.x);

    Serial.print("\tPressure = "); Serial.println(p.z);

  }

  tft.setTextSize(2);

  if (p.y > 50 && p.y < 100 && p.x > 200 && p.x < 500)
  {
  digitalWrite(13, HIGH);
  tft.setTextColor(WHITE);tft.setCursor(160, 80);
  tft.println("1 OFF");
  tft.setCursor(160, 80);tft.setTextColor(GREEN);
  tft.println("1 ON");
  delay(1000);
  }

  if (p.y > 50 && p.y < 100 && p.x > 600 && p.x < 1000)
  {
  digitalWrite(13, LOW);
  tft.setTextColor(WHITE);tft.setCursor(160, 80);
  tft.println("1 ON");
  tft.setCursor(160, 80);tft.setTextColor(RED);
  tft.println("1 OFF");
  delay(1000);
  }

  if (p.y > 100 && p.y < 150 && p.x > 200 && p.x < 500)
  {
  digitalWrite(12, HIGH);
  tft.setCursor(160, 143);tft.setTextColor(WHITE);
  tft.println("2 OFF");
  tft.setCursor(160, 143);tft.setTextColor(GREEN);
  tft.println("2 ON");
  delay(1000);
  }

  if (p.y > 100 && p.y < 150 && p.x > 600 && p.x < 1000)
  {
  digitalWrite(12, LOW);
  tft.setCursor(160, 143);tft.setTextColor(WHITE);
  tft.println("2 ON");
  tft.setCursor(160, 143);tft.setTextColor(RED);
  tft.println("2 OFF");
  delay(1000);
  }

  if (p.y > 150 && p.y < 200 && p.x > 200 && p.x < 500)
  {
  digitalWrite(19, HIGH);  
  tft.setCursor(160, 200);tft.setTextColor(WHITE);
  tft.println("3 OFF");
  tft.setCursor(160, 200);tft.setTextColor(GREEN);
  tft.println("3 ON");
  delay(1000);
  }

 if (p.y > 150 && p.y < 200 && p.x > 600 && p.x < 1000)
  {
  digitalWrite(19, LOW);
  tft.setCursor(160, 200);tft.setTextColor(WHITE);
  tft.println("3 ON");
  tft.setCursor(160, 200);tft.setTextColor(RED);
  tft.println("3 OFF");
  delay(1000);
  }

  delay(1000); // is to stabilize the x,y coordinates

}
