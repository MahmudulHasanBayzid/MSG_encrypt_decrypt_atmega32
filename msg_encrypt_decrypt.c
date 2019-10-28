// LCD module connections
sbit LCD_RS at PORTD2_bit;
sbit LCD_EN at PORTD3_bit;
sbit LCD_D4 at PORTD4_bit;
sbit LCD_D5 at PORTD5_bit;
sbit LCD_D6 at PORTD6_bit;
sbit LCD_D7 at PORTD7_bit;

sbit LCD_RS_Direction at DDD2_bit;
sbit LCD_EN_Direction at DDD3_bit;
sbit LCD_D4_Direction at DDD4_bit;
sbit LCD_D5_Direction at DDD5_bit;
sbit LCD_D6_Direction at DDD6_bit;
sbit LCD_D7_Direction at DDD7_bit;
// End LCD module connections


char message[]="MAIN MESSAGE :D";
char txt=message;
int n;
char en_message[100]=" ";
int pass=0b1010;

char nn[10];
void encripte(char a[])
{
    int i;

    n=strlen(message);


     for(i=0;i<n;i++)
     {
           en_message[i]=a[i]+2;
     }




}


void main(){


  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off

  DDB0_bit=0;
  DDRC=0b0000;
  while(1){



      delay_ms(100);
  Lcd_Cmd(_LCD_CLEAR);
   if(PINB0_bit==1)
   {
         if(PINC==pass){
         

                        Lcd_Out(1,1,"MAIN MESSAGE :D");
                        delay_ms(100);
         
         }
         else
  {

      encripte(message);
      Lcd_Out(1,1,en_message);                 // Write text in first row

  }
   }

  else
  {


      Lcd_Out(1,1,"ENTER PASSWORD: ");                 // Write text in first row

  }



  }
}