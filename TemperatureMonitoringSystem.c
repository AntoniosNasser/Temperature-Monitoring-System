sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
// End LCD module connections

/* Global Variables */
char Temperature[] = " 00.0 C";
unsigned int Temp;

void Init_Message();  // Initial message function declearation

void main()
{
     Lcd_Init();                           // Initialize LCD
     Init_Message();                       // Initial Message function that shows names and IDs
     lcd_out(1, 3, "Temperature:");        // print "Temperature:" on LCD in row 1 and col 3
     
     // LM35 and RGB modules connections 
     // LM35 (Port A pin 0) as input 
     // RGB (Port A pin 4,5,6) as output
     TRISA = 0b00001111;
     
     while(1){
              Temp = ADC_Read(0) * 0.4876;              // Read analog voltage and convert it to degree Celsius
              // convert the int value of Temp to string value stored in Temperature array
              if (temp > 99)
                 Temperature[0]  = 1 + 48;              // Put 1 (of hundred)
               else
                 Temperature[0]  = ' ';                 // Put space
               Temperature[1]  = (temp / 10) % 10  + 48;
               Temperature[2]  =  temp % 10  + 48;
               Temperature[5] = 223;                    // Put degree symbol ( ° )
               lcd_out(2, 5, Temperature);              // Display LM35 temperature result
               // dispaly RGB as respect to value of Temp
               if(Temp<20)                            // display blue for Temp<20
               {
                          PORTA = 0x40;               // turn blue light
                          delay_ms(10);
               }
               else if(Temp>20&&Temp<33)              // display green for Temp>20 and Temp <33
               {
                          PORTA = 0x20;               // turn green light
                          delay_ms(10);
               }
               else if(Temp>33)                       // display red for Temp>33
               {
                          PORTA = 0x10;               // turn red light
                          delay_ms(10);
               }
               else
               {
                          delay_ms(10);
               }
               delay_ms(100);                          // Wait 1 second
     }
}

void Init_Message(){

     Lcd_Cmd(_LCD_CLEAR);                 // Clear LCD
     Lcd_Cmd(_LCD_CURSOR_OFF);            // Cursor Off
     /* print developer name and  */
     Lcd_Out(1,1,"   Made By:");
     Lcd_Out(2,1,"Antonios Nasser");
     delay_ms(1000);                       // delay for few seconds
     Lcd_Cmd(_LCD_CLEAR);                 // Clear LCD
}
