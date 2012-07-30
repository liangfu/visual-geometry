/**
 * @file   abstractcanvas.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sat Jul 28 21:59:55 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __ABSTRACT_CANVAS_H__
#define __ABSTRACT_CANVAS_H__

#include "common.h"
#include "wx/wx.h"

class AbstractCanvas : public wxWindow
{
	wxBitmap m_bitmap;
public:
	AbstractCanvas(){}
	AbstractCanvas(wxWindow* parent, wxWindowID id,
				   const wxPoint& pos = wxDefaultPosition,
				   const wxSize& size = wxDefaultSize);
	void OnPaint(wxPaintEvent & event);
	void loadBitmap(const wxBitmap& bitmap){
		m_bitmap = bitmap;
		Refresh(false);
	}

};

#endif //__ABSTRACT_CANVAS_H__
