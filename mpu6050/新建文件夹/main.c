#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include <stdio.h>

//ALIENTEK ̽����STM32F407������ ʵ��32
//MPU6050���ᴫ���� ʵ�� -�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

//����1����1���ַ� 
//c:Ҫ���͵��ַ�


int fd=0;

int main(void)
{ 
	float pitch,roll,yaw; 		//ŷ����
	short aacx,aacy,aacz;		//���ٶȴ�����ԭʼ����
	short gyrox,gyroy,gyroz;	//������ԭʼ����
	short temp;			//�¶�
	int num=0;
	int errnum=0;				//����� 
	IIC_Init(); 
	MPU_Init();					//��ʼ��MPU6050
	
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
			temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
		}
		if(num==100)
		{
			printf("pitch=%f,\troll=%f,\tyaw=%f\n",pitch,roll,yaw);
			num=0;
		}
		num++;
	} 	
}
