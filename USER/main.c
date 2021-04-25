#include "led.h"
#include "delay.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "bsp_dht11.h"
#include "ds18b20.h"
#include "key.h"
#include "beep.h"

DHT11_Data_TypeDef DHT11_Data;

/*
	DS18B20
	�����ѹ��3 - 5.5V
	���ߣ�DQ -�� PG11 ��IO�ڣ�
	
	DHT11
	�����ѹ��3.3 - 5V
	���ߣ�DATA -�� PB10 ��IO�ڣ�
*/

int main(void)
{
	u8 str[100] = {0};
	// ������������־λ
	u8 flag = 0;
	// ����ģʽ
	u8 mode = 0;
	vu8 key = 0;
	// ѭ������
	u8 time = 0;
	// DS18B20�ñ���
	short temperature;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();				 // LCD��ʼ��
	KEY_Init();				 // KEY��ʼ��
	BEEP_Init();			 // BEEP��ʼ��
	DHT11_GPIO_Config();     // ��ʼ��DTT11������ DATA -> PB10
	LED0 = 0;
	LED1 = 0;
	POINT_COLOR = WHITE;
	BACK_COLOR = BLACK;
	LCD_Clear(BLACK); 
	while(DS18B20_Init())	//DS18B20��ʼ��	
	{
		LCD_ShowString(10,70,200,16,16,"DS18B20 Error");
		delay_ms(200);
		LCD_Fill(10,70,239,130+16, BLACK);
 		delay_ms(200);
	}
	LCD_ShowString(10,90,200,16,16,"Temp:   . CEL"); 
	LCD_ShowString(10,220,220,12,12,"TOUCH KEY0 CLOSE ALARM MODE"); 
	LCD_ShowString(10,240,220,12,12,"TOUCH KEY1 OPEN ALARM MODE"); 
	POINT_COLOR = RED;
	LCD_ShowString(10,260,100,12,12,"ALARM MODE: OFF"); 
	POINT_COLOR = WHITE;
  	while(1) 
	{
		flag = 2;
		POINT_COLOR = WHITE;
		
		key = KEY_Scan(0); //�õ���ֵ
		if (key)
		{
			switch (key)
			{
				case WKUP_PRES: 
					LED1 = !LED1;
					break;
				// KEY1 ���� ��������ģʽ
				case KEY1_PRES: 
					mode = 1;
					LED1 = !LED1;
					LCD_ShowString(80,260,100,12,12,"ON  "); 
					printf("��������ģʽ\r\n");
					break;
				// KEY1 ���� �رձ���ģʽ
				case KEY0_PRES: 
					mode = 0;
					LED1 = !LED1;
					LCD_ShowString(80,260,100,12,12,"OFF "); 
					printf("�رձ���ģʽ\r\n");
					break;
			}
		}
		
		// Լ2��һ��
		if(time % 200 == 0)
		{
			// DS18B20
			temperature = DS18B20_Get_Temp();	
			if(temperature < 0)
			{
				LCD_ShowChar(10+40, 90, '-', 16, 0);			//��ʾ����
				temperature = -temperature;					    //תΪ����
			}else LCD_ShowChar(10+40,90,' ', 16, 0);			//ȥ������
			LCD_ShowNum(10+40+8, 90, temperature/10, 2, 16);	//��ʾ��������	    
			LCD_ShowNum(10+40+32, 90,temperature%10, 1, 16);	//��ʾС������
			printf("�¶�Ϊ %u.%u�� \r\n",temperature/10, temperature%10);
			
			// DHT11
			// ����Read_DHT11��ȡ��ʪ�ȣ����ɹ����������Ϣ �������ڲ��õ���1�룬������ȡʧ��
			if( Read_DHT11(&DHT11_Data) == SUCCESS)
			{
				printf("ʪ��Ϊ%d.%d ��RH ���¶�Ϊ %d.%d�� \r\n", DHT11_Data.humi_int, DHT11_Data.humi_deci, DHT11_Data.temp_int, DHT11_Data.temp_deci);
				sprintf((char*)str, "HUM: %d.%d%%RH  ", DHT11_Data.humi_int, DHT11_Data.humi_deci);
				LCD_ShowString(10,130,200,24,24, str);
				sprintf((char*)str, "TEMP: %d.%dCEL ", DHT11_Data.temp_int, DHT11_Data.temp_deci);
				LCD_ShowString(10,170,200,24,24, str);
				//printf("\r\n ʪ��:%d,�¶�:%d \r\n" ,DHT11_Data.humi_int,DHT11_Data.temp_int);
			}
			else
			{
				printf("Read DHT11 ERROR!\r\n");
			}
			
			// �ж��¶��Ƿ񲻵���85���϶�
			if(temperature >= 850 || DHT11_Data.temp_int >= 85)
			{
				printf("�¶ȹ��ߣ�����\r\n");
				flag++;
			}
			else
			{
				flag--;
			}
			
			// �ж�ʪ���Ƿ����90%RH
			if(DHT11_Data.humi_int >= 90)
			{
				printf("ʪ�ȹ��ߣ�����\r\n");
				flag++;
			}
			else
			{
				flag--;
			}
			
			// �ж��Ƿ���Ҫ����
			if(flag >= 2 && mode == 1)
			{
				LCD_ShowString(10,200,200,16,16,"BEEP������(>__<)"); 
				printf("BEEP������(>__<)\r\n");
				BEEP = 1;
			}
			
			if(flag < 2)
			{
				LCD_ShowString(10,200,200,16,16,"     (- v -)    "); 
				BEEP = 0;
			}
			
			// ��������
			time = 0;
			
			LED0 = !LED0;
		}
		
		if(mode == 0)
		{
			LCD_ShowString(10,200,200,16,16,"     (- v -)    "); 
			BEEP = 0;
		}
		
		time++;
		delay_ms(10);
	} 
}
 
