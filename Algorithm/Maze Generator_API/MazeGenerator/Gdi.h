#pragma once
#include <Windows.h> 
#include <string> 
#include <vector> 
#include <cassert> 

const int NumColors = 15;

const COLORREF colors[NumColors] = { RGB(255,0,0), //Red
								   RGB(0,0,255), //Blue
								   RGB(0,255,0), //Green
								   RGB(0,0,0), //Black
								   RGB(255,255,255), //White
								   RGB(150,150,150), //Gray
								   RGB(255,200,200), //Pink
								   RGB(255,255,0), //Yellow
								   RGB(255,170,0), //Orange
								   RGB(255,0,255), //Purple
								   RGB(133,90,0), //Brown
								   RGB(0,100,0), //Dark Green
								   RGB(0,255,255), //Cyan
								   RGB(200,200,200),//Light Gray
								   RGB(255,230,230), //Light Pink
};

#define g_pGdi CGdi::Instance() //ΩÃ±€≈Ê

class CGdi
{
private:
	HDC  m_hdcScreen, m_hdc;
	HBITMAP m_hbm;
	HPEN m_OldPen;	HPEN m_RedPen;	HPEN m_BluePen;	HPEN m_GreenPen;
	HPEN m_BlackPen;	HPEN m_WhitePen;	HPEN m_GrayPen;	HPEN m_PinkPen;
	HPEN m_YellowPen;	HPEN m_OrangePen;	HPEN m_PurplePen;	HPEN m_BrownPen;
	HPEN m_DkGreenPen;HPEN m_CyanPen;	HPEN m_LtGrayPen;	HPEN m_LtPinkPen;

	HBRUSH m_OldBrush;	HBRUSH m_RedBrush;	HBRUSH m_BlueBrush;
	HBRUSH m_GreenBrush;	HBRUSH m_BlackBrush;	HBRUSH m_WhiteBrush;
	HBRUSH m_GrayBrush;	HBRUSH m_PinkBrush;	HBRUSH m_YellowBrush;
	HBRUSH m_OrangeBrush;	HBRUSH m_PurpleBrush;	HBRUSH m_BrownBrush;
	HBRUSH m_DkGreenBrush;		HBRUSH m_CyanBrush;	
	HBRUSH m_LtGrayBrush;			HBRUSH m_LtPinkBrush;

public:
	enum	{ red, blue, green, black, white, gray, pink, yellow, 
		 orange, purple, brown, dkgreen, cyan, ltgray, ltpink};

public:
	static CGdi* Instance();

	CGdi(void);
	~CGdi(void);

	void RedPen() { if(m_hdc){ SelectObject(m_hdc, m_RedPen); } }
	void BluePen() { if(m_hdc){ SelectObject(m_hdc, m_BluePen); } }
	void GreenPen() { if(m_hdc){ SelectObject(m_hdc, m_GreenPen); } }
	void BlackPen() { if(m_hdc){ SelectObject(m_hdc, m_BlackPen); } }
	void WhitePen() { if(m_hdc){ SelectObject(m_hdc, m_WhitePen); } }
	void GrayPen() { if(m_hdc){ SelectObject(m_hdc, m_GrayPen); } }
	void PinkPen() { if(m_hdc){ SelectObject(m_hdc, m_PinkPen); } }
	void YellowPen() { if(m_hdc){ SelectObject(m_hdc, m_YellowPen); } }
	void OrangePen() { if(m_hdc){ SelectObject(m_hdc, m_OrangePen); } }
	void PurplePen() { if(m_hdc){ SelectObject(m_hdc, m_PurplePen); } }
	void BrownPen() { if(m_hdc){ SelectObject(m_hdc, m_BrownPen); } }
	void DkGreenPen() { if(m_hdc){ SelectObject(m_hdc, m_DkGreenPen); } }
	void CyanPen() { if(m_hdc){ SelectObject(m_hdc, m_CyanPen); } }
	void LtGrayPen() { if(m_hdc){ SelectObject(m_hdc, m_LtGrayPen); } }
	void LtPinkPen() { if(m_hdc){ SelectObject(m_hdc, m_LtPinkPen); } }

