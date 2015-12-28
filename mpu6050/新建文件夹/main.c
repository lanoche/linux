#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include <stdio.h>

//ALIENTEK 探索者STM32F407开发板 实验32
//MPU6050六轴传感器 实验 -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

//串口1发送1个字符 
//c:要发送的字符


int fd=0;

int main(void)
{ 
	float pitch,roll,yaw; 		//欧拉角
	short aacx,aacy,aacz;		//加速度传感器原始数据
	short gyrox,gyroy,gyroz;	//陀螺仪原始数据
	short temp;			//温度
	int num=0;
	int errnum=0;				//错误号 
	IIC_Init(); 
	MPU_Init();					//初始化MPU6050
	
	errnum=mpu_set_sensors(INV_X_GYRO|INV_Y_GYRO|INV_Z_GYRO|INV_XYZ_GYRO|INV_XYZ_ACCEL);
 	if(errnum)
 	printf("mpu_set_sensors errnum=%d",errnum);
	
	
	while(errnum=mpu_dmp_init())
	{
		printf("mpu_dmp_init() errornum=%d\n",errnum);
		delay_ms(100);
		errnum=0;
	}


	 
	while(1)
	{
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{ 
			temp=MPU_Get_Temperature();	//得到温度值
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		}
		if(num==100)
		{
			printf("pitch=%f,\troll=%f,\tyaw=%f\n",pitch,roll,yaw);
			num=0;
		}
		num++;
	} 	
}
