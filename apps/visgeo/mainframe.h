/**
 * @file   mainframe.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Mon Jul 23 19:33:26 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __MAIN_FRAME_H__
#define __MAIN_FRAME_H__


#include "wx/wx.h"
#include "glcanvas.h"
#include "canvas.h"

enum {
	ID_QUIT = wxID_HIGHEST,
	ID_ABOUT,
};


class MainFrame: public wxFrame
{
	wxBitmap m_bitmap;
	// TestGLCanvas m_glcanvas;
	Canvas m_canvas;
public:

    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnMenuFileOpen(wxCommandEvent & event);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	void OnPaint(wxPaintEvent & event);
    // DECLARE_EVENT_TABLE()
};

#endif //__MAIN_FRAME_H__
