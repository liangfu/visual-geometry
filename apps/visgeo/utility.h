/**
 * @file   utility.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sat Aug  4 22:15:57 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "wx/wx.h"
#include "opencv/cv.h"
#include <cstdio>
#include <cstdlib>

inline void vgCvImage2WxImage(const cv::Mat cvimage, wxImage & wximage)
{
  cv::Mat rgb;
  cv::cvtColor(cvimage, rgb, CV_BGR2RGB);
  wximage = wxImage(rgb.cols, rgb.rows, rgb.data);
}

inline void vgWxImage2CvImage(const wxImage wximage, cv::Mat & cvimage)
{
  cvimage = cv::Mat::Mat(wximage.GetHeight(), wximage.GetWidth(),
                         CV_8UC3);
  // wxImage returns RGBRGBRGB... format
  memcpy(cvimage.data, wximage.GetData(), 
         sizeof(uchar)*wximage.GetWidth()*wximage.GetHeight()*3);
  cv::cvtColor(cvimage, cvimage, CV_RGB2BGR);
}


#endif //__UTILITY_H__
