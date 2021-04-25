#include "led.h"
#include "delay.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "bsp_dht11.h"

DHT11_Data_TypeDef DHT11_Data;

/*
	�����ѹ��3.3 - 5V
	���ߣ�DATA -�� PB10 ��IO�ڣ�
*/

int main(void)
{
	u8 str[100] = {0};
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();				 // LCD��ʼ��
	DHT11_GPIO_Config();     // ��ʼ��DTT11������ DATA -> PB10
	LED0 = 0;
	POINT_COLOR = WHITE;
	BACK_COLOR = BLACK;
	LCD_Clear(BLACK); 
  	while(1) 
	{
		POINT_COLOR = WHITE;
		// ����Read_DHT11��ȡ��ʪ�ȣ����ɹ����������Ϣ
		if( Read_DHT11(&DHT11_Data) == SUCCESS)
		{
			printf("ʪ��Ϊ%d.%d ��RH ���¶�Ϊ %d.%d�� \r\n", DHT11_Data.humi_int, DHT11_Data.humi_deci, DHT11_Data.temp_int, DHT11_Data.temp_deci);
			sprintf((char*)str, "HUM: %d.%d%%RH  ", DHT11_Data.humi_int, DHT11_Data.humi_deci);
			LCD_ShowString(10,130,200,24,24, str);
			sprintf((char*)str, "YEMP: %d.%dCEL ", DHT11_Data.temp_int, DHT11_Data.temp_deci);
			LCD_ShowString(10,170,200,24,24, str);
			//printf("\r\n ʪ��:%d,�¶�:%d \r\n" ,DHT11_Data.humi_int,DHT11_Data.temp_int);
		}
		else
		{
			printf("Read DHT11 ERROR!\r\n");
		}
		LED0 = !LED0;
		// �������ڲ��õ���1�룬������ȡʧ��
		delay_ms(1000);
		delay_ms(1000);
	} 
}
 
