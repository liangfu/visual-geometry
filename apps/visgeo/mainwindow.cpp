/**
 * @file   mainwindow.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Mon Jul 30 01:24:18 2012
 * 
 * @brief  
 * 
 * 
 */

#include "common.h"
#include "mainwindow.h"

#include "res/new.xpm"
#include "res/open.xpm"
#include "res/save.xpm"
#include "res/inpaint.xpm"
#include "res/settings.xpm"

#include <wx/numdlg.h>

MainWindow::MainWindow(const wxString& title,
                       const wxPoint& pos,
                       const wxSize& size)
	: wxFrame( NULL, -1, title, pos, size ),
      m_menuBar(NULL),
      m_toolBar(NULL),
	  m_bitmap(wxBitmap()),
      m_hsizer(NULL)
{
  wxInitAllImageHandlers();
  initMenuBar();

  SetMenuBar( m_menuBar );

  initToolBars();
  initMainPanel();

  CreateStatusBar(1);
  SetStatusText( _("Welcome to "APPLICATION_TITLE"!"));

  initEvents();
}

void MainWindow::initMenuBar()
{
  wxMenu *menuFile = new wxMenu;
  menuFile->Append( wxID_OPEN, _("&Open\tCtrl-O") );
  menuFile->AppendSeparator();
  menuFile->Append( ID_QUIT, _("&Exit\tCtrl-Q") );

  wxMenu *menuEdit = new wxMenu;
  menuEdit->Append( wxID_ANY, _("&Undo\tCtrl-Z") );
  wxMenu *menuToolkit = new wxMenu;
  menuToolkit->Append( ID_INPAINT, _("&Inpaint") );

  wxMenu *menuAbout = new wxMenu;
  menuAbout->Append( ID_ABOUT, _("&About...") );

  m_menuBar = new wxMenuBar;
  m_menuBar->Append( menuFile, _("&File") );
  m_menuBar->Append( menuEdit, _("&Edit") );
  m_menuBar->Append( menuToolkit, _("&Tools") );
  m_menuBar->Append( menuAbout, _("&About") );
}

void MainWindow::initMainPanel()
{
  m_panel = new wxPanel(this, wxID_ANY);
  // m_panel->
  SetMinSize(wxSize(320, 240));
  // m_topsizer = new wxGridSizer(1);
  wxSizer * m_vsizer = new wxBoxSizer(wxVERTICAL);
  m_hsizer = new wxBoxSizer(wxHORIZONTAL);
  m_canvas =
      new Canvas(m_panel, wxID_ANY);
  m_vsizer->Add(m_canvas, 1,
                wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL // | wxEXPAND
                );
  m_hsizer->Add(m_vsizer, 1,
                wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  m_hsizer->SetMinSize(wxSize(320,240));
  m_canvas->SetParentSizerPtr(m_hsizer);
  m_panel->SetSizer(m_hsizer);
  m_panel->SetAutoLayout(true);
}

void MainWindow::initToolBars()
{
  m_toolBar = CreateToolBar();
  wxBitmap bitmapNew(new_xpm);
  wxBitmap bitmapOpen(open_xpm);
  wxBitmap bitmapSave(save_xpm);
  // wxBitmap bitmapView(preview_xpm);
  wxBitmap bitmapInpaint(inpaint_xpm);
  wxBitmap bitmapSettings(settings_xpm);

  m_toolBar->AddTool((int)wxID_NEW,  wxT("New"),  bitmapNew,  wxNullBitmap);
  m_toolBar->AddTool((int)wxID_OPEN, wxT("Open"), bitmapOpen, wxNullBitmap);
  m_toolBar->AddTool((int)wxID_SAVE, wxT("Save"), bitmapSave, wxNullBitmap);
  m_toolBar->AddTool((int)ID_INPAINT, wxT("Inpaint"),
                   bitmapInpaint, wxNullBitmap);
  m_toolBar->AddTool((int)ID_SETTINGS, wxT("Settings"),
                   bitmapSettings, wxNullBitmap);
  // SetToolBar(toolBar);
  m_toolBar->Realize();
}

void MainWindow::initEvents()
{
  Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED,
          wxCommandEventHandler(MainWindow::OnMenuFileOpen));
  Connect(ID_QUIT, wxEVT_COMMAND_MENU_SELECTED,
          wxCommandEventHandler(MainWindow::OnQuit));
  Connect(ID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
          wxCommandEventHandler(MainWindow::OnAbout));
  Connect(ID_INPAINT, wxEVT_COMMAND_MENU_SELECTED,
          wxCommandEventHandler(MainWindow::OnMenuToolkitInpaint));
  // Connect(wxEVT_PAINT, wxPaintEventHandler(MainWindow::OnPaint));
  // Connect(wxID_ANY, wxEVT_SIZE,
  //         wxSizeEventHandler(MainWindow::OnResize));

  // Connect(wxID_ANY, wxEVT_MOUSEWHEEL,
  //         wxMouseEventHandler(MainWindow::OnMouseWheel));
}

