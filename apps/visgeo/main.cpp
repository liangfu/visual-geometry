/**
 * @file   main.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sun Apr  8 17:35:06 2012
 * 
 * @brief  
 * 
 * 
 */

#include "common.h"
#include "mainframe.h"

class MyApp: public wxApp
{
    virtual bool OnInit();
};


// IMPLEMENT_APP(MyApp)
int main(int argc, char * argv[])
{
	wxApp::SetInstance(new MyApp());
	wxEntryStart(argc, argv);

	wxTheApp->OnInit();
	// do testing here
	wxTheApp->OnRun();
	wxTheApp->OnExit();
	wxEntryCleanup();
	return 0;
}


bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame( _(APPLICATION_TITLE), wxPoint(50, 50),
									  wxSize(640, 480) );
    frame->Show(true);
    // SetTopWindow(frame);
    return true;
}

