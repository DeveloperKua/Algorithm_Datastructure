#pragma once

class CTimeManager
{
public:
	float m_fAcculTime; //�ð� ����
	float m_fFPS;       //FPS
	float m_fTimeStep;  //�ð� ����
	float m_fFPSTime;   

	int m_nFrameCount;
	DWORD m_dwBeforeTime;

public:
	CTimeManager(void);
	virtual ~CTimeManager(void);

	bool Initialize();
	void Terminate();
	void Pulse();

public:
	__inline float GetTime() const;
	__inline float GetFPS() const;
	__inline float GetTimeStep() const;
};

__inline float CTimeManager::GetTime() const
{
	return m_fAcculTime;;
}

__inline float CTimeManager::GetFPS() const
{
	return m_fFPS;
}
__inline float CTimeManager::GetTimeStep() const
{
	return m_fTimeStep;
}