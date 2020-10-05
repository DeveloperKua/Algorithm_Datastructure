#pragma once
class CInputManager : public CSingleton<CInputManager>
{
private:
	IInputHandler* m_pCurInputHandler;

public:
	char m_OldKeyState[256];
	char m_CurKeyState[256];
	MOUSESTATE m_diMouseState;

public:
	CInputManager(void);
	virtual ~CInputManager(void);

private:
	void Keyboard();
	void Mouse();

public:
	bool Initialize();
	void Terminate();
	void Pulse();

public:
	__inline void SetInputHandler(IInputHandler* pInputHandler);
	__inline IInputHandler* GetInputHandler() const;
};


__inline void CInputManager::SetInputHandler(IInputHandler* pInputHandler)
{
	m_pCurInputHandler = pInputHandler;
}

__inline IInputHandler* CInputManager::GetInputHandler() const
{
	return m_pCurInputHandler;
}

#define g_pInputManager	CInputManager::GetSingleton()

#define g_pKeyCodeScan(vk) (g_pInputManager->m_OldKeyState[vk]&&g_pInputManager->m_CurKeyState[vk])
