#pragma once
#include <windows.h>

class GameTimer
{
public:
	GameTimer();

	float TotalTime()const;		// ����Ϸʱ��
	float DeltaTime()const;		// ֡���ʱ��

	void Reset();               // ����Ϣѭ��֮ǰ����
	void Start();               // ��ȡ����ͣ��ʱ�����
	void Stop();                // ����ͣ��ʱ�����
	void Tick();                // ��ÿһ֡��ʱ�����

private:

	double m_SecondsPerCount;
	double m_DeltaTime;
	
	__int64 m_BaseTime;
	__int64 m_PausedTime;
	__int64 m_StopTime;
	__int64 m_PrevTime;
	__int64 m_CurrTime;

	bool m_Stopped;
};