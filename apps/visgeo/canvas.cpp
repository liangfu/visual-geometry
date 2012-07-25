/**
 * @file   canvas.cpp
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Wed Jul 25 22:19:09 2012
 * 
 * @brief  
 * 
 * 
 */

#include "canvas.h"

void Canvas::OnPaint(wxPaintEvent & WXUNUSED(event))
{
	wxPaintDC dc(this);
	dc.DrawBitmap(m_bitmap,
				  (GetSize().GetWidth() - m_bitmap.GetWidth ())/2.,
				  (GetSize().GetHeight()- m_bitmap.GetHeight())/2.,
				  0);
}
