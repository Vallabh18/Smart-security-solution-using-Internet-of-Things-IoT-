#include "gpio.h"

#define  LCD_EN     P1_17
#define  LCD_RS     P1_16   					

#define  LCD_D4     P1_18   					
#define  LCD_D5     P1_19   					
#define  LCD_D6     P1_20  						
#define  LCD_D7     P1_21   					


#define  LCD_RS_on	(IOSET1 |= LCD_RS)
#define  LCD_RS_off	(IOCLR1 |= LCD_RS)

#define  LCD_EN_on  (IOSET1 |= LCD_EN)
#define  LCD_EN_off	(IOCLR1 |= LCD_EN)
void delay( unsigned int a)
{
 int i,j;
 for(i=0;i<a;i++)
  for(j=0;j<5000;j++);
}

void clcd(unsigned char val)
{
 unsigned int lcd_ch;			   
 unsigned int lcd_i;			   

 IOCLR1 = LCD_RS ;			//rs=0 command		
 
 lcd_ch=((val>>4)&0x0f);			

 IOCLR1 = (LCD_D7|LCD_D6|LCD_D5|LCD_D4);	 
 IOSET1 = (lcd_ch<<18); 			    	 
 IOSET1 = LCD_EN ;					
 for (lcd_i=0;lcd_i<100;lcd_i++);	
 IOCLR1 = LCD_EN ;				
 lcd_ch=(val&0x0F);				  		

 IOCLR1 = (LCD_D7|LCD_D6|LCD_D5|LCD_D4); 
 IOSET1 = (lcd_ch<<18); 				
 IOSET1 = LCD_EN ;					// EN = 1 (Enable)
 for (lcd_i=0;lcd_i<100;lcd_i++);	//delay
 IOCLR1 = LCD_EN ;					// EN = 0 (Disable)	
  
 for (lcd_i=0;lcd_i<100;lcd_i++);	 //delay
}

void dlcd(unsigned char val)
{
 unsigned int lcd_ch;		   // LCD Initial Data 
 unsigned int lcd_i;		   // LCD Initial Delay Count 

 IOSET1 = LCD_RS ;	 		// RS = 1 
 
 lcd_ch=((val>>4)&0x0F);	

 IOCLR1 = (LCD_D7|LCD_D6|LCD_D5|LCD_D4); // Reset 4-Bit Pin Data
 IOSET1 = (lcd_ch<<18); 				  
 IOSET1 = LCD_EN ;					// EN = 1 (Enable)
 for (lcd_i=0;lcd_i<100;lcd_i++);	// delay
 IOCLR1 = LCD_EN ;					// EN = 0 (Disable)	
  
 lcd_ch=(val&0x0F);				  	

 IOCLR1 = (LCD_D7|LCD_D6|LCD_D5|LCD_D4); 
 IOSET1 = (lcd_ch<<18); 				   
 
 IOSET1 = LCD_EN ;					// EN = 1 (Enable)
 for (lcd_i=0;lcd_i<100;lcd_i++);	//delay
 IOCLR1 = LCD_EN ;					// EN = 0 (Disable)	
  
 for (lcd_i=0;lcd_i<100;lcd_i++);	 //delay
}

void initlcd()
{
// unsigned int i;									
 PINSEL0 |= 0x00000000;
 PINSEL1 |= 0x00000000;
 PINSEL2 |= 0x00000000;			
 IODIR1  |= 0xFFFF0000;


 
 			
 clcd(0x20); delay(50); 
clcd(0x20); delay(50); 

 clcd(0x28); delay(50); 
 clcd(0x28);delay(50);  

 clcd(0x0e);delay(50);
  clcd(0x01);delay(50);	
 clcd(0x06);delay(50);	
 clcd(0x80);delay(50);
 clcd(0x80);delay(50);	
}
  

void stringlcd(unsigned char ch,unsigned char *str)
{
 
 if(ch==0x80){clcd(0x01);}
 clcd(ch);delay(10);
 while(*str)
 {
  dlcd(*str++);delay(100);

 }
}

// CONVERT HEX DECIMAL TO ASCII VALUE
 
 void conv(unsigned int temp1_value)  
		  {
            unsigned char value,d1,d2,d3,d4,val1;
              value=temp1_value/10;
              d4=temp1_value%10;
              val1=value/10;
              d3=value%10;
			  d2=val1%10;
			  d1=val1/10;
			   
             dlcd(d1+48);delay(10);
             dlcd(d2+48);delay(10);
             dlcd(d3+48);delay(10);
	         dlcd(d4+48);delay(10);


          }

 
