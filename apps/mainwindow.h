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
#include "wx/aui/aui.h"
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
  wxAuiManager m_mgr;
  
  wxMenuBar * m_menuBar;
  wxToolBar * m_toolBar;
  wxBitmap m_bitmap;
  Canvas * m_canvas;

  cv::Mat m_imgOriginal;
  wxImage m_image;
  wxImage m_imgResized;

  wxPanel* m_panel;
  wxSizer * m_hsizer;

  void initMenuBar();
  void initToolBars();
  void initMainPanel();
  void initEvents();

 protected:
  // void OnMouseWheel(wxMouseEvent& event);
  void OnMenuFileOpen(wxCommandEvent & event);
  void OnMenuFileSave(wxCommandEvent & event);
  void OnMenuFileSaveAs(wxCommandEvent & event);
  
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnMenuToolkitInpaint(wxCommandEvent& event);
  void OnResize(wxSizeEvent & event)
  {
    m_panel->Refresh(false);
    m_canvas->Refresh(false);
  }
  
 public:

  MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
  ~MainWindow()
  {
    m_mgr.UnInit();
  }
  void fileOpen(const wxString fn);
};

#endif //__MAIN_WINDOW_H__
