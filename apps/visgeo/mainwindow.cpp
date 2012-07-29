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
#include "res/preview.xpm"

#include <wx/numdlg.h>

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame( NULL, -1, title, pos, size ),
	  m_bitmap(wxBitmap()),
	  // m_glcanvas(this, wxID_ANY, wxDefaultPosition, wxDefaultSize),
	  // m_canvas(this, wxID_ANY, wxDefaultPosition, wxDefaultSize),
	  m_mainframe(this, wxID_ANY, pos, size),
	  m_dlgInpaint(NULL)
	  // m_dlgInpaint(new AbstractImageEditDialog(this, wxID_ANY,
	  // 										   wxT("Inpaint Dialog"),
	  // 										   wxDefaultPosition,
	  // 										   wxDefaultSize))
{
	wxInitAllImageHandlers();
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

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _("&File") );
    menuBar->Append( menuEdit, _("&Edit") );
    menuBar->Append( menuToolkit, _("&Toolkit") );
    menuBar->Append( menuAbout, _("&About") );

    SetMenuBar( menuBar );

	{
		wxToolBar * toolBar = CreateToolBar();
		wxBitmap bitmapNew(new_xpm);
		wxBitmap bitmapOpen(open_xpm);
		wxBitmap bitmapSave(save_xpm);
		wxBitmap bitmapView(preview_xpm);

		toolBar->AddTool((int)wxID_NEW,  wxT("New"),  bitmapNew,  wxNullBitmap);
		toolBar->AddTool((int)wxID_OPEN, wxT("Open"), bitmapOpen, wxNullBitmap);
		toolBar->AddTool((int)wxID_SAVE, wxT("Save"), bitmapSave, wxNullBitmap);
		toolBar->AddTool((int)wxID_PREVIEW, wxT("View"), bitmapView, wxNullBitmap);
		// SetToolBar(toolBar);
		toolBar->Realize();
	}
	{
		// m_canvas.SetBackgroundColor();
		// m_canvas.Refresh(false);
	}
    CreateStatusBar(1);
    SetStatusText( _("Welcome to "APPLICATION_TITLE"!"));

	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnMenuFileOpen));
	Connect(ID_QUIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnQuit));
	Connect(ID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnAbout));
	Connect(ID_INPAINT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnMenuToolkitInpaint));
	// Connect(wxEVT_PAINT, wxPaintEventHandler(MainWindow::OnPaint));
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
	wxString fn = wxFileSelector(_T("Choose a file"), wxEmptyString, wxEmptyString,
								 (const wxChar*)NULL,
								 wxT("All image files (*.png;*.jpg;*.bmp)|*.png;*.jpg;*.bmp|")
								 wxT("PNG files (*.png)|*.png|")
								 wxT("JPEG files (*.jpg)|*.jpg|")
								 );
	if ( fn.empty() ){return;}

	wxImage image(fn);
	m_imgOriginal = cv::Mat::Mat(image.GetHeight(), image.GetWidth(),
								 CV_8UC3);
	memcpy(m_imgOriginal.data, image.GetData(), 
		   sizeof(uchar)*image.GetWidth()*image.GetHeight()*3);
	m_bitmap = wxBitmap(image);
	m_mainframe.loadBitmap(m_bitmap);
	m_mainframe.Refresh(false);
}

void MainWindow::fileOpen(const wxString fn)
{
	if ( fn.empty() ){return;}

	wxImage image(fn);
	m_bitmap = wxBitmap(image);
	m_mainframe.loadBitmap(m_bitmap);
	m_mainframe.Refresh(false);
}

void MainWindow::OnMenuToolkitInpaint(wxCommandEvent& event)
{
	if (m_dlgInpaint==NULL){
		m_dlgInpaint = new AbstractImageEditDialog(this, wxID_ANY,
												   wxT("Inpaint Dialog"),
												   wxDefaultPosition,
												   wxDefaultSize);
	}
	m_dlgInpaint->loadImage(m_bitmap);
	m_dlgInpaint->ShowModal();
	m_dlgInpaint->loadImage(m_bitmap);
	
	// int brushsize =
	// 	wxGetNumberFromUser(wxT("Please assign brush size:"), wxEmptyString,
	// 						wxT("Set brush size"),
	// 						3, 1, 100, this);
	// m_canvas.SetCursor(wxCursor(wxCURSOR_PENCIL));

	// NOTIFY("%d", brushsize);
	// cv::imshow("test", m_imgOriginal);
}
