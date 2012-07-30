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
						const wxPoint& pos,
						const wxSize& size):
	wxFrame( parent, id, title, pos, size ),
	m_canvas0(NULL),
	m_canvas1(NULL)
{
  wxGridSizer * topsizer =
      new wxGridSizer(2,2,5,5);
  wxBoxSizer * bsizer1 =
      new wxBoxSizer(wxHORIZONTAL);
  wxStaticText * pButtonOK =
      new wxStaticText( this, wxID_OK, _T("Original"));
  bsizer1->Add(pButtonOK,
                wxSizerFlags().Expand().Border(10).Proportion(1).Center());
  wxStaticText * pButtonCancel =
      new wxStaticText( this, wxID_CANCEL, _T("Modified"));
  bsizer1->Add(pButtonCancel,
               wxSizerFlags().Expand().Border(10).Proportion(1));

  topsizer->Add(bsizer1);

  wxBoxSizer * bsizer2 =
      new wxBoxSizer(wxHORIZONTAL);
  m_canvas0 = new AbstractCanvas(this, wxID_ANY,
                                 wxDefaultPosition, wxSize(320, 240));
  m_canvas1 = new AbstractCanvas(this, wxID_ANY,
                                 wxDefaultPosition, wxSize(320, 240));
  bsizer2->Add(m_canvas0, 1, wxEXPAND | wxALL, 10);
  bsizer2->Add(m_canvas1, 1, wxALL, 10);

  topsizer->Add(bsizer2);

  SetSizer( topsizer );
  topsizer->SetSizeHints( this );
}
