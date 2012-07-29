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

class AbstractImageEditDialog : public wxDialog
{
// protected:
	AbstractCanvas * m_canvas0;
	// AbstractCanvas m_canvas1;
	
public:
	AbstractImageEditDialog();
	AbstractImageEditDialog(wxWindow* parent, wxWindowID id,
							const wxString& title,
							const wxPoint& pos,
							const wxSize& size);
	void loadImage(const wxBitmap & bitmap){
		m_canvas0->loadBitmap(bitmap);
		m_canvas0->Refresh(false);
		Refresh(false);
		puts(__FUNCTION__);
	}
};

#endif //__ABSTRACT_IMAGE_EDIT_DIALOG_H__
