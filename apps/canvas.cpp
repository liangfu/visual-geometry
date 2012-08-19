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
	wxScrolledWindow
    (parent, id, pos, size),
	m_bitmap(wxBitmap()),
	// m_rect(wxRect(0,0,0,0))
    m_fZoomFactor(0.0f),
    m_hsizer(NULL),
    m_imgOriginal(NULL),
    m_imgModifier(NULL)
{
  // SetMinSize(wxSize(1,1));
  // SetMinSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  // SetMaxSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
  Connect(wxID_ANY, wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
  Connect(wxID_ANY, wxEVT_MOTION,
          wxMouseEventHandler(Canvas::OnMouseMotion));
  Connect(wxID_ANY, wxEVT_LEFT_UP,
          wxMouseEventHandler(Canvas::OnMouseRelease));
  Connect(wxID_ANY, wxEVT_MOUSEWHEEL,
          wxMouseEventHandler(Canvas::OnMouseWheel));
}

void Canvas::OnPaint(wxPaintEvent & WXUNUSED(event))
{
  wxPaintDC dc(this);
  wxImage imgResized = m_image.Scale(m_image.GetWidth() *(1.f+m_fZoomFactor),
                                     m_image.GetHeight()*(1.f+m_fZoomFactor));
  if (imgResized.GetHeight()<0x00f || imgResized.GetWidth()<0x00f ||
      imgResized.GetHeight()>0xfff || imgResized.GetWidth()>0xfff)
  {
    return;
  } // maximum resolution (4095x4095) 16,769,025 
  wxBitmap m_bmDisplay = wxBitmap(imgResized);
  dc.DrawBitmap(m_bmDisplay,0,0,0);
}

void Canvas::OnMouseRelease(wxMouseEvent & event)
{
  m_imgModified.push_back(cvCloneImage(m_imgOriginal));
  cvInpaint(m_imgOriginal, m_imgModifier, m_imgModified.back(),
            3, CV_INPAINT_NS);
  wxImage modified;// = vgCvImage2WxImage(m_imgModified.back());
  vgCvImage2WxImage(m_imgModified.back(), modified);
  
  m_bitmap = wxBitmap(modified);
  m_image = m_bitmap.ConvertToImage();
  m_image.Scale(m_image.GetWidth() *(1.f+m_fZoomFactor),
                m_image.GetHeight()*(1.f+m_fZoomFactor));
  m_hsizer->Layout();
  Refresh(false);
  event.Skip();
}

void Canvas::OnMouseMotion(wxMouseEvent & event)
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
    //dc.DrawLine(xpos, ypos, pt.x, pt.y);
    cvLine(m_imgModifier,
           cvPoint(xpos/(m_fZoomFactor+1.0f), ypos/(m_fZoomFactor+1.0f)),
           cvPoint(pt.x/(m_fZoomFactor+1.0f), pt.y/(m_fZoomFactor+1.0f)),
           cvScalar(255,255,255), 5);
    vgShow(m_imgModifier);
  }

  xpos = pt.x;
  ypos = pt.y;

  event.Skip();
}

void Canvas::OnMouseWheel(wxMouseEvent& event)
{
  m_fZoomFactor += event.GetWheelRotation()/event.GetWheelDelta()*0.01f;

  wxSize size =
      wxSize(m_image.GetWidth () *(1.f+m_fZoomFactor),
             m_image.GetHeight() *(1.f+m_fZoomFactor));
  
  if (size.GetHeight() < 0x00f || (size.GetWidth()) < 0x00f ||
      size.GetHeight() > 0xfff || (size.GetWidth()) > 0xfff)
  {
    return;
  } // maximum resolution (4095x4095) 16,769,025 

  SetMinSize(size);
  SetMaxSize(size);

  Refresh(false);
  m_hsizer->Layout();

  event.Skip();
}