	void RedBrush() { if(m_hdc){ SelectObject(m_hdc, m_RedBrush); } }
	void BlueBrush() { if(m_hdc){ SelectObject(m_hdc, m_BlueBrush); } }
	void GreenBrush() { if(m_hdc){ SelectObject(m_hdc, m_GreenBrush); } }
	void BlackBrush() { if(m_hdc){ SelectObject(m_hdc, m_BlackBrush); } }
	void WhiteBrush() { if(m_hdc){ SelectObject(m_hdc, m_WhiteBrush); } }
	void GrayBrush() { if(m_hdc){ SelectObject(m_hdc, m_GrayBrush); } }
	void PinkBrush() { if(m_hdc){ SelectObject(m_hdc, m_PinkBrush); } }
	void YellowBrush() { if(m_hdc){ SelectObject(m_hdc, m_YellowBrush); } }
	void OrangeBrush() { if(m_hdc){ SelectObject(m_hdc, m_OrangeBrush); } }
	void PurpleBrush() { if(m_hdc){ SelectObject(m_hdc, m_PurpleBrush); } }
	void BrownBrush() { if(m_hdc){ SelectObject(m_hdc, m_BrownBrush); } }
	void DkGreenBrush() { if(m_hdc){ SelectObject(m_hdc, m_DkGreenBrush); } }
	void CyanBrush() { if(m_hdc){ SelectObject(m_hdc, m_CyanBrush); } }
	void LtGrayBrush() { if(m_hdc){ SelectObject(m_hdc, m_LtGrayBrush); } }
	void LtPinkBrush() { if(m_hdc){ SelectObject(m_hdc, m_LtPinkBrush); } }

	void StartDraw(HDC hdc);
	void StopDraw(HDC hdc);
	void Blt(void);

	void SetPenColor(int color);
	void SetBrushColor(int color);

	void Rect(int l, int t, int r, int b);
	void Rect(float l, float t, float r, float b);
	void Circle(int l, int t, int r, int b);
	void Circle(float l, float t, float r, float b);
	void Circle(int x, int y, int r);
	void Circle(float x, float y, float r);

	void TextAtPos(int x, int y, const TCHAR* text);
	//void TextAtPos(int x, int y, const char* text);
	//void TextAtPos(int x, int y, const std::string& s);
	//void TextAtPos(float x, float y, const std::string& s);
//	void TextAtPos(Vector2D pos, const std::string& s);
	inline void TransparentText() { SetBkMode( m_hdc, TRANSPARENT ); }
	inline void OpaqueText() { SetBkMode( m_hdc, OPAQUE); }
	inline void TextAlignCenter() { SetTextAlign( m_hdc, TA_CENTER ); }
	inline void TextAlignVCenter() { SetTextAlign( m_hdc, VTA_CENTER ); }
	inline void TextAlignLeft() { SetTextAlign( m_hdc, TA_LEFT ); }
	inline void TextAlignRight() { SetTextAlign( m_hdc, TA_RIGHT ); }
	inline void TextColor(int color){ SetTextColor(m_hdc, colors[color]); }
	inline void TextColor(BYTE r, BYTE g, BYTE b) { SetTextColor(m_hdc, RGB(r,g,b));}

//	void DrawDot(Vector2D pos, COLORREF color);
	void DrawDot(int x, int y, COLORREF color);
	void DrawDot(float x, float y, COLORREF color);

//	void Line(Vector2D from, Vector2D to);
	void Line(int x1, int y1, int x2, int y2);
	void Line(float x1, float y1, float x2, float y2);
//	void PolyLine(const std::vector<Vector2D>& points);

//	void Cross(Vector2D pos, int diameter);
//	void LineWithArrow(Vector2D from, Vector2D to, float fsize);
//	void LineWithCircle(Vector2D from, Vector2D to, float fsize);

public:
	__inline const HDC GetDrawDC() { return m_hdc; }
};

