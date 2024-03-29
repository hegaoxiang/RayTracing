#include "GameTimer.h"

GameTimer::GameTimer()
	: m_SecondsPerCount(0.0), m_DeltaTime(-1.0), m_BaseTime(0), m_StopTime(0),
	m_PausedTime(0), m_PrevTime(0), m_CurrTime(0), m_Stopped(false)
{
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)& countsPerSec);
	m_SecondsPerCount = 1 / countsPerSec;
}

float GameTimer::TotalTime() const
{
	// If we are stopped,we do not need to count the time that has passed since we stopped.
	// Moreover,if we already had a pause,the distance m_StopTime - m_BaseTime includes paused time,
	// which wo do not want to count.To correct this,we can subtract the paused time form m_stopTime:
	if (m_Stopped)
	{
		return (float)(((m_StopTime - m_BaseTime) - m_PausedTime) * m_SecondsPerCount);
	}
	// Maybe we also had a pause,so we need to subtract the pause time from
	// the distance m_CurrTime - m_BaseTiem
	else
	{
		return (float)(((m_CurrTime - m_BaseTime) - m_PausedTime) * m_SecondsPerCount);
	}
}

float GameTimer::DeltaTime() const
{
	return (float)m_DeltaTime;
}

void GameTimer::Reset()
{
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)& currTime);

	m_BaseTime = currTime;
	m_PrevTime = currTime;
	m_StopTime = 0;
	m_PausedTime = 0;
	m_Stopped = false;
}

void GameTimer::Start()
{
	if (m_Stopped)
	{
		m_Stopped = false;

		// Accumulate the time elapsed between stop() and start() were called
		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)& currTime);

		m_PausedTime += currTime - m_StopTime;
		m_StopTime = 0;
	}
}

void GameTimer::Stop()
{
	if (!m_Stopped)
	{
		m_Stopped = true;

		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)& currTime);
		m_StopTime = currTime;
	}
}

void GameTimer::Tick()
{
	if (m_Stopped)
	{
		m_DeltaTime = 0.0;
		return;
	}

	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)& currTime);
	m_CurrTime = currTime;

	// Time difference between this frame and the previous.
	m_DeltaTime = (m_CurrTime - m_PrevTime) * m_SecondsPerCount;

	// Prepare for next frame.
	m_PrevTime = m_CurrTime;

	if (m_DeltaTime < 0.0)
	{
		m_DeltaTime = 0.0;
	}
}
