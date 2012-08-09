/**
 * @file   canvas.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Wed Jul 25 22:19:09 2012
 * 
 * @brief  
 * 
 * 
 */

#include "canvas.h"

Canvas::Canvas(wxWindow* parent, wxWindowID id,
			   const wxPoint& pos,
			   const wxSize& size):
	wxScrolledWindow// wxWindow
    (parent, id, pos, size),
	m_bitmap(wxBitmap())// ,
	// m_rect(wxRect(0,0,0,0))
{
  // SetMinSize(wxSize(1,1));
  // SetMinSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  // SetMaxSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  Connect(wxID_ANY, wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
  Connect(wxID_ANY, wxEVT_MOTION,
          wxMouseEventHandler(Canvas::OnMouseEvent));
  
}

void Canvas::OnPaint(wxPaintEvent & WXUNUSED(event))
{
  wxPaintDC dc(this);
  // m_rect = wxRect(0,0,
  //                 m_bitmap.GetWidth (),
  //                 m_bitmap.GetHeight ());
  dc.DrawBitmap(m_bitmap,0,0,0);
}

void Canvas::OnMouseEvent(wxMouseEvent & event)
{
  // For drawing lines in a canvas
  static long xpos = -1;
  static long ypos = -1;

  wxClientDC dc(this);
  PrepareDC(dc);

  wxPoint pt(event.GetLogicalPosition(dc));
	

  if (xpos > -1 && ypos > -1 && event.Dragging())
  {
    dc.SetPen(*wxRED_PEN);
    dc.DrawLine(xpos, ypos, pt.x, pt.y);
  }

  xpos = pt.x;
  ypos = pt.y;

  event.Skip();
}
