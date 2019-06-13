#pragma once
#ifndef _RaintubeSensor_h
#define _RaintubeSensor_h
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//��ͬ���ӹ��ڡ�ModbusRTUComm(MySerial * port, long baud, byte slaveId);���С�port���Ķ��岻ͬ��
//mega2560�������HardwareSerial��lenoard ������� Serial_
#if defined (USBCON)
#define  MySerial Serial_
#else
#define  MySerial HardwareSerial 
#endif

#include<SensorBase.h>
#include"ModbusMaster.h"


class RaintubeSensor:public SensorBase
{
public:
	RaintubeSensor(MySerial * port, long baud, byte slaveId);
	~RaintubeSensor();
	virtual int GetChnanelNum() override;
	virtual int Update() override;
	virtual float Read(int chanelNo) override;
	virtual int Write(int channelNo, float value, bool isAllowed = false) override;
private:
	float rainfall;//channelNo 0
	int rainsensorAddress;//channelNo 1
	int TotalChannel = 2;//�����ܵ�channel����
	int result;//���ܽ��
	ModbusMaster node;//ʵ������վ�ڵ㣬�������Ϊ��վ��������Ϊ��վ
	Stream* _Myport;//���ڴ���
};


#endif // !_RaintubeSensor_h

