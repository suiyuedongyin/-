#ifndef __LCD__
#define __LCD__

#define DataPort P1

extern char local_date,base_date;
extern unsigned char code *Main_Menu1[];
extern unsigned char code *Main_Menu2[];

sbit RS = P5^3;
sbit RW = P5^2;
sbit E  = P5^1;
sbit PSB   = P5^0;
sbit RES   = P4^0;

void DisplayUpdata0(void);
void DisplayUpdata1(void);
void DisplayUpdata2(void);
void ClrScreen();
void LCD_PutString(unsigned char x,unsigned char y,unsigned char code *s);
void DisplayCGRAM(unsigned char x,unsigned char y);
void CGRAM();
void Init_ST7920();
void Write_Data(unsigned char Data);
void Write_Cmd(unsigned char Cmd);
void Check_Busy();

#endif
