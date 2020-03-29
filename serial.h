void ser_init_1(unsigned char dll,unsigned char dlm)//serial
{
   U1FCR=0x07;
   U1LCR=0x83;
   U1DLL=dll;	
   U1DLM=dlm;	
   U1LCR=0x03;
}
void send_1(unsigned char ch)// tx an assic value
{
U1THR=ch;
while(!(U1LSR&0X20));// CHECK THE TX HOLDING REGISTER
}
unsigned char receive_1(void)
{
 unsigned char ch;
 while(!(U1LSR&0x01));
 ch=U1RBR;
 return ch;
}
void string_1(unsigned char *str)
{
 unsigned int i=0;
 while(str[i]!='\0')
 {
   send_1(str[i]);
   i++;
 }
}
void ser_init_0(unsigned char dll,unsigned char dlm)
{
   U0FCR=0x07;
   U0LCR=0x80;
   U0DLL=dll;	
   U0DLM=dlm;	
   U0LCR=0x03;
}
void send_0(unsigned char ch)// tx an assic value
{

while(!(U0LSR&0X20));// CHECK THE TX HOLDING REGISTER
U0THR=ch;
}
unsigned char receive_0(void)
{
 unsigned char ch;
 while(!(U0LSR&0x01));
 ch=U0RBR;
 return ch;
}
void string_0(unsigned char *str)
{
 unsigned int i=0;
 while(str[i]!='\0')
 {
   send_0(str[i]);
   i++;
 }
}
void conv_serial_0(unsigned long int ch)
 {
 unsigned long int temp=0,temp2=0;
 temp2=ch;
 temp=temp2/10000;
// send_0(temp+0x30);
 temp2=temp2%10000;
 temp=temp2/1000;
 send_0(temp+0x30);
 temp2=temp2%1000;
 temp=temp2/100;
 send_0(temp+0x30); 
 temp2=temp2%100;
 temp=temp2/10;
 send_0(temp+0x30);
 temp2=temp2%10;
 send_0(temp2+0x30);
 }
 void conv_serial_1(unsigned long int ch)
 {
 unsigned long int temp=0,temp2=0;
 temp2=ch;
 temp=temp2/10000;
 send_1(temp+0x30);
 temp2=temp2%10000;
 temp=temp2/1000;
 send_1(temp+0x30);
 temp2=temp2%1000;
 temp=temp2/100;
 send_1(temp+0x30); 
 temp2=temp2%100;
 temp=temp2/10;
 send_1(temp+0x30);
 temp2=temp2%10;
 send_1(temp2+0x30);
 }
