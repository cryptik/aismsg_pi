///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "AISMsgUIBase.h"

///////////////////////////////////////////////////////////////////////////

AISMsgUIDialogBase::AISMsgUIDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_stMsgTextLabel1 = new wxStaticText( this, wxID_ANY, _("Message Thread:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stMsgTextLabel1->Wrap( -1 );
	bSizer1->Add( m_stMsgTextLabel1, 0, wxALL, 5 );
	
	m_tcMsgThread = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_LEFT|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_WORDWRAP );
	m_tcMsgThread->SetMinSize( wxSize( 350,200 ) );
	
	bSizer1->Add( m_tcMsgThread, 0, wxALL|wxEXPAND, 5 );
	
	m_stMsgTextLabel2 = new wxStaticText( this, wxID_ANY, _("Enter Message Text:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stMsgTextLabel2->Wrap( -1 );
	bSizer1->Add( m_stMsgTextLabel2, 0, wxALL, 5 );
	
	m_tcMsgText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer1->Add( m_tcMsgText, 0, wxALL|wxEXPAND, 5 );
	
	m_rbMsgTypeBBM = new wxRadioButton( this, wxID_ANY, _("Binary Broadcast (BBM)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_rbMsgTypeBBM, 0, wxALL, 5 );
	
	m_rbMsgTypeABM = new wxRadioButton( this, wxID_ANY, _("Addressed Binary (ABM)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_rbMsgTypeABM, 0, wxALL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_btnDebug = new wxButton( this, wxID_ANY, _("Debug"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_btnDebug, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_btnSend = new wxButton( this, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_btnSend, 0, wxALIGN_CENTER|wxALL|wxALIGN_RIGHT, 5 );
	
	
	bSizer1->Add( gSizer1, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AISMsgUIDialogBase::OnDialogClose ) );
	m_rbMsgTypeBBM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_rbMsgTypeABM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_btnDebug->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnDebug ), NULL, this );
	m_btnSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnSndMsg ), NULL, this );
}

AISMsgUIDialogBase::~AISMsgUIDialogBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AISMsgUIDialogBase::OnDialogClose ) );
	m_rbMsgTypeBBM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_rbMsgTypeABM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AISMsgUIDialogBase::OnSetMsgType ), NULL, this );
	m_btnDebug->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnDebug ), NULL, this );
	m_btnSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgUIDialogBase::OnSndMsg ), NULL, this );
	
}

AISMsgPrefsDialogBase::AISMsgPrefsDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_cbEnableBBM = new wxCheckBox( this, wxID_ANY, _("Enable BBM"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	bSizer2->Add( m_cbEnableBBM, 0, wxALL|wxEXPAND, 5 );
	
	m_cbEnableABM = new wxCheckBox( this, wxID_ANY, _("Enable ABM"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	bSizer2->Add( m_cbEnableABM, 0, wxALL|wxEXPAND, 5 );
	
	m_stMsgTextLabel1 = new wxStaticText( this, wxID_ANY, _("Ownship MMSI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stMsgTextLabel1->Wrap( -1 );
	bSizer2->Add( m_stMsgTextLabel1, 0, wxALL|wxEXPAND, 5 );
	
	m_tcOwnshipMMSI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_tcOwnshipMMSI->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
	
	m_tcOwnshipMMSI->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &m_wsOwnMMSI ) );
	
	bSizer2->Add( m_tcOwnshipMMSI, 0, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer2->Add( m_sdbSizer1, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_cbEnableBBM->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AISMsgPrefsDialogBase::OnEnableBBM ), NULL, this );
	m_cbEnableABM->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AISMsgPrefsDialogBase::OnEnableABM ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgPrefsDialogBase::OnOk ), NULL, this );
}

AISMsgPrefsDialogBase::~AISMsgPrefsDialogBase()
{
	// Disconnect Events
	m_cbEnableBBM->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AISMsgPrefsDialogBase::OnEnableBBM ), NULL, this );
	m_cbEnableABM->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AISMsgPrefsDialogBase::OnEnableABM ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgPrefsDialogBase::OnOk ), NULL, this );
	
}

AISMsgDebugDialogBase::AISMsgDebugDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 640,460 ), wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Filter Messages") ), wxHORIZONTAL );
	
	m_cbFilterNMEA = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("NMEA"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	sbSizer1->Add( m_cbFilterNMEA, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbFilterAIS = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("AIS"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	sbSizer1->Add( m_cbFilterAIS, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbFilterNMEAEvents = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("Events"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	sbSizer1->Add( m_cbFilterNMEAEvents, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbFilterInternal = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("Internal"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	sbSizer1->Add( m_cbFilterInternal, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( sbSizer1, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_tcTextStats = new wxTextCtrl( this, wxID_ANY, _("C: 999999 / L: 9999"), wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE|wxTE_READONLY|wxNO_BORDER );
	m_tcTextStats->SetMinSize( wxSize( 240,-1 ) );
	
	bSizer4->Add( m_tcTextStats, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnPause = new wxButton( this, wxID_ANY, _("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnPause, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer3->Add( bSizer4, 0, wxEXPAND|wxALL, 5 );
	
	m_tcAisStream = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_LEFT|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_WORDWRAP );
	m_tcAisStream->SetMinSize( wxSize( 350,200 ) );
	
	bSizer3->Add( m_tcAisStream, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AISMsgDebugDialogBase::OnDialogClose ) );
	m_btnPause->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgDebugDialogBase::OnPause ), NULL, this );
}

AISMsgDebugDialogBase::~AISMsgDebugDialogBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AISMsgDebugDialogBase::OnDialogClose ) );
	m_btnPause->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AISMsgDebugDialogBase::OnPause ), NULL, this );
	
}
