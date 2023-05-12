#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColor(38, 50, 56));

	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));
	button->SetBackgroundColour(wxColour(1, 87, 155));
	button->SetForegroundColour(wxColour(255, 255, 255));

	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 55));
	checkBox->SetForegroundColour(wxColor(255, 255, 255));

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Hello", wxPoint(120, 150));
	staticText->SetForegroundColour(wxColour(255,255,255));

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(100, 250), wxSize(200, -1));
	textCtrl->SetBackgroundColour(wxColour(1, 87, 155));
	textCtrl->SetForegroundColour(wxColour(255, 255, 255));
}
