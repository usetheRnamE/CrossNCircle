#pragma once
#include <wx/wx.h>

namespace GUI
{
	enum ID // forbiden ID: 0, 1, [4999, 5999]
	{
		BUTTON1 = 2, BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8, BUTTON9, BUTTONS_COUNT,
		NAME_TXT_ID,
		BACKGROUND_ID
	};

	class MainFrame : public wxFrame
	{
	public:
		MainFrame(const wxString& mainFrameTitle);
	public:
		void OnButton1CLK(wxCommandEvent& evt);
		void OnButton2CLK(wxCommandEvent& evt);
		void OnButton3CLK(wxCommandEvent& evt);
		void OnButton4CLK(wxCommandEvent& evt);
		void OnButton5CLK(wxCommandEvent& evt);
		void OnButton6CLK(wxCommandEvent& evt);
		void OnButton7CLK(wxCommandEvent& evt);
		void OnButton8CLK(wxCommandEvent& evt);
		void OnButton9CLK(wxCommandEvent& evt);
	private:
		void AlingButtons(wxBitmapButton* buttons, wxBoxSizer* mainSizer);

		wxDECLARE_EVENT_TABLE();
	};
}

