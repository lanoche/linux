#include "myiic.h"


//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//IIC ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/6
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

//��ʼ��IIC
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
