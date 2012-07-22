
#ifndef __MAIN_FRAME_H__
#define __MAIN_FRAME_H__


#include "wx/wx.h"


enum {
	ID_QUIT = wxID_HIGHEST,
	ID_ABOUT,
};


class MainFrame: public wxFrame
{
public:

    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    // DECLARE_EVENT_TABLE()
};

#endif //__MAIN_FRAME_H__
