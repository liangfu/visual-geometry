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
	m_bitmap(wxBitmap()),// ,
	// m_rect(wxRect(0,0,0,0))
    m_fZoomFactor(0.0f),
    m_hsizer(NULL)
{
  // SetMinSize(wxSize(1,1));
  // SetMinSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  // SetMaxSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  Connect(wxID_ANY, wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
  Connect(wxID_ANY, wxEVT_MOTION,
          wxMouseEventHandler(Canvas::OnMouseEvent));
  Connect(wxID_ANY, wxEVT_MOUSEWHEEL,
          wxMouseEventHandler(Canvas::OnMouseWheel));
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

void Canvas::OnMouseWheel(wxMouseEvent& event)
{
  //notify("%d", event.GetWheelRotation()/event.GetWheelDelta());
  //static float factor = 0.f;
  m_fZoomFactor += event.GetWheelRotation()/event.GetWheelDelta()*0.01f;
  wxImage imgResized = m_image.Scale(m_image.GetWidth() *(1.f+m_fZoomFactor),
                                     m_image.GetHeight()*(1.f+m_fZoomFactor));
  if (imgResized.GetHeight()<0x00f || imgResized.GetWidth()<0x00f ||
      imgResized.GetHeight()>0xfff || imgResized.GetWidth()>0xfff){
    return; } // maximum resolution (4095x4095) 16,769,025 
  m_bitmap = wxBitmap(imgResized);
  notify("%d, %d", m_bitmap.GetWidth(), m_bitmap.GetHeight());

  SetMinSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  SetMaxSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  //  GetSizer()->Layout();
  m_hsizer->Layout();
  Refresh(false);
}
