#include "MainFrame.h"
#include "ImagePanel.h"
#include "Files.h"

namespace GUI
{
	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
		EVT_BUTTON(BUTTON1, MainFrame::OnButton1CLK)
		EVT_BUTTON(BUTTON2, MainFrame::OnButton2CLK)
		EVT_BUTTON(BUTTON3, MainFrame::OnButton3CLK)
		EVT_BUTTON(BUTTON4, MainFrame::OnButton4CLK)
		EVT_BUTTON(BUTTON5, MainFrame::OnButton5CLK)
		EVT_BUTTON(BUTTON6, MainFrame::OnButton6CLK)
		EVT_BUTTON(BUTTON7, MainFrame::OnButton7CLK)
		EVT_BUTTON(BUTTON8, MainFrame::OnButton8CLK)
		EVT_BUTTON(BUTTON9, MainFrame::OnButton9CLK)
		wxEND_EVENT_TABLE()

inline void MainFrame::AlingButtons(wxBitmapButton* buttons, wxBoxSizer* mainSizer)
{
	mainSizer->Add(&buttons[BUTTON1], 0, wxALIGN_TOP | wxALIGN_LEFT);
	mainSizer->Add(&buttons[BUTTON2], 0, wxALIGN_TOP | wxALIGN_CENTER);
	mainSizer->Add(&buttons[BUTTON3], 0, wxALIGN_TOP | wxALIGN_RIGHT);

	mainSizer->Add(&buttons[BUTTON4], 0, wxALIGN_CENTER | wxALIGN_LEFT);
	mainSizer->Add(&buttons[BUTTON5], 0, wxALIGN_CENTER | wxALIGN_CENTER);
	mainSizer->Add(&buttons[BUTTON6], 0, wxALIGN_CENTER | wxALIGN_RIGHT);

	mainSizer->Add(&buttons[BUTTON7], 0, wxALIGN_BOTTOM | wxALIGN_LEFT);
	mainSizer->Add(&buttons[BUTTON8], 0, wxALIGN_BOTTOM | wxALIGN_CENTER);
	mainSizer->Add(&buttons[BUTTON9], 0, wxALIGN_BOTTOM | wxALIGN_RIGHT);
}

MainFrame::MainFrame(const wxString& mainFrameTitle) : wxFrame(nullptr, wxID_ANY, mainFrameTitle)
{
	static Files files;
	ImagePanel* imgMainPanel = nullptr;
	imgMainPanel = new ImagePanel(this, files.GetBackgroundPath(), wxBITMAP_TYPE_JPEG);

	try
	{
		imgMainPanel = new ImagePanel(this, files.GetBackgroundPath(), wxBITMAP_TYPE_JPEG);

		if (imgMainPanel == nullptr) printf("Error: Panel is nullptr\n");
	}
	catch (std::exception e) { printf("Exception: [%s]\n", e.what()); }

	imgMainPanel->SetMinClientSize(wxSize(640, 480));

	const int idOffset = 2;
	#define ABS_BTN_CNT BUTTONS_COUNT - idOffset

	wxBitmapButton* buttons[ABS_BTN_CNT];

	for (size_t i = 0; i < ABS_BTN_CNT; i++)
		buttons[i] = new wxBitmapButton(imgMainPanel, i + idOffset, files.GetBitmap(EMPTY));

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	AlingButtons(*buttons, mainSizer);

	imgMainPanel->SetSizer(mainSizer);

	mainSizer->Layout();
}

	#pragma region Buttons
	void MainFrame::OnButton1CLK(wxCommandEvent& evt)
	{
			evt.Skip();
	}
	void MainFrame::OnButton2CLK(wxCommandEvent& evt)
	{
		wxLogStatus("Info");
		evt.Skip();
	}
	void MainFrame::OnButton3CLK(wxCommandEvent& evt)
	{
		wxLogStatus("Info");
		evt.Skip();
	}
	void MainFrame::OnButton4CLK(wxCommandEvent& evt)
	{
		wxLogStatus("Info");
		evt.Skip();
	}
	void MainFrame::OnButton5CLK(wxCommandEvent& evt)
	{
		wxLogStatus("Info");
		evt.Skip();
	}
	void MainFrame::OnButton6CLK(wxCommandEvent& evt)
	{
		wxLogStatus("Info");
		evt.Skip();
	}

	void MainFrame::OnButton7CLK(wxCommandEvent& evt)
	{
		evt.Skip();
	}

	void MainFrame::OnButton8CLK(wxCommandEvent& evt)
	{
		evt.Skip();
	}

	void MainFrame::OnButton9CLK(wxCommandEvent& evt)
	{
		evt.Skip();
	}

	#pragma endregion
}