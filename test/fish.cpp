/**
 * @file   fish.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sat Aug 25 10:25:57 2012
 * 
 * @brief  
 * 
 * 
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <stdio.h>
#include <stdlib.h>

#define NNODES 6

float fBodyWidth [] = {3.0f,  2.0f,  2.0f,  1.0f,  0.0f};
float fBodyLength[] = {10.0f, 10.0f, 10.0f, 10.0f, 10.0f};

class FishModel
{
  IplImage * m_display;

  CvPoint & m_head;
  CvPoint m_bodynode[NNODES];
  CvPoint & m_tail;
 public:
  FishModel():
      m_head(m_bodynode[0]),
      m_tail(m_bodynode[5])
  {
    m_head = cvPoint(20.0f, 20.0f);
    for (int i = 0; i < 5; i++){
      m_bodynode[i+1] = cvPoint(m_bodynode[i].x,
                                m_bodynode[i].y+fBodyLength[i]*1.0f);
    }
  }

  void Swim()
  {
    m_display = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);
    cvSet(m_display, CV_RGB(255, 255, 255));

    for (int i = 0; i < 6; i++)
    {
      cvLine(m_display, m_bodynode[i], m_bodynode[i+1], CV_RGB(255,0,0));
    }

    cvShowImage("Fish", m_display);
    int k = 0;
    while(k!='q'){k = cvWaitKey();}
  }
  
};

int main()
{
  FishModel fish;
  fish.Swim();
  return 0;
}
