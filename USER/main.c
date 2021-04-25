#include "led.h"
#include "delay.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "bsp_dht11.h"
#include "ds18b20.h"

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
	// DS18B20用变量
	short temperature;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			     //LED端口初始化
	LCD_Init();				 // LCD初始化
	DHT11_GPIO_Config();     // 初始化DTT11的引脚 DATA -> PB10
	LED0 = 0;
	POINT_COLOR = WHITE;
	BACK_COLOR = BLACK;
	LCD_Clear(BLACK); 
	while(DS18B20_Init())	//DS18B20初始化	
	{
		LCD_ShowString(10,70,200,16,16,"DS18B20 Error");
		delay_ms(200);
		LCD_Fill(10,70,239,130+16,WHITE);
 		delay_ms(200);
	}
	LCD_ShowString(10,90,200,16,16,"Temp:   . CEL"); 
  	while(1) 
	{
		POINT_COLOR = WHITE;
		
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
		// 调用Read_DHT11读取温湿度，若成功则输出该信息
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
		LED0 = !LED0;
		// 采样周期不得低于1秒，否则会读取失败
		delay_ms(1000);
		delay_ms(1000);
	} 
}
 
