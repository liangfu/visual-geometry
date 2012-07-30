/**
 * @file   abstractcanvas.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sat Jul 28 22:00:03 2012
 * 
 * @brief  
 * 
 * 
 */

#include "abstractcanvas.h"

AbstractCanvas::AbstractCanvas(wxWindow* parent, wxWindowID id,
							   const wxPoint& pos,
							   const wxSize& size):
    wxWindow(parent, id, pos, size),
	m_bitmap(wxBitmap())
	
{
	Connect(wxID_ANY, wxEVT_PAINT,
			wxPaintEventHandler(AbstractCanvas::OnPaint));
}

void AbstractCanvas::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	// wxRect m_rect = wxRect((GetSize().GetWidth() - m_bitmap.GetWidth ())/2.,
	// 					   (GetSize().GetHeight()- m_bitmap.GetHeight())/2.,
	// 					   m_bitmap.GetWidth (),
	// 					   m_bitmap.GetHeight ());
	dc.DrawBitmap(m_bitmap,
				  0,0, 0);
}
