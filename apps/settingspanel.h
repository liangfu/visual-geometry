/**
 * @file   settingspanel.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Sat Aug 18 16:12:53 2012
 * 
 * @brief  
 * 
 * 
 */

#include "wx/wx.h"

#include "common.h"

class SettingsPanel : public wxPanel
{
  enum
  {
    ID_PaneBorderSize = wxID_HIGHEST+1,
    ID_SashSize,
    ID_CaptionSize,
    ID_BackgroundColor,
    ID_SashColor,
    ID_InactiveCaptionColor,
    ID_InactiveCaptionGradientColor,
    ID_InactiveCaptionTextColor,
    ID_ActiveCaptionColor,
    ID_ActiveCaptionGradientColor,
    ID_ActiveCaptionTextColor,
    ID_BorderColor,
    ID_GripperColor
  };

 public:

  SettingsPanel(wxWindow* parent, wxFrame* frame)
      : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize)
  {
    wxBoxSizer* vert = new wxBoxSizer(wxVERTICAL);

    //vert->Add(1, 1, 1, wxEXPAND);

    // wxBoxSizer* s1 = new wxBoxSizer(wxHORIZONTAL);
    // m_border_size = new wxSpinCtrl(this, ID_PaneBorderSize, wxEmptyString, wxDefaultPosition, wxSize(50,20));
    // s1->Add(1, 1, 1, wxEXPAND);
    // s1->Add(new wxStaticText(this, -1, wxT("Pane Border Size:")));
    // s1->Add(m_border_size);
    // s1->Add(1, 1, 1, wxEXPAND);
    // s1->SetItemMinSize((size_t)1, 180, 20);
    // //vert->Add(s1, 0, wxEXPAND | wxLEFT | wxBOTTOM, 5);

    // wxBoxSizer* s2 = new wxBoxSizer(wxHORIZONTAL);
    // m_sash_size = new wxSpinCtrl(this, ID_SashSize, wxEmptyString, wxDefaultPosition, wxSize(50,20));
    // s2->Add(1, 1, 1, wxEXPAND);
    // s2->Add(new wxStaticText(this, -1, wxT("Sash Size:")));
    // s2->Add(m_sash_size);
    // s2->Add(1, 1, 1, wxEXPAND);
    // s2->SetItemMinSize((size_t)1, 180, 20);
    // //vert->Add(s2, 0, wxEXPAND | wxLEFT | wxBOTTOM, 5);

    // wxBoxSizer* s3 = new wxBoxSizer(wxHORIZONTAL);
    // m_caption_size = new wxSpinCtrl(this, ID_CaptionSize, wxEmptyString, wxDefaultPosition, wxSize(50,20));
    // s3->Add(1, 1, 1, wxEXPAND);
    // s3->Add(new wxStaticText(this, -1, wxT("Caption Size:")));
    // s3->Add(m_caption_size);
    // s3->Add(1, 1, 1, wxEXPAND);
    // s3->SetItemMinSize((size_t)1, 180, 20);
    // //vert->Add(s3, 0, wxEXPAND | wxLEFT | wxBOTTOM, 5);

    //vert->Add(1, 1, 1, wxEXPAND);


    wxBitmap b = CreateColorBitmap(*wxBLACK);

    wxBoxSizer* s4 = new wxBoxSizer(wxHORIZONTAL);
    m_background_color = new wxBitmapButton(this, ID_BackgroundColor, b, wxDefaultPosition, wxSize(50,25));
    s4->Add(1, 1, 1, wxEXPAND);
    s4->Add(new wxStaticText(this, -1, wxT("Background Color:")));
    s4->Add(m_background_color);
    s4->Add(1, 1, 1, wxEXPAND);
    s4->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s5 = new wxBoxSizer(wxHORIZONTAL);
    m_sash_color = new wxBitmapButton(this, ID_SashColor, b, wxDefaultPosition, wxSize(50,25));
    s5->Add(1, 1, 1, wxEXPAND);
    s5->Add(new wxStaticText(this, -1, wxT("Sash Color:")));
    s5->Add(m_sash_color);
    s5->Add(1, 1, 1, wxEXPAND);
    s5->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s6 = new wxBoxSizer(wxHORIZONTAL);
    m_inactive_caption_color = new wxBitmapButton(this, ID_InactiveCaptionColor, b, wxDefaultPosition, wxSize(50,25));
    s6->Add(1, 1, 1, wxEXPAND);
    s6->Add(new wxStaticText(this, -1, wxT("Normal Caption:")));
    s6->Add(m_inactive_caption_color);
    s6->Add(1, 1, 1, wxEXPAND);
    s6->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s7 = new wxBoxSizer(wxHORIZONTAL);
    m_inactive_caption_gradient_color = new wxBitmapButton(this, ID_InactiveCaptionGradientColor, b, wxDefaultPosition, wxSize(50,25));
    s7->Add(1, 1, 1, wxEXPAND);
    s7->Add(new wxStaticText(this, -1, wxT("Normal Caption Gradient:")));
    s7->Add(m_inactive_caption_gradient_color);
    s7->Add(1, 1, 1, wxEXPAND);
    s7->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s8 = new wxBoxSizer(wxHORIZONTAL);
    m_inactive_caption_text_color = new wxBitmapButton(this, ID_InactiveCaptionTextColor, b, wxDefaultPosition, wxSize(50,25));
    s8->Add(1, 1, 1, wxEXPAND);
    s8->Add(new wxStaticText(this, -1, wxT("Normal Caption Text:")));
    s8->Add(m_inactive_caption_text_color);
    s8->Add(1, 1, 1, wxEXPAND);
    s8->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s9 = new wxBoxSizer(wxHORIZONTAL);
    m_active_caption_color = new wxBitmapButton(this, ID_ActiveCaptionColor, b, wxDefaultPosition, wxSize(50,25));
    s9->Add(1, 1, 1, wxEXPAND);
    s9->Add(new wxStaticText(this, -1, wxT("Active Caption:")));
    s9->Add(m_active_caption_color);
    s9->Add(1, 1, 1, wxEXPAND);
    s9->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s10 = new wxBoxSizer(wxHORIZONTAL);
    m_active_caption_gradient_color = new wxBitmapButton(this, ID_ActiveCaptionGradientColor, b, wxDefaultPosition, wxSize(50,25));
    s10->Add(1, 1, 1, wxEXPAND);
    s10->Add(new wxStaticText(this, -1, wxT("Active Caption Gradient:")));
    s10->Add(m_active_caption_gradient_color);
    s10->Add(1, 1, 1, wxEXPAND);
    s10->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s11 = new wxBoxSizer(wxHORIZONTAL);
    m_active_caption_text_color = new wxBitmapButton(this, ID_ActiveCaptionTextColor, b, wxDefaultPosition, wxSize(50,25));
    s11->Add(1, 1, 1, wxEXPAND);
    s11->Add(new wxStaticText(this, -1, wxT("Active Caption Text:")));
    s11->Add(m_active_caption_text_color);
    s11->Add(1, 1, 1, wxEXPAND);
    s11->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s12 = new wxBoxSizer(wxHORIZONTAL);
    m_border_color = new wxBitmapButton(this, ID_BorderColor, b, wxDefaultPosition, wxSize(50,25));
    s12->Add(1, 1, 1, wxEXPAND);
    s12->Add(new wxStaticText(this, -1, wxT("Border Color:")));
    s12->Add(m_border_color);
    s12->Add(1, 1, 1, wxEXPAND);
    s12->SetItemMinSize((size_t)1, 180, 20);

    wxBoxSizer* s13 = new wxBoxSizer(wxHORIZONTAL);
    m_gripper_color = new wxBitmapButton(this, ID_GripperColor, b, wxDefaultPosition, wxSize(50,25));
    s13->Add(1, 1, 1, wxEXPAND);
    s13->Add(new wxStaticText(this, -1, wxT("Gripper Color:")));
    s13->Add(m_gripper_color);
    s13->Add(1, 1, 1, wxEXPAND);
    s13->SetItemMinSize((size_t)1, 180, 20);

    wxGridSizer* grid_sizer = new wxGridSizer(2);
    grid_sizer->SetHGap(5);
    // grid_sizer->Add(s1);  grid_sizer->Add(s4);
    // grid_sizer->Add(s2);  grid_sizer->Add(s5);
    // grid_sizer->Add(s3);  grid_sizer->Add(s13);
    grid_sizer->Add(1,1); grid_sizer->Add(s12);
    grid_sizer->Add(s6);  grid_sizer->Add(s9);
    grid_sizer->Add(s7);  grid_sizer->Add(s10);
    grid_sizer->Add(s8);  grid_sizer->Add(s11);

    wxBoxSizer* cont_sizer = new wxBoxSizer(wxVERTICAL);
    cont_sizer->Add(grid_sizer, 1, wxEXPAND | wxALL, 5);
    SetSizer(cont_sizer);
    GetSizer()->SetSizeHints(this);

    // m_frame = frame;
    // m_border_size->SetValue(frame->GetDockArt()->GetMetric(wxAUI_ART_PANE_BORDER_SIZE));
    // m_sash_size->SetValue(frame->GetDockArt()->GetMetric(wxAUI_ART_SASH_SIZE));
    // m_caption_size->SetValue(frame->GetDockArt()->GetMetric(wxAUI_ART_CAPTION_SIZE));

    UpdateColors();
  }

 private:

  wxBitmap CreateColorBitmap(const wxColour& c)
  {
    wxImage image;
    image.Create(25,14);
    for (int x = 0; x < 25; ++x)
      for (int y = 0; y < 14; ++y)
      {
        wxColour pixcol = c;
        if (x == 0 || x == 24 || y == 0 || y == 13)
          pixcol = *wxBLACK;
        image.SetRGB(x, y, pixcol.Red(), pixcol.Green(), pixcol.Blue());
      }
    return wxBitmap(image);
  }
    void UpdateColors()
    {
    }
    

    void OnSetColor(wxCommandEvent& event)
    {
        wxColourDialog dlg(m_frame);
        dlg.SetTitle(_("Color Picker"));
        if (dlg.ShowModal() != wxID_OK)
            return;
        
        // int var = 0;
        // switch (event.GetId())
        // {
        //     case ID_BackgroundColor:              var = wxAUI_ART_BACKGROUND_COLOUR; break;
        //     case ID_SashColor:                    var = wxAUI_ART_SASH_COLOUR; break;
        //     case ID_InactiveCaptionColor:         var = wxAUI_ART_INACTIVE_CAPTION_COLOUR; break;
        //     case ID_InactiveCaptionGradientColor: var = wxAUI_ART_INACTIVE_CAPTION_GRADIENT_COLOUR; break;
        //     case ID_InactiveCaptionTextColor:     var = wxAUI_ART_INACTIVE_CAPTION_TEXT_COLOUR; break;
        //     case ID_ActiveCaptionColor:           var = wxAUI_ART_ACTIVE_CAPTION_COLOUR; break;
        //     case ID_ActiveCaptionGradientColor:   var = wxAUI_ART_ACTIVE_CAPTION_GRADIENT_COLOUR; break;
        //     case ID_ActiveCaptionTextColor:       var = wxAUI_ART_ACTIVE_CAPTION_TEXT_COLOUR; break;
        //     case ID_BorderColor:                  var = wxAUI_ART_BORDER_COLOUR; break;
        //     case ID_GripperColor:                 var = wxAUI_ART_GRIPPER_COLOUR; break;
        //     default: return;
        // }
        
        // m_frame->GetDockArt()->SetColor(var, dlg.GetColourData().GetColour());
        // m_frame->DoUpdate();
        UpdateColors();
    }
    
private:

    wxFrame* m_frame;
    wxSpinCtrl* m_border_size;
    wxSpinCtrl* m_sash_size;
    wxSpinCtrl* m_caption_size;
    wxBitmapButton* m_inactive_caption_text_color;
    wxBitmapButton* m_inactive_caption_gradient_color;
    wxBitmapButton* m_inactive_caption_color;
    wxBitmapButton* m_active_caption_text_color;
    wxBitmapButton* m_active_caption_gradient_color;
    wxBitmapButton* m_active_caption_color;
    wxBitmapButton* m_sash_color;
    wxBitmapButton* m_background_color;
    wxBitmapButton* m_border_color;
    wxBitmapButton* m_gripper_color;
};
