/**
 * @file   canvas.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Tue Jul 24 00:02:29 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "wx/wx.h"

class Canvas : public wxWindow
{
	wxBitmap m_bitmap;
public:
	Canvas(wxWindow* parent, wxWindowID id,
		   const wxPoint& pos = wxDefaultPosition,
		   const wxSize& size = wxDefaultSize):
		wxWindow(parent, id),
		m_bitmap(wxBitmap())
	{
		Connect(wxID_ANY, wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
	}
	void loadBitmap(const wxBitmap& bitmap){
	fprintf(stderr, "%s\n", __func__);
		m_bitmap = wxBitmap(bitmap);
		Refresh(false);
	}
	void OnPaint(wxPaintEvent & WXUNUSED(event))
	{
	fprintf(stderr, "%s\n", __func__);
		wxPaintDC dc(this);
		dc.DrawBitmap(m_bitmap,0,0,0);
	}
};


#endif //__CANVAS_H__
