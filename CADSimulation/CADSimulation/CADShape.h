#pragma once
class CCADShape
{
public:
  CCADShape();
  virtual ~CCADShape();

protected:
  CPoint m_objBeginPoint;
  CPoint m_objEndPoint;
  int m_nRotation;

  CPoint m_objBeginPointBefore;  //���ھ�ȷ��ק����
  CPoint m_objEndPointBefore;

  int m_nPenWidth;
  int m_nPenStyle;
  COLORREF  m_nPenColor;
  COLORREF  m_nBrushColor;

  int m_nPenWidthSwitch;
  int m_nPenStyleSwitch;
  COLORREF  m_nPenColorSwitch;
  COLORREF  m_nBrushColorSwitch;

  //bool m_bIsStyleSet;

  static CDC *m_pStaticDCMem;
  static CBitmap *m_pStaticBitmap;
  static bool m_bIsDrawingBackground;
public:
  virtual int SetBeginPoint(CPoint & objBeginPoint);
  virtual int SetEndPoint(CPoint & objEndPoint);
  virtual CDC * Draw(HWND hWnd, CDC * pDC);
  virtual int SaveThisShape(CPoint & objPoint);
  CDC * GetMemDC(HWND hWnd, CDC * pDC);
  int DrawTheBigPicture(HWND hWnd, CDC * pDC);
  int ResetMemDCBackground(HWND hWnd, CDC * pDC);
  virtual BOOL IsSelected(LPRECT pUserRect);
  int WhenSelected();
  int WhenUnselected();
  virtual int WhenDragged(int nCoordXOffset, int nCoordYOffset);
  virtual int BeforeBeingDragged();
  int AfterBeingDragged();
  int SetBrush(COLORREF color);
  int SetPen(int PenWidth, int PenStyle, COLORREF PenColor);
  int SetRotation(int nRotation);
};
