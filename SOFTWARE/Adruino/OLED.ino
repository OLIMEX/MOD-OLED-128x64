#include <Wire.h>
#include <avr/pgmspace.h>
#include "OLED.h"

void setup() {
  
    pinMode(8, OUTPUT);
    digitalWrite(8, LOW);
    delay(300);

    Wire.begin();

    send_command(0xAE);
    send_command_data(0xD5, __osc_freq << 4 | __clk_div);
    send_command_data(0xA8, __mux_ratio);
    send_command_data(0xd3, 0x00);
    send_command_data(0x8d, 0x14);
    send_command(0x40);
    send_command(0xa6);
    send_command(0xa4);
    send_command(0xa1);
    send_command(0xc8);
    // Horizontal mode
    send_command(0x20);
    send_command(0x00);

    send_command_data(0xda, 0x12);
    send_command_data(0x81, __contrast);
    send_command_data(0xd9, 0xf1);
    send_command_data(0xdb, 0x40);
    send_command(0xaf);

    clear_screen();
    print_text(1," OLIMEX");
    print_smtext(3,(unsigned char *)"     Hello World!",1);
    print_smtext(5,(unsigned char *)"        Sensei will",1);
    print_smtext(6,(unsigned char *)"        teach you the",1);
    print_smtext(7,(unsigned char *)"        Olimexino way",1);
    
    drawLine(1,25,128,25);
    
    drawEllipse(20,70,5,20);
    drawLine(23,52,37,60);
    drawLine(17,52,10,64);
    
    drawCircle(20,40,10);
    drawLine(15,38,18,38);
    drawLine(22,38,25,38);
    drawLine(20,40,21,42);
    drawLine(15,43,16,45);
    drawLine(17,46,20,47);
    
    drawTriangle(5,35,20,28,35,35);
    
    drawRectangle(37,55,40,65);
    drawSolidRectangle(37,54,40,30);
    
    //invert_screen();
    //normal_screen();
    
    update();
    delay(200);
}

void loop() {
}
