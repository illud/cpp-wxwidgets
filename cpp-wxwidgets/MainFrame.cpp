#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

//Events (Static Handling)
/*enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};*/

//Events (Static Handling)
/*wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()*/

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

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200, -1));
	textCtrl->SetBackgroundColour(wxColour(1, 87, 155));
	textCtrl->SetForegroundColour(wxColour(255, 255, 255));

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);
	slider->SetForegroundColour(wxColour(255, 255, 255));

	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	gauge->SetBackgroundColour(wxColour(1, 87, 155));
	gauge->SetForegroundColour(wxColour(1, 87, 155));
	gauge->SetValue(40);

	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	choice->SetBackgroundColour(wxColour(1, 87, 155));

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));
	spinCtrl->SetBackgroundColour(wxColour(1, 87, 155));
	spinCtrl->SetForegroundColour(wxColour(255, 255, 255));

	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);
	listBox->SetBackgroundColour(wxColour(1, 87, 155));
	listBox->SetForegroundColour(wxColour(255, 255, 255));

	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);
	radioBox->SetBackgroundColour(wxColour(1, 87, 155));
	radioBox->SetForegroundColour(wxColour(255, 255, 255));

	// Dynamic Event Handling
	wxButton* buttonDynamic = new wxButton(panel, wxID_ANY, "Button Dynamic", wxPoint(500, 575), wxSize(200, 50));
	buttonDynamic->SetBackgroundColour(wxColour(1, 87, 155));
	buttonDynamic->SetForegroundColour(wxColour(255, 255, 255));

	wxSlider* sliderDynamic = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 575), wxSize(200, -1), wxSL_VALUE_LABEL);
	sliderDynamic->SetForegroundColour(wxColour(255, 255, 255));

	wxTextCtrl* textCtrlDynamic = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable - Dynamic", wxPoint(500, 675), wxSize(200, -1));
	textCtrlDynamic->SetBackgroundColour(wxColour(1, 87, 155));
	textCtrlDynamic->SetForegroundColour(wxColour(255, 255, 255));

	//Events (Static Handling)
	/*wxButton* buttonStatic = new wxButton(panel, BUTTON_ID, "Button Static", wxPoint(500, 575), wxSize(200, 50));
	buttonStatic->SetBackgroundColour(wxColour(1, 87, 155));
	buttonStatic->SetForegroundColour(wxColour(255, 255, 255));

	wxSlider* sliderStatic = new wxSlider(panel, SLIDER_ID, 25, 0, 100, wxPoint(100, 575), wxSize(200, -1), wxSL_VALUE_LABEL);
	sliderStatic->SetForegroundColour(wxColour(255, 255, 255));

	wxTextCtrl* textCtrlStatic = new wxTextCtrl(panel, TEXT_ID, "TextCtrl - editable - Static", wxPoint(500, 675), wxSize(200, -1));
	textCtrlStatic->SetBackgroundColour(wxColour(1, 87, 155));
	textCtrlStatic->SetForegroundColour(wxColour(255, 255, 255));*/

	buttonDynamic->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	sliderDynamic->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	textCtrlDynamic->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	//buttonDynamic->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	buttonDynamic->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	//Mouse
	panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);

	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetBackgroundColour(wxColour(1, 87, 155));
	//statusBar->SetForegroundColour(wxColour(wxT("WHITE")));
	//wxStaticText* txt = new wxStaticText(statusBar, wxID_ANY, wxT("Validation failed"), wxPoint(10, 5), wxDefaultSize, 0);
	//txt->Show(true);
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked");
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Slider value: %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Text: %s", evt.GetString());
	wxLogStatus(str);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
	wxPoint mousePos = evt.GetPosition();
	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}