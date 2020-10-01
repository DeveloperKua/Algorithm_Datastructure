#include "StdAfx.h"
#include "Gdi.h"

CGdi* CGdi::Instance()
{
  static CGdi instance;
  return &instance;
} 

CGdi::CGdi(void)
{
	m_RedPen	= CreatePen(PS_SOLID, 1, colors[red]);
	m_BluePen	= CreatePen(PS_SOLID, 1, colors[blue]);
	m_GreenPen	= CreatePen(PS_SOLID, 1, colors[green]);
	m_BlackPen	= CreatePen(PS_SOLID, 1, colors[black]);
	m_WhitePen	= CreatePen(PS_SOLID, 1, colors[white]);
	m_GrayPen	= CreatePen(PS_SOLID, 1, colors[gray]);
	m_PinkPen	= CreatePen(PS_SOLID, 1, colors[pink]);
	m_YellowPen	= CreatePen(PS_SOLID, 1, colors[yellow]);
	m_OrangePen	= CreatePen(PS_SOLID, 1, colors[orange]);
	m_PurplePen	= CreatePen(PS_SOLID, 1, colors[purple]);
	m_BrownPen	= CreatePen(PS_SOLID, 1, colors[brown]);
	m_DkGreenPen = CreatePen(PS_SOLID, 1, colors[dkgreen]);
	m_CyanPen	= CreatePen(PS_SOLID, 1, colors[cyan]);
	m_LtGrayPen	= CreatePen(PS_SOLID, 1, colors[ltgray]);
	m_LtPinkPen	= CreatePen(PS_SOLID, 1, colors[ltpink]);

	m_RedBrush =		CreateSolidBrush(colors[red]);
	m_BlueBrush =	CreateSolidBrush(colors[blue]);
	m_GreenBrush =	CreateSolidBrush(colors[green]);
	m_BlackBrush =	CreateSolidBrush(colors[black]);
	m_WhiteBrush =	CreateSolidBrush(colors[white]);
	m_GrayBrush =	CreateSolidBrush(colors[gray]);
	m_PinkBrush =	CreateSolidBrush(colors[pink]);
	m_YellowBrush =	CreateSolidBrush(colors[yellow]);
	m_OrangeBrush =	CreateSolidBrush(colors[orange]);
	m_PurpleBrush =	CreateSolidBrush(colors[purple]);
	m_BrownBrush =	CreateSolidBrush(colors[brown]);
	m_DkGreenBrush = CreateSolidBrush(colors[dkgreen]);
	m_CyanBrush =	CreateSolidBrush(colors[cyan]);
	m_LtGrayBrush =	CreateSolidBrush(colors[ltgray]);
	m_LtPinkBrush =	CreateSolidBrush(colors[ltpink]);

	m_hdc = NULL;
}


CGdi::~CGdi(void)
{
	DeleteObject(m_RedPen	);
	DeleteObject(m_BluePen);	
	DeleteObject(m_GreenPen);	
	DeleteObject(m_BlackPen);	
	DeleteObject(m_WhitePen);	
	DeleteObject(m_GrayPen);	
	DeleteObject(m_PinkPen);	
	DeleteObject(m_YellowPen);	
	DeleteObject(m_OrangePen);	
	DeleteObject(m_PurplePen);	
	DeleteObject(m_BrownPen);	
	DeleteObject(m_DkGreenPen); 
	DeleteObject(m_CyanPen);	
	DeleteObject(m_LtGrayPen);	
	DeleteObject(m_LtPinkPen);	

	DeleteObject(m_RedBrush);
	DeleteObject(m_BlueBrush);	
	DeleteObject(m_GreenBrush);	
	DeleteObject(m_BlackBrush);	
	DeleteObject(m_WhiteBrush);	
	DeleteObject(m_GrayBrush);	
	DeleteObject(m_PinkBrush);	
	DeleteObject(m_YellowBrush);	
	DeleteObject(m_OrangeBrush);	
	DeleteObject(m_PurpleBrush);	
	DeleteObject(m_BrownBrush);	
	DeleteObject(m_DkGreenBrush); 
	DeleteObject(m_CyanBrush);	
	DeleteObject(m_LtGrayBrush);	
	DeleteObject(m_LtPinkBrush);	

}

