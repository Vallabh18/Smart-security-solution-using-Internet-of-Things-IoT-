#include<lpc214x.h>
#include"lcdmodern.h"
#include"gpio.h"
#include"serial.h"

#define fire    P0_21 			 //p0.2
#define ldr     P0_22			 //p0.3


 void pin()
{
 PINSEL0=0X00050005;//SELECTING PIN OPERATION
 PINSEL1=0X15000000;
 PINSEL2=0X00000000;
 IODIR0=0XFFFFFFFF;// as output	and 2 pins as input
 IODIR0&=~((1<<21)|(1<<22));
 //IODIR1&=~(1<<17);
 IOCLR1=0XFFFFFFFF;
 IOPIN1=0X0;
 AD0CR=0X00210600;// ADC CONTROL REGISTER

}
char inp0(unsigned long int pinNumber)
{
	unsigned long int pinBlockState =IOPIN0;
	int pinState = (pinBlockState & (pinNumber)) ? 1 : 0;
	return pinState;
}
char inp1(unsigned long int pinNumber)
{
   unsigned long int pinBlockState=IOPIN1;
  int pinState = (pinBlockState &(pinNumber)) ? 1 : 0;
  return pinState;
}



int main()
{
unsigned char hum,hum1[15]="HUMAN-DETECTED";
unsigned long int i;
 pin();
 initlcd();
 delay(50);
 hum=inp0(ldr);
 //fi=inp0(fire);
 

 ser_init_1(0x61,0x00);
 ser_init_0(0x61,0x00);
 
 clcd(0x01);delay(10);

stringlcd(0x80,"SMART SECURITY");
stringlcd(0xC0," USING - IoT  ");
delay(2000);	
 while(1)
{
stringlcd(0x80,"NO HUMAN");
delay(1000);
     for(i=0;i<15;i++)  
   {

   hum=inp0(ldr);

   			if(hum==1)
		     {
				
				stringlcd(0x01,"HUMAN Detected ");
				delay(1000);
				hum=1;
									 
			 }
			

	}// END OF FOR LOOP

 
	stringlcd(0x01," DATA UPDATING ");delay(50);
	delay(5000);
	
	string_0("AT+CPIN?\r\n");
	delay(3000);
	
	string_0("AT+SAPBR=3,1,\"CONTYPE\" ,\"GPRS\" \r\n");
	delay(3000);
	string_0("AT+SAPBR=3,1,\"APN\",\"live.vodafone.com \"\r\n");
	delay(3000);
	
	string_0("AT+SAPBR=1,1\r\n");
	delay(3000);
	
	string_0("AT+HTTPINIT \r\n");
	delay(3000);
	
	string_0("AT+HTTPPARA=\"CID\",1\r\n");
	delay(3000);
	
	string_0("AT+HTTPPARA=\"URL\",\"http://bosembedded.com/GPRS/res14.asp?data=");
	
				if(hum==1)
		    	{
				string_0(*(&hum1));
			//	string_0(",");
				 }
			

string_0("\"\r\n");
		delay(3000);
		string_0("AT+HTTPACTION=0\r\n");
		delay(3000);
		
		string_0("AT+HTTPREAD\r\n");
		delay(3000);
		
		string_0("AT+HTTPTERM\r\n");
		delay(3000);

  }	  //END OF WHILE
  }	 //END OF MAIN
// end of main loop



