/**
 * @file   abstractimageeditdlg.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sat Jul 28 18:58:29 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __ABSTRACT_IMAGE_EDIT_DIALOG_H__
#define __ABSTRACT_IMAGE_EDIT_DIALOG_H__

#include "common.h"
#include "wx/wx.h"

#include "abstractcanvas.h"
#include "mainframe.h"

class AbstractImageEditDialog : public wxFrame
{
  AbstractCanvas * m_canvas0;
  AbstractCanvas * m_canvas1;
	
 public:
  AbstractImageEditDialog(wxWindow* parent, wxWindowID id,
                          const wxString& title,
                          const wxPoint& pos = wxDefaultPosition,
                          const wxSize& size = wxDefaultSize);
  void loadImage(const wxBitmap & bitmap){
    if (m_canvas0==NULL||m_canvas1==NULL){return;}
    m_canvas0->loadBitmap(bitmap);
    m_canvas0->Refresh(false);
    m_canvas1->loadBitmap(bitmap);
    m_canvas1->Refresh(false);
  }
};

#endif //__ABSTRACT_IMAGE_EDIT_DIALOG_H__