void MainWindow::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(TRUE);
}

void MainWindow::OnAbout(wxCommandEvent& WXUNUSED(event))
{
  wxMessageBox( _("Visual Geometry is a program for multimedia processing.\n"
                  "Copyright (C) 2012 Liangfu Chen"),
                _("About "APPLICATION_TITLE),
                wxOK | wxICON_INFORMATION, this);
}

void MainWindow::OnMenuFileOpen(wxCommandEvent & event)
{
  wxString fn = wxFileSelector(_T("Choose a file"),
                               wxEmptyString, wxEmptyString,
                               (const wxChar*)NULL,
                               wxT("Image files (*.png;*.jpg;*.bmp)|*.png;*.jpg;*.bmp|")
                               wxT("Video files (*.mp4;*.avi)|*.mp4;*.avi|")
                               );
  fileOpen(fn);
}

void MainWindow::fileOpen(const wxString fn)
{
  if ( fn.empty() ){return;}
  if (!m_image.LoadFile(fn)) {
    // wxMessageDialog msgdlg(this, wxT("Fail to load image file!"),
    //                        wxT("ERROR"));
    // msgdlg.ShowModal();
    return;
  }
  m_imgResized = m_image;
  m_imgOriginal = cv::Mat::Mat(m_image.GetHeight(), m_image.GetWidth(),
                               CV_8UC3);
  memcpy(m_imgOriginal.data, m_image.GetData(), 
         sizeof(uchar)*m_image.GetWidth()*m_image.GetHeight()*3);
  m_bitmap = wxBitmap(m_image);
  m_canvas->loadBitmap(m_bitmap);

  m_hsizer->Layout();
  m_canvas->Refresh(false);
}

void MainWindow::OnMenuToolkitInpaint(wxCommandEvent& event)
{
  // AbstractImageEditDialog * m_dlgInpaint =
  //     new AbstractImageEditDialog(this, wxID_ANY,
  //                                 wxT("Inpaint Dialog"),
  //                                 wxDefaultPosition,
  //                                 wxDefaultSize);
  // m_dlgInpaint->loadImage(m_bitmap);
  // m_dlgInpaint->Show();
}

// void MainWindow::OnMouseWheel(wxMouseEvent& event)
// {
//   //notify("%d", event.GetWheelRotation()/event.GetWheelDelta());
//   static float factor = 0.f;
//   factor += event.GetWheelRotation()/event.GetWheelDelta()*0.05f;
//   m_imgResized = m_image.Scale(m_image.GetWidth() *(1.f+factor),
//                                m_image.GetHeight()*(1.f+factor));
//   m_bitmap = wxBitmap(m_imgResized);
//   notify("%d, %d", m_bitmap.GetWidth(), m_bitmap.GetHeight());
//   m_canvas->loadBitmap(m_bitmap);
//   m_hsizer->Layout();
//   m_canvas->Refresh(false);
// }
