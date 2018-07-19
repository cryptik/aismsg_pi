///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __AISMSGUIDIALOGBASE_H__
#define __AISMSGUIDIALOGBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class AISMsgUIDialogBase
///////////////////////////////////////////////////////////////////////////////
class AISMsgUIDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* m_tcMsgThread;
		wxStaticText* m_stMsgTextLabel;
		wxTextCtrl* m_tcMsgText;
		wxRadioButton* m_cbMsgTypeBBM;
		wxRadioButton* m_cbMsgTypeABM;
		wxButton* m_btnSend;
		wxButton* m_btnCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSetMsgType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSndMsg( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AISMsgUIDialogBase( wxWindow* parent, 
			wxWindowID id = wxID_ANY, 
			const wxString& title = _("AIS Message Control"), 
			const wxPoint& pos = wxDefaultPosition, 
			const wxSize& size = wxSize( -1,-1 ), 
			long style = wxDEFAULT_DIALOG_STYLE ); 

		~AISMsgUIDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AISMsgSettingsDialogBase
///////////////////////////////////////////////////////////////////////////////
class AISMsgSettingsDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* m_cbEnableBBM;
		wxCheckBox* m_cbEnableABM;
		wxStaticText* m_stOwnshipIMSILabel;
		wxTextCtrl* m_tcOwnshipIMSI;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AISMsgSettingsDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("AIS Message Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AISMsgSettingsDialogBase();
	
};

#endif //__AISMSGUIDIALOGBASE_H__
