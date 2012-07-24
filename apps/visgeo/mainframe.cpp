
#include "common.h"
#include "mainframe.h"
#include "res/new.xpm"
#include "res/open.xpm"
#include "res/save.xpm"
#include "res/preview.xpm"


MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame( NULL, -1, title, pos, size ),
	  m_bitmap(wxBitmap()),
	  // m_glcanvas(this, wxID_ANY, wxDefaultPosition, wxDefaultSize),
	  m_canvas(this, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	wxInitAllImageHandlers();
    wxMenu *menuFile = new wxMenu;
    menuFile->Append( wxID_OPEN, _("&Open\tCtrl-O") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_QUIT, _("&Exit\tCtrl-Q") );

    wxMenu *menuEdit = new wxMenu;
    menuEdit->Append( wxID_ANY, _("&Undo\tCtrl-Z") );

    wxMenu *menuAbout = new wxMenu;
    menuAbout->Append( ID_ABOUT, _("&About...") );

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _("&File") );
    menuBar->Append( menuEdit, _("&Edit") );
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

	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnMenuFileOpen));
	Connect(ID_QUIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnQuit));
	Connect(ID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnAbout));
	Connect(wxEVT_PAINT, wxPaintEventHandler(MainFrame::OnPaint));
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(TRUE);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("Visual Geometry is a program for visualizing geometry relation between a set of related images.\n"
					"Copyright 2012 (C) Liangfu Chen"),
                  _("About "APPLICATION_TITLE),
                  wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnMenuFileOpen(wxCommandEvent & event)
{
	wxString fn = wxFileSelector(_T("Choose a file"), wxEmptyString, wxEmptyString,
								 (const wxChar*)NULL,
								 wxT("All image files (*.png;*.jpg;*.bmp)|*.png;*.jpg;*.bmp|")
								 wxT("PNG files (*.png)|*.png|")
								 wxT("JPEG files (*.jpg)|*.jpg|")
								 );
	if ( fn.empty() ){return;}

	wxImage * image = new wxImage(fn);
	// if (!image.LoadFile(fn,wxBITMAP_TYPE_JPEG)){
	// 	wxLogError(_T("Couldn't load image from '%s'."), fn.c_str());
	// 	return;
	// }
	m_bitmap = wxBitmap(*image);
	m_canvas.loadBitmap(m_bitmap);
}

void MainFrame::OnPaint(wxPaintEvent & WXUNUSED(event))
{
	wxPaintDC dc(this);
	// fprintf(stderr, "size: %d,%d\n",
	// 		m_canvas.GetSize().GetWidth(), m_bitmap.GetWidth());
	dc.DrawBitmap(m_bitmap,
				  10,10,0);
	m_canvas.Center();
	wxCoord x1 = 50, y1 = 60;
	wxCoord x2 = 190, y2 = 60;

	dc.DrawLine(x1, y1, x2, y2);
	// dc.DrawCircle(10,10,0);
				  // (m_canvas.GetSize().GetWidth() -
				  //  m_bitmap.GetWidth ())/2.,
				  // (m_canvas.GetSize().GetHeight()-
				  //  m_bitmap.GetHeight())/2.,
				  // 0);
}
