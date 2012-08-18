/**
 * @file   glcanvas.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Mon Jul 23 23:36:20 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __GL_CANVAS_H__
#define __GL_CANVAS_H__


#include "wx/glcanvas.h"


class TestGLCanvas: public wxGLCanvas
{
    friend class MainFrame;
public:
    TestGLCanvas( wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0, const wxString& name = _T("TestGLCanvas") );

    TestGLCanvas( wxWindow *parent, const TestGLCanvas *other,
        wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = _T("TestGLCanvas") );

    ~TestGLCanvas();

    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnEraseBackground(wxEraseEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnKeyUp(wxKeyEvent& event);
    void OnEnterWindow(wxMouseEvent& event);

    void Render();
    void InitGL();
    void Rotate(GLfloat deg);
    static GLfloat CalcRotateSpeed(unsigned long acceltime);
    static GLfloat CalcRotateAngle( unsigned long lasttime,
        unsigned long acceltime );
    void Action( long code, unsigned long lasttime,
        unsigned long acceltime );

private:
    bool   m_init;
    GLuint m_gllist;
    long   m_rleft;
    long   m_rright;

    static unsigned long  m_secbase;
    static int            m_TimeInitialized;
    static unsigned long  m_xsynct;
    static unsigned long  m_gsynct;

    long           m_Key;
    unsigned long  m_StartTime;
    unsigned long  m_LastTime;
    unsigned long  m_LastRedraw;

DECLARE_EVENT_TABLE()
};


#endif //__GL_CANVAS_H__
