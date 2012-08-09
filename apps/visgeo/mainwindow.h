/**
 * @file   mainwindow.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Mon Jul 23 19:33:26 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__


#include "wx/wx.h"
#include "glcanvas.h"
#include "canvas.h"

#include "opencv/cv.h"
#include "opencv/highgui.h"

// #include "abstractimageeditdlg.h"
// #include "mainframe.h"
// #include "dlginpaint.h"

enum {
  ID_QUIT = wxID_HIGHEST+1,
  ID_ABOUT,
  ID_INPAINT,
  ID_SETTINGS
};


class MainWindow: public wxFrame
{
  wxBitmap m_bitmap;
  // TestGLCanvas m_glcanvas;
  // Canvas m_canvas;
  // MainFrame m_mainframe;
  Canvas * m_canvas;
  cv::Mat m_imgOriginal;
  // AbstractImageEditDialog * m_dlgInpaint;
  wxPanel* m_panel;
  // wxSizer * m_topsizer;
 public:

  MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);

  void OnMenuFileOpen(wxCommandEvent & event);
  void fileOpen(const wxString fn);
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnMenuToolkitInpaint(wxCommandEvent& event);
  // void OnPaint(wxPaintEvent & event);
  void OnResize(wxSizeEvent & event){
    // m_topsizer->RecalcSizes();
    // m_topsizer->Layout();
    m_panel->Refresh(false);
    m_canvas->Refresh(false);
  }
  // DECLARE_EVENT_TABLE()
};

#endif //__MAIN_WINDOW_H__
