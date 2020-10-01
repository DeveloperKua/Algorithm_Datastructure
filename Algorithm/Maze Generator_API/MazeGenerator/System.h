#pragma once

class CSystem : public CSingleton<CSystem>,
	public CBaseWindow,
	public CTimeManager

{
public:
	cMaze* myMaze;

public:
	CSystem(void);
	virtual ~CSystem(void);

	bool Initialize(void);
	void Update(void);
	void Terminate(void);
	void Run(void);
};

#define WIDTH  800;
#define HEIGHT  800;
