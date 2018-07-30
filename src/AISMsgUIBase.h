///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __AISMSGUIBASE_H__
#define __AISMSGUIBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>
#include <wx/valtext.h>
#include <wx/statbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class AISMsgUIDialogBase
///////////////////////////////////////////////////////////////////////////////
class AISMsgUIDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_stMsgTextLabel1;
		wxTextCtrl* m_tcMsgThread;
		wxStaticText* m_stMsgTextLabel2;
		wxTextCtrl* m_tcMsgText;
		wxRadioButton* m_rbMsgTypeBBM;
		wxRadioButton* m_rbMsgTypeABM;
		wxButton* m_btnDebug;
		wxButton* m_btnSend;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDialogClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnSetMsgType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDebug( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSndMsg( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AISMsgUIDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("AIS Message Control"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,410 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AISMsgUIDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AISMsgPrefsDialogBase
///////////////////////////////////////////////////////////////////////////////
class AISMsgPrefsDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* m_cbEnableBBM;
		wxCheckBox* m_cbEnableABM;
		wxStaticText* m_stMsgTextLabel1;
		wxTextCtrl* m_tcOwnshipMMSI;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnEnableBBM( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEnableABM( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxString m_wsOwnMMSI; 
		
		AISMsgPrefsDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("AIS Message Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 293,169 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AISMsgPrefsDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AISMsgDebugDialogBase
///////////////////////////////////////////////////////////////////////////////
class AISMsgDebugDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* m_cbFilterNMEA;
		wxCheckBox* m_cbFilterAIS;
		wxCheckBox* m_cbFilterNMEAEvents;
		wxCheckBox* m_cbFilterInternal;
		wxTextCtrl* m_tcTextStats;
		wxButton* m_btnPause;
		wxTextCtrl* m_tcAisStream;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDialogClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnPause( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AISMsgDebugDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("AIS Stream Debug"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,460 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~AISMsgDebugDialogBase();
	
};

#endif //__AISMSGUIBASE_H__
