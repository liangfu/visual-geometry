/**
 * @file   mainframe.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Fri Jul 27 00:21:24 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __MAIN_FRAME_H__
#define __MAIN_FRAME_H__

#include "wx/wx.h"
#include "canvas.h"

class MainFrame : public wxWindow
{
	wxBitmap m_bitmap;
	Canvas m_canvas;
	wxRect m_rect;
public:
	MainFrame(wxWindow* parent, wxWindowID id,
		   const wxPoint& pos = wxDefaultPosition,
		   const wxSize& size = wxDefaultSize);
	void loadBitmap(const wxBitmap& bitmap){
		m_bitmap = wxBitmap(bitmap);
		Refresh(false);
	}
	void OnPaint(wxPaintEvent & event);
	void OnMouseEvent(wxMouseEvent & event);
};


#endif //__MAIN_FRAME_H__
