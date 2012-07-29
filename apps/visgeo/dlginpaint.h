/**
 * @file   dlginpaint.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Thu Jul 26 00:55:06 2012
 * 
 * @brief  
 * 
 * 
 */

#include "common.h"

#include "wx/wx.h"
#include "abstractimageeditdlg.h"

class InpaintDialog : public AbstractImageEditDialog
{
public:
	InpaintDialog(wxWindow* parent, wxWindowID id,
				  const wxString& title,
				  const wxPoint& pos,
				  const wxSize& size):
		AbstractImageEditDialog(parent, id, title, pos, size)
	{
		
	}
};
