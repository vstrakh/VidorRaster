#include "VidorGraphics.h"
#include "Vidor_GFX.h"

Vidor_GFX  vdgfx;
void testLines(unsigned color);
void testRects(unsigned color);
void testFilledRects(unsigned color1, unsigned color2);

void setup() {
  Serial.begin(9600);

  // Initialize the FPGA
  if (!FPGA.begin()) {
    Serial.println("Initialization failed!");
    while (1) {}
  }

  delay(3000);
  vdgfx.begin();
}

void loop()
{
  for(int i=0; i<2; ++i)
  {
#if 1
    testLines(vdgfx.lightBlue());
    testRects(vdgfx.White());
    testFilledRects(vdgfx.Purple(), vdgfx.Yellow());
#else
    vdgfx.runBenchmark(0);
#endif
  }
  /**
  *  Draw an Arduino logo
  */
#if 0
  // Fill the screen with a white background
  vdgfx.fillRect(0,0,640,480,vdgfx.White());

  /**
  *  The library allows drawing some basic elements to the view, like circles, rectangles, lines
  */  

  vdgfx.fillCircle(225,225,100 ,vdgfx.lightBlue());
  vdgfx.fillCircle(415,225,100 ,vdgfx.lightBlue());
  vdgfx.fillCircle(225,225,90 ,vdgfx.White());
  vdgfx.fillCircle(415,225,90 ,vdgfx.White());
  vdgfx.fillRect(175,220,100,10 ,vdgfx.lightBlue());
  vdgfx.fillRect(365,220,100,10 ,vdgfx.lightBlue());
  vdgfx.fillRect(410,175,10,100 ,vdgfx.lightBlue());

  /**
  *  To draw a text we can use the classic functions like write() and print()
  *  Text size, color and position can be changed using the .text subclass
  */
  vdgfx.text.setFont(0);
  vdgfx.text.setCursor(150,375);
  vdgfx.text.setAlpha(255);
  vdgfx.text.setSize(7);
  vdgfx.text.setColor(vdgfx.lightBlue());
  vdgfx.println("ARDUINO");
  vdgfx.text.setCursor(480,145);
  vdgfx.text.setSize(3);
  vdgfx.println("TM");

  vdgfx.drawLine(20,40, 300, 10, vdgfx.Blue());
  vdgfx.fillRoundRect(10, 50, 240, 180, 80, vdgfx.Blue());
  vdgfx.drawRoundRect(10,240, 240, 180, 80, vdgfx.Blue());
  vdgfx.drawRect(300, 50, 240, 180, vdgfx.Blue());
  vdgfx.fillRect(300, 240, 240, 180, vdgfx.Blue());

  vdgfx.Cross(400, 360, vdgfx.Red());
#endif
  //while (1) {
  //}
  delay(2000);
}

void testLines(unsigned color)
{
    //unsigned start, t;
    int x1, y1, x2, y2,
        w = 640,
        h = 480;

    vdgfx.fillRect(0,0,640,480,vdgfx.Black());

    x1 = y1 = 0;
    y2 = h - 1;

    for (x2 = 0; x2 < w; x2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);
    x2 = w - 1;
    for (y2 = 0; y2 < h; y2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);

    vdgfx.fillRect(0,0,640,480,vdgfx.Black());

    x1 = w - 1;
    y1 = 0;
    y2 = h - 1;

    for (x2 = 0; x2 < w; x2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);
    x2 = 0;
    for (y2 = 0; y2 < h; y2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);

    vdgfx.fillRect(0,0,640,480,vdgfx.Black());

    x1 = 0;
    y1 = h - 1;
    y2 = 0;

    for (x2 = 0; x2 < w; x2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);
    x2 = w - 1;
    for (y2 = 0; y2 < h; y2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);

    vdgfx.fillRect(0,0,640,480,vdgfx.Black());

    x1 = w - 1;
    y1 = h - 1;
    y2 = 0;

    for (x2 = 0; x2 < w; x2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);
    x2 = 0;
    for (y2 = 0; y2 < h; y2 += 6)
        vdgfx.drawLine(x1, y1, x2, y2, color);
}

void testRects(unsigned color)
{
    int n, i, i2,
        cx = 640 / 2,
        cy = 480 / 2;

    //vdgfx.fillRect(0,0,640,480,vdgfx.Black());
    n = min(640, 480);

    for (i = 2; i < n; i += 6)
    {
        i2 = i / 2;
        vdgfx.drawRect(cx - i2, cy - i2, i, i, color);
    }
}

void testFilledRects(unsigned color1, unsigned color2)
{
    unsigned long start, t = 0;
    int n, i, i2,
        cx = 640 / 2 - 1,
        cy = 480 / 2 - 1;

    vdgfx.fillRect(0,0,640,480,vdgfx.Black());
    n = min(640, 480);
    for (i = n - 1; i > 0; i -= 6)
    {
        i2 = i / 2;
        vdgfx.fillRect(cx - i2, cy - i2, i, i, color1);
        vdgfx.drawRect(cx - i2, cy - i2, i, i, color2);
    }
}
