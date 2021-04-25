#include "led.h"
#include "delay.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "bsp_dht11.h"

DHT11_Data_TypeDef DHT11_Data;

/*
	供电电压：3.3 - 5V
	接线：DATA -》 PB10 （IO口）
*/

int main(void)
{
	u8 str[100] = {0};
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
  	while(1) 
	{
		POINT_COLOR = WHITE;
		// 调用Read_DHT11读取温湿度，若成功则输出该信息
		if( Read_DHT11(&DHT11_Data) == SUCCESS)
		{
			printf("湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n", DHT11_Data.humi_int, DHT11_Data.humi_deci, DHT11_Data.temp_int, DHT11_Data.temp_deci);
			sprintf((char*)str, "HUM: %d.%d%%RH  ", DHT11_Data.humi_int, DHT11_Data.humi_deci);
			LCD_ShowString(10,130,200,24,24, str);
			sprintf((char*)str, "YEMP: %d.%dCEL ", DHT11_Data.temp_int, DHT11_Data.temp_deci);
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
 