extern RECT rtSystem;
void CGdi::StartDraw(HDC hdc)
{
    assert(hdc != NULL);
   
	m_hdcScreen = hdc;
    m_hdc = CreateCompatibleDC( m_hdcScreen );
	m_hbm = CreateCompatibleBitmap( m_hdcScreen, 810, 810 );
	SelectObject( m_hdc, m_hbm );

    m_OldPen = (HPEN)SelectObject(hdc, m_BlackPen);
    SelectObject(hdc, m_OldPen);
    m_OldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(WHITE_BRUSH));
    SelectObject(hdc, m_OldBrush);
}

void CGdi::StopDraw(HDC hdc)
{
    assert(hdc != NULL);
    
	DeleteObject( m_hbm );
	ReleaseDC( NULL, m_hdc );
    SelectObject(hdc, m_OldPen);
    SelectObject(hdc, m_OldBrush);

    m_hdc = NULL;
}

void CGdi::Blt()
{
	BitBlt( m_hdcScreen, 0, 0, 810, 810, m_hdc, 0, 0, SRCCOPY );
}

void CGdi::Rect(int l, int t, int r, int b)
{
	Rectangle( m_hdc, l, t, r, b);
}

void CGdi::Rect(float l, float t, float r, float b)
{
	Rectangle( m_hdc, (int)l, (int)t, (int)r, (int)b);
}

void CGdi::Circle(int l, int t, int r, int b)
{
	Ellipse( m_hdc, l, t, r, b);
}

void CGdi::Circle(float l, float t, float r, float b)
{
	Ellipse( m_hdc, (int)l, (int)t, (int)r, (int)b);
}

void CGdi::Circle(int x, int y, int r)
{
	Ellipse( m_hdc, x-r, y-r, x+r, y+r);
}

void CGdi::Circle(float x, float y, float r)
{
	Ellipse( m_hdc, (int)(x-r), (int)(y-r), (int)(x+r), (int)(y+r));
}

void CGdi::SetPenColor(int color)
{
	switch(color)
	{
	case red:		RedPen();	break;
	case blue:		BluePen();	break;
	case green:		GreenPen();	break;
	case black:		BlackPen();	break;
	case white:		WhitePen();	break;
	case gray:		GrayPen();	break;
	case pink:		PinkPen();	break;
	case yellow:		YellowPen();	break;
	case orange:		OrangePen();	break;
	case purple:		PurplePen();	break;
	case brown:		BrownPen();	break;
	case dkgreen:	DkGreenPen();break;
	case cyan:		CyanPen();	break;
	case ltgray:		LtGrayPen();	break;
	case ltpink:		LtPinkPen();	break;
	}
}

void CGdi::SetBrushColor(int color)
{
	switch(color)
	{
	case red:		RedBrush();		break;
	case blue:		BlueBrush();		break;
	case green:		GreenBrush();	break;
	case black:		BlackBrush();	break;
	case white:		WhiteBrush();	break;
	case gray:		GrayBrush();		break;
	case pink:		PinkBrush();		break;
	case yellow:		YellowBrush();	break;
	case orange:		OrangeBrush();	break;
	case purple:		PurpleBrush();	break;
	case brown:		BrownBrush();	break;
	case dkgreen:	DkGreenBrush();	break;
	case cyan:		CyanBrush();		break;
	case ltgray:		LtGrayBrush();	break;
	case ltpink:		LtPinkBrush();	break;
	}
}

