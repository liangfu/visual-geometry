/** 
 * @file   mainframe.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Fri Jul 27 00:09:56 2012
 * 
 * @brief  
 * 
 * 
 */

#include "mainframe.h"
#include "canvas.h"

MainFrame::MainFrame(wxWindow* parent, wxWindowID id,
					 const wxPoint& pos,
					 const wxSize& size):
	wxWindow(parent, id, pos, size),
	m_bitmap(wxBitmap()),
	// m_canvas(this, id,
	// 				wxPoint((GetSize().GetWidth() - m_bitmap.GetWidth ())/2.,
	// 						(GetSize().GetHeight()- m_bitmap.GetHeight())/2.),
	// 				wxSize(m_bitmap.GetWidth (),
	// 					   m_bitmap.GetHeight())),
	m_rect(wxRect(0,0,0,0))
{
	Connect(wxID_ANY, wxEVT_PAINT,
			wxPaintEventHandler(MainFrame::OnPaint));
	// Connect(wxID_ANY, wxEVT_MOTION,
	// 		wxMouseEventHandler(MainFrame::OnMouseEvent));
}

void MainFrame::OnPaint(wxPaintEvent & WXUNUSED(event))
{
	wxPaintDC dc(this);
	m_rect = wxRect((GetSize().GetWidth() - m_bitmap.GetWidth ())/2.,
					(GetSize().GetHeight()- m_bitmap.GetHeight())/2.,
					m_bitmap.GetWidth (),
					m_bitmap.GetHeight ());
	dc.DrawBitmap(m_bitmap,
				  m_rect.x, m_rect.y, 0);
}

// void MainFrame::OnMouseEvent(wxMouseEvent & event)
// {
// 	// For drawing lines in a canvas
// 	static long xpos = -1;
// 	static long ypos = -1;

// 	wxClientDC dc(this);
//     PrepareDC(dc);

//     wxPoint pt(event.GetLogicalPosition(dc));
	

//     if (xpos > -1 && ypos > -1 && event.Dragging())
//     {
//         // dc.SetPen(*wxRED_PEN);
//         // dc.DrawLine(xpos, ypos, pt.x, pt.y);
//     }

//     xpos = pt.x;
//     ypos = pt.y;

// 	event.Skip();
// }
