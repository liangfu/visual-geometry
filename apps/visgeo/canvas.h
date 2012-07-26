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
	wxRect m_rect;
public:
	Canvas(wxWindow* parent, wxWindowID id,
		   const wxPoint& pos = wxDefaultPosition,
		   const wxSize& size = wxDefaultSize);
	void loadBitmap(const wxBitmap& bitmap){
		m_bitmap = wxBitmap(bitmap);
		Refresh(false);
	}
	void OnPaint(wxPaintEvent & event);
	void OnMouseEvent(wxMouseEvent & event);
};


#endif //__CANVAS_H__
