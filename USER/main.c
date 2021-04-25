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
	供电电压：3 - 5.5V
	接线：DQ -》 PG11 （IO口）
	
	DHT11
	供电电压：3.3 - 5V
	接线：DATA -》 PB10 （IO口）
*/

int main(void)
{
	u8 str[100] = {0};
	// 蜂鸣器报警标志位
	u8 flag = 0;
	// 报警模式
	u8 mode = 0;
	vu8 key = 0;
	// 循环计数
	u8 time = 0;
	// DS18B20用变量
	short temperature;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	LCD_Init();				 // LCD初始化
	KEY_Init();				 // KEY初始化
	BEEP_Init();			 // BEEP初始化
	DHT11_GPIO_Config();     // 初始化DTT11的引脚 DATA -> PB10
	LED0 = 0;
	LED1 = 0;
	POINT_COLOR = WHITE;
	BACK_COLOR = BLACK;
	LCD_Clear(BLACK); 
	while(DS18B20_Init())	//DS18B20初始化	
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
		
		key = KEY_Scan(0); //得到键值
		if (key)
		{
			switch (key)
			{
				case WKUP_PRES: 
					LED1 = !LED1;
					break;
				// KEY1 按下 开启报警模式
				case KEY1_PRES: 
					mode = 1;
					LED1 = !LED1;
					LCD_ShowString(80,260,100,12,12,"ON  "); 
					printf("开启报警模式\r\n");
					break;
				// KEY1 按下 关闭报警模式
				case KEY0_PRES: 
					mode = 0;
					LED1 = !LED1;
					LCD_ShowString(80,260,100,12,12,"OFF "); 
					printf("关闭报警模式\r\n");
					break;
			}
		}
		
		// 约2秒一次
		if(time % 200 == 0)
		{
			// DS18B20
			temperature = DS18B20_Get_Temp();	
			if(temperature < 0)
			{
				LCD_ShowChar(10+40, 90, '-', 16, 0);			//显示负号
				temperature = -temperature;					    //转为正数
			}else LCD_ShowChar(10+40,90,' ', 16, 0);			//去掉负号
			LCD_ShowNum(10+40+8, 90, temperature/10, 2, 16);	//显示正数部分	    
			LCD_ShowNum(10+40+32, 90,temperature%10, 1, 16);	//显示小数部分
			printf("温度为 %u.%u℃ \r\n",temperature/10, temperature%10);
			
			// DHT11
			// 调用Read_DHT11读取温湿度，若成功则输出该信息 采样周期不得低于1秒，否则会读取失败
			if( Read_DHT11(&DHT11_Data) == SUCCESS)
			{
				printf("湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n", DHT11_Data.humi_int, DHT11_Data.humi_deci, DHT11_Data.temp_int, DHT11_Data.temp_deci);
				sprintf((char*)str, "HUM: %d.%d%%RH  ", DHT11_Data.humi_int, DHT11_Data.humi_deci);
				LCD_ShowString(10,130,200,24,24, str);
				sprintf((char*)str, "TEMP: %d.%dCEL ", DHT11_Data.temp_int, DHT11_Data.temp_deci);
				LCD_ShowString(10,170,200,24,24, str);
				//printf("\r\n 湿度:%d,温度:%d \r\n" ,DHT11_Data.humi_int,DHT11_Data.temp_int);
			}
			else
			{
				printf("Read DHT11 ERROR!\r\n");
			}
			
			// 判断温度是否不低于85摄氏度
			if(temperature >= 850 || DHT11_Data.temp_int >= 85)
			{
				printf("温度过高！！！\r\n");
				flag++;
			}
			else
			{
				flag--;
			}
			
			// 判断湿度是否高于90%RH
			if(DHT11_Data.humi_int >= 90)
			{
				printf("湿度过高！！！\r\n");
				flag++;
			}
			else
			{
				flag--;
			}
			
			// 判断是否需要报警
			if(flag >= 2 && mode == 1)
			{
				LCD_ShowString(10,200,200,16,16,"BEEP！！！(>__<)"); 
				printf("BEEP！！！(>__<)\r\n");
				BEEP = 1;
			}
			
			if(flag < 2)
			{
				LCD_ShowString(10,200,200,16,16,"     (- v -)    "); 
				BEEP = 0;
			}
			
			// 重新置零
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
 
