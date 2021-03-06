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

#define vgShow(im)                              \
  cvShowImage((#im), (im))

/** 
 * release IplImage with NULL reference check
 * 
 * @param im IN:OUT: image to be released
 */
inline void vgReleaseImage(IplImage *& im)
{
  if (im!=NULL){ cvReleaseImage(&im); im = NULL; }
}

/** 
 * convert IplImage to wxImage type
 * 
 * @param cvimage IN: IplImage to be converted
 * @param wximage OUT: wxImage output 
 */
inline void vgCvImage2WxImage(const IplImage * const cvimage,
                              wxImage & wximage)
{
  assert(cvimage->nChannels==3);
  assert(cvimage->depth==8);
  IplImage * rgb = cvCreateImage(cvGetSize(cvimage), IPL_DEPTH_8U, 3);
  cvCvtColor(cvimage, rgb, CV_BGR2RGB);

  unsigned char * pImgData =
      (unsigned char*)malloc(sizeof(unsigned char)*rgb->width*rgb->height*3);
  memcpy(pImgData, rgb->imageData,
         sizeof(unsigned char)*rgb->width*rgb->height*3);
  wximage = wxImage(rgb->width, rgb->height, (unsigned char*)pImgData, false);
  // free(pImgData); // WE DO NOT HAVE TO RELEASE MEMORY HERE -------> ^^^^^
  // wxWidget will automatically release the memory for us
  vgReleaseImage(rgb);
}

inline void vgWxImage2CvImage(const wxImage wximage, IplImage *& cvimage)
{
  vgReleaseImage(cvimage);
  cvimage = cvCreateImage(cvSize(wximage.GetWidth(), wximage.GetHeight()),
                          IPL_DEPTH_8U, 3);
  IplImage * imgTemp =
      cvCreateImage(cvGetSize(cvimage), IPL_DEPTH_8U, 3);
  // wxImage returns RGBRGBRGB... format
  memcpy(imgTemp->imageData, wximage.GetData(), 
         sizeof(uchar)*wximage.GetWidth()*wximage.GetHeight()*3);
  cvCvtColor(imgTemp, cvimage, CV_RGB2BGR);//vgShow(cvimage);
}

// inline void vgCvImage2WxImage(const cv::Mat cvimage, wxImage & wximage)
// {
//   cv::Mat rgb;
//   cv::cvtColor(cvimage, rgb, CV_BGR2RGB);
//   wximage = wxImage(rgb.cols, rgb.rows, rgb.data);
// }

// inline void vgWxImage2CvImage(const wxImage wximage, cv::Mat & cvimage)
// {
//   cvimage = cv::Mat::Mat(wximage.GetHeight(), wximage.GetWidth(),
//                          CV_8UC3);
//   // wxImage returns RGBRGBRGB... format
//   memcpy(cvimage.data, wximage.GetData(), 
//          sizeof(uchar)*wximage.GetWidth()*wximage.GetHeight()*3);
//   cv::cvtColor(cvimage, cvimage, CV_RGB2BGR);
// }


#endif //__UTILITY_H__
