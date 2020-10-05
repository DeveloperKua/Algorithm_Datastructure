#pragma once

class CSystem : public CSingleton<CSystem>,
	public CBaseWindow,
	public CTimeManager,
	public IInputHandler

{
public:
	cMaze* myMaze;
	CInputManager*	m_pInputManager;

private:
	Vector2D m_vMouseXY;
	bool m_bIsMouseLeft;
	bool m_bIsMouseRight;
	bool m_bIsMouseMid;

public:
	CSystem(void);
	virtual ~CSystem(void);

	bool Initialize(void);
	void Update(void);
	void Terminate(void);
	void Run(void);

private:
	void KeyboardHandler();
	void MouseHandler(MOUSESTATE diMouseState);
};

#define g_pSystem	CSystem::GetSingleton()
#define WIDTH  800;
#define HEIGHT  800;
