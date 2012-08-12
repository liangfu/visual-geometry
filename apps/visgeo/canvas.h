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
  wxBitmap m_bitmap;        // image to be displayed on canvas
  wxImage m_image;          // the original image 
  // wxRect m_rect;
  float m_fZoomFactor;
  wxSizer * m_hsizer;       // the horizontal sizer (used in main panel)

  cv::Mat m_imgOriginal;    // the original input image (for image processing)
  cv::Mat m_imgModifier;    // the mask image for modifying original image
 protected:
  void OnMouseWheel(wxMouseEvent& event);
 public:
  Canvas(wxWindow* parent, wxWindowID id,
         const wxPoint& pos = wxDefaultPosition,
         const wxSize& size = wxDefaultSize);
  void loadBitmap(const wxBitmap& bitmap)
  {
    m_bitmap = wxBitmap(bitmap);
    m_image = bitmap.ConvertToImage();
    vgWxImage2CvImage(m_image, m_imgOriginal);
    SetMinSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
    SetMaxSize(wxSize(m_bitmap.GetWidth(), m_bitmap.GetHeight()));
    Refresh(false);
  }
  void SetParentSizerPtr(wxSizer * sizer){m_hsizer = sizer;}
  void OnPaint(wxPaintEvent & event);
  void OnMouseEvent(wxMouseEvent & event);
  //void GetSize()
};


#endif //__CANVAS_H__
