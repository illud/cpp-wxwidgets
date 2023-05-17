#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
	public:
		MainFrame(const wxString& title);
	private:
		void OnButtonClicked(wxCommandEvent& evt);
		void OnSliderChanged(wxCommandEvent& evt);
		void OnTextChanged(wxCommandEvent& evt);
		void OnMouseEvent(wxMouseEvent& evt);
		//wxDECLARE_EVENT_TABLE(); // //Events (Static Handling)
};

