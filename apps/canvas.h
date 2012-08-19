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
#include "opencv/cv.h"
#include "opencv/highgui.h"

#include "common.h"
#include "utility.h"

class Canvas : public wxScrolledWindow//wxWindow
{
  wxBitmap m_bitmap;        // image to be displayed on canvas (unresized)
  wxImage m_image;          // the original image

  float m_fZoomFactor;
  wxSizer * m_hsizer;       // the horizontal sizer (used in main panel)

  IplImage * m_imgOriginal; // the original input image (for image processing)
  IplImage * m_imgModifier; // the mask image for modifying original image
  std::vector<IplImage *> m_imgModified;
 protected:
  void OnMouseWheel(wxMouseEvent& event);
 public:
  Canvas(wxWindow* parent, wxWindowID id,
         const wxPoint& pos = wxDefaultPosition,
         const wxSize& size = wxDefaultSize);
  ~Canvas()
  {
    vgReleaseImage(m_imgOriginal);
    vgReleaseImage(m_imgModifier);
  }
  void loadBitmap(const wxBitmap& bitmap)
  {
    m_bitmap = wxBitmap(bitmap);
    m_image = bitmap.ConvertToImage();
    vgWxImage2CvImage(m_image, m_imgOriginal);
    {
      if (m_imgModifier!=NULL){ vgReleaseImage(m_imgModifier);}
      m_imgModifier =
          cvCreateImage(cvGetSize(m_imgOriginal), IPL_DEPTH_8U, 1);
      cvZero(m_imgModifier);
    }
    SetMinSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
    SetMaxSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
    Refresh(false);
  }
  void SetParentSizerPtr(wxSizer * sizer){m_hsizer = sizer;}
  void OnPaint(wxPaintEvent & event);
  void OnMouseMotion(wxMouseEvent & event);
  void OnMouseRelease(wxMouseEvent & event);
  //void GetSize()
};


#endif //__CANVAS_H__
