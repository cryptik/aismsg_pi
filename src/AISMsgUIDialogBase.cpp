///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "AISMsgUIDialogBase.h"

///////////////////////////////////////////////////////////////////////////

AISMsgUIDialogBase::AISMsgUIDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_tcMsgThread = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_LEFT|wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP );
	m_tcMsgThread->SetMinSize( wxSize( 350,200 ) );
	bSizer1->Add( m_tcMsgThread, 0, wxALL|wxEXPAND, 5 );
	
	m_stMsgTextLabel = new wxStaticText( this, wxID_ANY, _("Enter Message Text:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stMsgTextLabel->Wrap( -1 );
	bSizer1->Add( m_stMsgTextLabel, 0, wxALL, 5 );
	
	m_tcMsgText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer1->Add( m_tcMsgText, 0, wxALL|wxEXPAND, 5 );
	
	m_cbMsgTypeBBM = new wxRadioButton( this, wxID_ANY, _("Binary Broadcast (BBM)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_cbMsgTypeBBM, 0, wxALL, 5 );
	
	m_cbMsgTypeABM = new wxRadioButton( this, wxID_ANY, _("Addressed Binary (ABM)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_cbMsgTypeABM, 0, wxALL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_btnSend = new wxButton( this, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_btnSend, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_btnCancel, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer1->Add( gSizer1, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_cbMsgTypeBBM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_cbMsgTypeABM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_btnSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnSndMsg ), NULL, this );
	m_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnCancel ), NULL, this );
}

AISMsgUIDialogBase::~AISMsgUIDialogBase()
{
	// Disconnect Events
	m_cbMsgTypeBBM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_cbMsgTypeABM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_btnSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnSndMsg ), NULL, this );
	m_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnCancel ), NULL, this );
	
}

AISMsgSettingsDialogBase::AISMsgSettingsDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_cbEnableBBM = new wxCheckBox( this, wxID_ANY, _("Enable BBM"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_cbEnableBBM, 0, wxALL|wxEXPAND, 5 );
	
	m_cbEnableABM = new wxCheckBox( this, wxID_ANY, _("Enable ABM"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_cbEnableABM, 0, wxALL|wxEXPAND, 5 );
	
	m_stOwnshipIMSILabel = new wxStaticText( this, wxID_ANY, _("Ownship MMSI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stOwnshipIMSILabel->Wrap( -1 );
	bSizer2->Add( m_stOwnshipIMSILabel, 0, wxALL|wxEXPAND, 5 );
	
	m_tcOwnshipIMSI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_tcOwnshipIMSI, 0, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer2->Add( m_sdbSizer1, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AISMsgSettingsDialogBase::OnClose ) );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgSettingsDialogBase::OnCancel ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgSettingsDialogBase::OnOK ), NULL, this );
}

AISMsgSettingsDialogBase::~AISMsgSettingsDialogBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AISMsgSettingsDialogBase::OnClose ) );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgSettingsDialogBase::OnCancel ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgSettingsDialogBase::OnOK ), NULL, this );
	
}