//===============================================
//TextOut
void CGdi::TextAtPos(int x, int y, const TCHAR* text)
{
	TextOut(m_hdc, x, y, text, lstrlen(text));
}
//void CGdi::TextAtPos(int x, int y, const char* text)
//{
//	TextOut( m_hdc, x, y, text, strlen(text) );
//}
//
//void CGdi::TextAtPos(int x, int y, const std::string& s)
//{
//	TextOut( m_hdc, x, y, s.c_str(), (int)s.size() );
//}
//
//void CGdi::TextAtPos(float x, float y, const std::string& s)
//{
//	TextOut( m_hdc, (int)x, (int)y, s.c_str(), (int)s.size() );
//}

//void CGdi::TextAtPos(Vector2D pos, const std::string& s)
//{
//	TextOut( m_hdc, (int)pos.x, (int)pos.y, s.c_str(), (int)s.size() );
//}

//===============================================
// Draw Pixel
//void CGdi::DrawDot(Vector2D pos, COLORREF color)
//{
//	SetPixel( m_hdc, (int)pos.x, (int)pos.y, color );
//}

void CGdi::DrawDot(int x, int y, COLORREF color)
{
	SetPixel( m_hdc, x, y, color );
}

void CGdi::DrawDot(float x, float y, COLORREF color)
{
	SetPixel( m_hdc, (int)x, (int)y, color );
}

//===============================================
// Draw Line
//void CGdi::Line(Vector2D from, Vector2D to)
//{
//	MoveToEx( m_hdc, (int)from.x, (int)from.y, NULL );
//	LineTo( m_hdc, (int)to.x, (int)to.y );
//}

void CGdi::Line(int x1, int y1, int x2, int y2)
{
	MoveToEx( m_hdc, x1, y1, NULL );
	LineTo( m_hdc, x2, y2 );
}

void CGdi::Line(float x1, float y1, float x2, float y2)
{
	MoveToEx( m_hdc, (int)x1, (int)y1, NULL );
	LineTo( m_hdc, (int)x2, (int)y2 );
}
/*
void CGdi::PolyLine( const std::vector<Vector2D>& points)
{
	if( points.size() < 2 ) return;
	MoveToEx( m_hdc, (int)points[0].x, (int)points[0].y, NULL );
	for(int p = 1; p < points.size(); ++p)
	{
		LineTo( m_hdc, (int)points[p].x, (int)points[p].y );
	}
}

void CGdi::Cross(Vector2D pos, int diameter)
{
	Line(pos.x - diameter, pos.y - diameter, pos.x + diameter, pos.y + diameter);
	Line(pos.x - diameter, pos.y + diameter, pos.x + diameter, pos.y - diameter);
}

void CGdi::LineWithArrow(Vector2D from, Vector2D to, float fsize)
{
	Vector2D norm = Vec2DNormalize( to - from );
	Vector2D CrossingPoint = to - (norm * fsize);
	Vector2D ArrowPoint1 = CrossingPoint + ( norm.Perp() * 0.4f * fsize);
	Vector2D ArrowPoint2 = CrossingPoint - ( norm.Perp() * 0.4f * fsize);

	MoveToEx( m_hdc, (int)from.x, (int)from.y, NULL);
	LineTo( m_hdc, (int)CrossingPoint.x, (int)CrossingPoint.y);

	POINT	p[3];
	p[0] = VectorToPOINT( ArrowPoint1 );
	p[1] = VectorToPOINT( ArrowPoint2 );
	p[2] = VectorToPOINT( to );

	SetPolyFillMode( m_hdc, WINDING );
	Polygon( m_hdc, p, 3);
}

void CGdi::LineWithCircle(Vector2D from, Vector2D to, float fsize)
{
	Vector2D norm = Vec2DNormalize( to - from );
	Vector2D CrossingPoint = to - (norm * fsize);

	MoveToEx( m_hdc, (int)from.x, (int)from.y, NULL);
	LineTo( m_hdc, (int)CrossingPoint.x, (int)CrossingPoint.y);
	POINT p;
	p = VectorToPOINT( CrossingPoint );
	SetPolyFillMode( m_hdc, WINDING );
	this->Circle(p.x, p.y, (int)fsize);

}
//*/