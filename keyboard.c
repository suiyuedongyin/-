#include <stc8.h>
#include "delay.h"
#include "lcd_12864.h"
#include "keyboard.h"

#define uchar unsigned char
#define uint unsigned int
	


unsigned char i, j;
extern uchar key;
long unsigned int password1 = 111111 ;   //�����ʼ����
long unsigned int password2 = 0;         //�����û����������
unsigned int d = 0;                      //����λ��d��d = 5�Ǿ�����1����λ��

uchar key_scan()
{
			uchar num_key;

		//����2�У�����2�е͵�ƽ
			P2=0xef;					
			num_key=P2;
			num_key=num_key&0x0f;
			if(num_key!=0x0f)
				{
					Delay_Ms(40);
					num_key=P2;
					num_key=num_key&0x0f;
					while(num_key!=0x0f)
					{
						num_key=P2;
					switch(num_key)
						{
							case 0xee:key=1;
								break;
							case 0xed:key=2;
								break;
							case 0xeb:key=3;
								break;
							case 0xe7:key=10;break;	//up
								
						}
					while(num_key!=0x0f)
						{
							num_key=P2;
							num_key=num_key&0x0f;
						}
					}
				}

			P2=0xdf;
			num_key=P2;
			num_key=num_key&0x0f;
			while(num_key!=0x0f)
				{
					Delay_Ms(40);
					num_key=P2;
					num_key=num_key&0x0f;
					while(num_key!=0x0f)
					{
						num_key=P2;
					switch(num_key)
						{
							case 0xde:key=4;
								break;
							case 0xdd:key=5;
								break;
							case 0xdb:key=6;
								break;
							case 0xd7:key=11;//down
						}
					while(num_key!=0x0f)
						{
							num_key=P2;
							num_key=num_key&0x0f;
						}
					}
				}


			P2=0xbf;
			num_key=P2;
			num_key=num_key&0x0f;
			while(num_key!=0x0f)
				{
					Delay_Ms(40);
					num_key=P2;
					num_key=num_key&0x0f;
					while(num_key!=0x0f)
					{
						num_key=P2;
					switch(num_key)
						{
							case 0xbe:key=7;
								break;
							case 0xbd:key=8;
								break;
							case 0xbb:key=9;
								break;
							case 0xb7:key=14;//esc
						}
					while(num_key!=0x0f)
						{
							num_key=P2;
							num_key=num_key&0x0f;
						}
					}
				}


			P2=0x7f;
			num_key=P2;
			num_key=num_key&0x0f;
			while(num_key!=0x0f)
				{
					Delay_Ms(40);
					num_key=P2;
					num_key=num_key&0x0f;
					while(num_key!=0x0f)
					{
						num_key=P2;
					switch(num_key)
						{
							case 0x7e:key=12;break;//left
							case 0x7d:key=0;break;
							case 0x7b:key=13;//right
							case 0x77:key=15;break;//ent
						}
					while(num_key!=0x0f)
						{
							num_key=P2;
							num_key=num_key&0x0f;
						}
					}
				}
return key;

}









void key_disaplay()
{
	switch(key){
	 
		case 1:  //����1
			//ClrScreen();			
			 LCD_PutString(d,2,"1");
		  Delay_Ms(5000);
		  d++;        // d = 0 -->  d = 1
		  password2 = password2 * 10 + 1;
		  break;
	  case 2:  //����2
			 LCD_PutString(d,2,"2");
	     Delay_Ms(5000);
		   d++;        
		   password2 = password2 * 10 + 2;
		   break;
	  case 3:  //����3
			 LCD_PutString(d,2,"3");
		  Delay_Ms(5000);
		  d++;        
		  password2 = password2 * 10 + 3;
		  break;
	  case 4:  //����4
			 LCD_PutString(d,2,"4");
		  Delay_Ms(5000);
		  d++;        // d = 0 -->  d = 1
		  password2 = password2 * 10 + 4;
		  break;
		case 5:  //����5
			 LCD_PutString(d,2,"5");
		  Delay_Ms(5000);
		  d++;        // d = 0 -->  d = 1
		  password2 = password2 * 10 + 5;
		  break;
		case 6:  //����6
			 LCD_PutString(d,2,"6");
		  Delay_Ms(5000);
		  d++;        // d = 0 -->  d = 1
		  password2 = password2 * 10 + 6;
		  break;
		case 7:  //����7
			 LCD_PutString(d,2,"7");
		  Delay_Ms(5000);
		  d++;        // d = 0 -->  d = 1
		  password2 = password2 * 10 + 7;
		  break;
		case 8:
			 LCD_PutString(d,2,"8");
		   Delay_Ms(5000);
		   d++;
			 P55 = 0;  			Delay_Ms(50);  P55 = 1;
		   password2 = password2 * 10 + 6;
		case 9:
			 LCD_PutString(d,2,"9");
	   	Delay_Ms(5000);
		  d++;
		  password2 = password2 * 10 + 9;
		case 10: 
			break;//up
		case 11: 
			break;//down
		case 12: 
			break;//left
		case 13:
			break;//right
		case 14: 
			break;//esc
		case 15:   
			break;//ent
		
				}


		 
		
			
		if(d > 5){    
		
			d = 0;
			if(password2 == password1){
//				lock = 1;    ����
				ClrScreen();
				LCD_PutString(0,2,"    ��ͨ��"); 
				P55 = 0;  			Delay_Ms(500);  P55 = 1; 
				
				}
			else {
				ClrScreen();
				LCD_PutString(0,1,"�������");
 				Delay_Ms(1000);
				LCD_PutString(0,2,"��������������");
				Delay_Ms(30000);
				
				ClrScreen();
				LCD_PutString(0, 1, "���������룺");
      				  
			}
			password2 = 0;		
		}
}








