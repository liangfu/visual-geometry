/**
 * @file   abstractimageeditdlg.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sat Jul 28 21:49:45 2012
 * 
 * @brief  
 * 
 * 
 */

#include "abstractimageeditdlg.h"

AbstractImageEditDialog::
AbstractImageEditDialog(wxWindow* parent, wxWindowID id,
						const wxString& title,
						const wxPoint& pos = wxDefaultPosition,
						const wxSize& size = wxDefaultSize):
	wxDialog( parent, id, title, pos, size ),
	m_canvas0(new AbstractCanvas(this, wxID_ANY, pos, size))// ,
	// m_canvas1(this, wxID_ANY, pos, size)
{
    // wxMenu *menuAbout = new wxMenu;
    // menuAbout->Append( wxID_ANY, _("&About...") );

    // wxMenuBar *menuBar = new wxMenuBar;
    // menuBar->Append( menuAbout, _("&About") );

    // SetMenuBar( menuBar );

    new wxButton( this, wxID_OK, _T("Ok"), wxPoint(20*2,50*2), wxSize(20*2,13*2) );
    new wxButton( this, wxID_CANCEL, _T("Cancel"), wxPoint(44*2,50*2),
        wxSize(25*2,13*2) );
	m_canvas0 = new AbstractCanvas(this, wxID_ANY,
								   wxPoint(44*2,50*2),
								   wxSize(25*2,13*2));

	// Connect(wxID_ANY, wxEVT_CLOSE,
	// 		wxCloseEventHandler(AbstractImageEditDialog::OnClose));
}
