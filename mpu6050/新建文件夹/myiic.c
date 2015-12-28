#include "myiic.h"


//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//IIC 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/6
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

//初始化IIC
extern int fd;

void IIC_Init(void)
{
	fd = open("/dev/i2c-1", O_RDWR);
	if (ioctl(fd,I2C_SLAVE,0x68) < 0)
	{
		printf("IIC_Init error.\n");    
	}
		
}

void delay_ms(long t)
{
	usleep(t*1000);
}
