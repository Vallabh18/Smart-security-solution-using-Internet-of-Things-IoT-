/*  GPIO PIN's for port-0 */

#define   P0_0   0x00000001 
#define   P0_1   0x00000002
#define   P0_2   0x00000004
#define   P0_3   0x00000008
#define   P0_4   0x00000010 
#define   P0_5   0x00000020 
#define   P0_6   0x00000040 
#define   P0_7   0x00000080 
#define   P0_8   0x00000100 
#define   P0_9   0x00000200 
#define   P0_10  0x00000400 
#define   P0_11  0x00000800
#define   P0_12  0x00001000
#define   P0_13  0x00002000
#define   P0_14  0x00004000 
#define   P0_15  0x00008000 
#define   P0_16  0x00010000     
#define   P0_17  0x00020000
#define   P0_18  0x00040000 
#define   P0_19  0x00080000  
#define   P0_20  0x00100000 
#define   P0_21  0x00200000
#define   P0_22  0x00400000  
#define   P0_23  0x00800000
#define   P0_24  0x01000000
#define   P0_25  0x02000000
#define   P0_26  0x04000000
#define   P0_27  0x08000000
#define   P0_28  0x10000000
#define   P0_29  0x20000000
#define   P0_30  0x40000000
#define   P0_31  0x00100000

/* GPIO PIN's for port-1 */

#define  P1_16  0x00010000     
#define  P1_17  0x00020000
#define  P1_18  0x00040000 
#define  P1_19  0x00080000  
#define  P1_20  0x00100000 
#define  P1_21  0x00200000
#define  P1_22  0x00400000  
#define  P1_23  0x00800000
#define  P1_24  0x01000000
#define  P1_25  0x02000000
#define  P1_26  0x04000000
#define  P1_27  0x08000000
#define  P1_28  0x10000000
#define  P1_29  0x20000000
#define  P1_30  0x40000000
#define  P1_31  0x00100000

/*   UART  PIN's */

#define TX_0  0x00000001
#define RX_0  0x00000004
#define UART0 0x00000005
#define TX_1  0x00010000
#define RX_1  0x00040000
#define UART1 0x00050000

/*    UART Interrupts   */

#define u0_int_addr    0x00000026	  // interrupt source with index 6 and enable IRQ bit(5 bit);
#define u0_int_en      0x00000040	  // enable UART-0 interrupt;  
#define u1_int_addr    0x00000027	  // interrupt source with index 7 and enable IRQ bit(5 bit);
#define u1_int_en      0x00000080	  // enable UART-1 interrupt;  

/*   ADC-0 input pin's   */ 

#define  AD0_1  0x01000000			  // use PINSEL1
#define  AD0_2  0x04000000			  // use PINSEL1
#define  AD0_3  0x10000000			  // use PINSEL1
#define  AD0_4  0x00040000			  // use PINSEL1
#define  AD0_6  0x00000100			  // use PINSEL0
#define  AD0_7  0x00000400			  // use PINSEL0

/*   ADC-1 input pin's   */ 

#define  AD1_0  0x00003000			  // use PINSEL0
#define  AD1_1  0x00030000			  // use PINSEL0
#define  AD1_2  0x00300000			  // use PINSEL0
#define  AD1_3  0x03000000			  // use PINSEL0
#define  AD1_4  0x0c000000			  // use PINSEL0
#define  AD1_5  0xc0000000			  // use PINSEL0
#define  AD1_6  0xc0000c00			  // use PINSEL1
#define  AD1_7  0x00003000			  // use PINSEL1

/*  ADC POWER CONTROL PINS  */

#define  AD0_power_on  0x00001000	  // use PCONP 
#define  AD1_power_on  0x00100000	  // use PCONP

/* ADC  channel selection  */

#define  CH_0  0x00000001			 //  use AD0CR/AD1CR 
#define  CH_1  0x00000002			 //  use AD0CR/AD1CR
#define  CH_2  0x00000004			 //  use AD0CR/AD1CR
#define  CH_3  0x00000008			 //  use AD0CR/AD1CR
#define  CH_4  0x00000010			 //  use AD0CR/AD1CR
#define  CH_5  0x00000020			 //  use AD0CR/AD1CR
#define  CH_6  0x00000040			 //  use AD0CR/AD1CR
#define  CH_7  0x00000080			 //  use AD0CR/AD1CR

/*  CLKDIV  section  */

#define CLK_1   0x00000000           // MCU clock/CLK_n  12MHZ/7= 1.71 Mhz
#define CLK_2   0x00000100
#define CLK_3   0x00000200
#define CLK_4   0x00000300
#define CLK_5   0x00000400
#define CLK_6   0x00000500
#define CLK_7   0x00000600
#define CLK_8   0x00000700

/* ADC  burst bit */

#define BURST_OFF  0xFFFEFFFF 	     // must be AND operation with AD0CR
#define BURST_ON   0xFFF1FFFF 	     // must be AND operation with AD0CR

/*  ADC resolution	in bits  */

#define  bit_10  0x00000000
#define  bit_9   0x00020000
#define  bit_8   0x00040000
#define  bit_7   0x00060000
#define  bit_6   0x00080000
#define  bit_5   0x000A0000
#define  bit_4   0x000C0000
#define  bit_3   0x000E0000

#define  PDN_ON     0x00200000
#define  ADC_start  0x01000000
#define  ADC_Wait 	(AD0DR1 & 0x80000000)
#define  Result     ((AD0DR1 >> 6) & 0x000003FF)
#define  ADC_Stop 	(AD0CR &= 0xF8FFFFFF)

/*  RTC REGISTERS  */

#define sec   (CTIME0 & 0x3f)	              //READ SECONDS 
#define min   ((CTIME0 & 0x3f00)>>8)	      //READ MINUTES 
#define hour  ((CTIME0 & 0x1f0000)>>16)       //READ HOURS IN 24 HOURS MODE
#define dow   ((CTIME0 & 0x07000000)>>24)	  //READ DAY OF THE WEEK

#define dom   (CTIME1 & 0x1f)		          //READ DAY OF THE MONTH
#define mon   ((CTIME1 & 0x0f00)>>8)		  //READ MONTH
#define year  ((CTIME1 & 0x0fff0000)>>16)	  //READ YEAR

#define doy   (CTIME2 & 0x07ff) 	          //READ DAY OF THE YEAR

/******************   I2C REGISTERS  ************************/

#define  i2c0  0x50                     // use PINSEL0

// FOR 100KHZ FREQUENCY

#define  sclh1   75
#define  scll1   75

// FOR 200KHZ FREQUENCY

#define  sclh2   37
#define  scll2   37

// FOR 400KHZ FREQUENCY

#define  sclh4   18
#define  scll4   18

