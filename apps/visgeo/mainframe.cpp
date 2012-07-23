
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
		toolBar->AddTool((int)wxID_NEW,  bitmapNew,  wxNullBitmap);
		toolBar->AddTool((int)wxID_OPEN, bitmapOpen, wxNullBitmap);
		toolBar->AddTool((int)wxID_SAVE, bitmapSave, wxNullBitmap);
		toolBar->AddTool((int)wxID_PREVIEW, bitmapView, wxNullBitmap);
		// SetToolBar(toolBar);
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
	Connect(wxID_ANY, wxEVT_PAINT, wxPaintEventHandler(MainFrame::OnPaint));
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(TRUE);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("This is a wxWidgets Hello world sample"),
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

	fprintf(stderr, "%s\n", __func__);
	wxImage * image = new wxImage(fn, wxBITMAP_TYPE_JPEG, -1);
	// if (!image.LoadFile(fn,wxBITMAP_TYPE_JPEG)){
	// 	wxLogError(_T("Couldn't load image from '%s'."), fn.c_str());
	// 	return;
	// }
	m_bitmap = wxBitmap(*image);
	m_canvas.loadBitmap(m_bitmap);
}

void MainFrame::OnPaint(wxPaintEvent & WXUNUSED(event))
{
	fprintf(stderr, "mainframe::%s\n", __func__);
	wxPaintDC dc(this);
	dc.DrawBitmap(m_bitmap,0,0,0);
}
