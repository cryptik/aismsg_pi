/**
 * Copyright (c) 2018 Ken Erney
 *
 * This file is part of the aismsg_pi distribution, and OpenCPN Plugin.
 *
 * aismsg_pi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * aismsg_pi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with aismsg_pi.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "aismsg_pi.h"

#include "AISMsgUIDialog.h"
#include "AISMsgDebugDialog.h"
#include "AISMsgPrefsDialog.h"

#include "icons.h"


extern "C" DECL_EXP opencpn_plugin* create_pi ( void *ppimgr )
{
	return new aismsg_pi ( ppimgr );
}

extern "C" DECL_EXP void destroy_pi ( opencpn_plugin* p )
{
	delete p;
}

aismsg_pi::aismsg_pi ( void *ppimgr ) : opencpn_plugin_115 ( ppimgr )
{
	// Create the PlugIn icons
	initialize_images ( );
}

aismsg_pi::~aismsg_pi ( void )
{
	delete _img_aismsg_pi;
	delete _img_aismsg;
}

int aismsg_pi::Init ( void )
{
	wxLogMessage( _T( "aismsg_pi: Init" ) );
	AddLocaleCatalog ( _T("opencpn-aismsg_pi") );

	// set some default private members
	m_pAISMsgUIDlg = NULL;
	m_oDlgPt = wxPoint ( 0, 0 );

	m_pAISMsgDbgDlg = NULL;
	m_oDbgDlgPt = wxPoint ( 0, 0 );

	// get a pointer to the OCPN configuration object
	m_pconfig = GetOCPNConfigObject( );

	// load the configuration items
	LoadConfig( );

	// get pointer to display canvas, to use as parent for plugin dialogs
	m_parent_window = GetOCPNCanvasWindow ( );

	// request toolbar icon insertion 
	m_leftclick_tool_id = InsertPlugInTool ( _T(""), _img_aismsg, _img_aismsg,
											 wxITEM_CHECK, _( "AIS Messages" ), _T( "" ), 
											 NULL, AISMSG_TOOL_POSITION, 0, this );

	return (WANTS_TOOLBAR_CALLBACK |
			 INSTALLS_TOOLBAR_TOOL |
			 WANTS_NMEA_SENTENCES |
			 WANTS_NMEA_EVENTS |
			 WANTS_AIS_SENTENCES |
			 WANTS_PLUGIN_MESSAGING | 
			 WANTS_PREFERENCES |
			 WANTS_CONFIG );
}

bool aismsg_pi::DeInit ( void )
{
	wxLogMessage( _T( "aismsg_pi: DeInit" ) );

	// save the current configuration
	SaveConfig( );

	// save the dialog position and release it
	if ( NULL != m_pAISMsgUIDlg )
	{
		SetDialogXY ( m_pAISMsgUIDlg->GetPosition ( ) );

		m_pAISMsgUIDlg->Close ( );
		delete m_pAISMsgUIDlg;
		m_pAISMsgUIDlg = NULL;
	}

	// save the debug window postion and release it
	if ( NULL != m_pAISMsgDbgDlg )
	{
		SetDebugDlgXY ( m_pAISMsgDbgDlg->GetPosition ( ) );

		m_pAISMsgDbgDlg->Close ( );
		delete m_pAISMsgDbgDlg;
		m_pAISMsgDbgDlg = NULL;
	}

	return true;
}

int aismsg_pi::GetAPIVersionMajor ( ) { return MY_API_VERSION_MAJOR; }
int aismsg_pi::GetAPIVersionMinor ( ) { return MY_API_VERSION_MINOR; }
int aismsg_pi::GetPlugInVersionMajor ( ) { return PLUGIN_VERSION_MAJOR; }
int aismsg_pi::GetPlugInVersionMinor ( ) { return PLUGIN_VERSION_MINOR; }
wxBitmap *aismsg_pi::GetPlugInBitmap ( ) { return _img_aismsg_pi; }
wxString aismsg_pi::GetCommonName ( ) { return _("AISMessageControl"); }
wxString aismsg_pi::GetShortDescription ( ) { return _("AIS message control plugin for OpenCPN."); }

wxString aismsg_pi::GetLongDescription ( )
{
	return _( "Provides OpenCPN with the ability to send and receive\n"
		      "AIS ABM and BBM messages to a connected AIS.");
}

int aismsg_pi::GetToolbarToolCount ( void ) { return 1; }

void aismsg_pi::SetColorScheme ( PI_ColorScheme cs )
{
	wxLogMessage( _T( "aismsg_pi: SetColorScheme" ) );

	if ( NULL == m_pAISMsgUIDlg ) return;

	DimeWindow ( m_pAISMsgUIDlg );
}

void aismsg_pi::OnToolbarToolCallback ( int id )
{
	wxLogMessage( _T( "aismsg_pi: OnToolbarCallback" ) );

	// create the main UI window, if not already
	if ( NULL == m_pAISMsgUIDlg )
	{
		m_pAISMsgUIDlg = new AISMsgUIDialog ( this, m_parent_window );
		m_pAISMsgUIDlg->Move ( GetDialogXY ( ) );
	}

	// toggle the main UI window visible status
	if ( !m_pAISMsgUIDlg->IsShown ( ) )
		m_pAISMsgUIDlg->Show ( );
	else
		m_pAISMsgUIDlg->Hide ( );

	// create the debug window, if not already
	if ( NULL == m_pAISMsgDbgDlg )
	{
		m_pAISMsgDbgDlg = new AISMsgDebugDialog ( this, m_parent_window );
		m_pAISMsgDbgDlg->Move ( GetDebugDlgXY ( ) );
	}

	// if its showing now, hide it
	if ( m_pAISMsgDbgDlg->IsShown ( ) )
		m_pAISMsgDbgDlg->Hide ( );

	// update the dsipaly size info
	::wxDisplaySize ( &m_iDispWidth, &m_iDispHeight );
	return;
}

void aismsg_pi::ShowPreferencesDialog( wxWindow* parent )
{
	// This method is called when the user clicks on this plugin's 
	// preferences button that is visible in the OCPN plugin manager
	// in seetings.  Must include in the WANTS_PREFERENCES capability

	AISMsgPrefsDialog *prefDialog = new AISMsgPrefsDialog( parent );

	if( prefDialog->ShowModal( ) == wxID_OK )
	{
		SaveConfig( );
	}

	prefDialog->Destroy( );
	return;
}

bool aismsg_pi::LoadConfig( void )
{
	wxLogMessage( _T( "aismsg_pi: LoadConfig" ) );
	return true;
}

bool aismsg_pi::SaveConfig( void )
{
	wxLogMessage( _T( "aismsg_pi: SaveConfig" ) );
	return true;
}

void aismsg_pi::SetDefaults( void )
{
	// This method is called when the user enables the plugin in
	// the OCPN plugin manger panel in settings.

	wxLogMessage( _T( "aismsg_pi: SetDefaults" ) );
	return;
}

void aismsg_pi::SetNMEASentence ( wxString &sentence )
{
	// This method is called when NMEA sentences are available on the
	// input stream provided WANTS_NMEA_SENTENCES is included
	// in the capabilities request.  Sentences include AIVDO/AIVDM as
	// well as NMEA sensor sentences

	if ( NULL != m_pAISMsgDbgDlg )
		m_pAISMsgDbgDlg->AppendToDebugLog ( AISMsgDebugDialog::MSG_NMEA, sentence );
	return;
}

void aismsg_pi::SetAISSentence ( wxString &sentence )
{
	// This method is called when ?? sentences are available on the
	// input stream provided WANTS_AIS_SENTENCES is included in the
	// capabilities request.  Not sure what this is for.

	if ( NULL != m_pAISMsgDbgDlg )
		m_pAISMsgDbgDlg->AppendToDebugLog ( AISMsgDebugDialog::MSG_AIS, sentence );
	return;
}

void aismsg_pi::SetPluginMessage ( wxString &message_id, wxString &message_body )
{
	// This method enables the plugin messaging system provided 
	// WANTS_PLUGIN_MESSAGING is included in the capabilities request.

	if( NULL != m_pAISMsgDbgDlg )
	{
		wxString msg = wxString::Format ( _T("ID: %s MSG: %s\n"), message_id, message_body );
		m_pAISMsgDbgDlg->AppendToDebugLog ( AISMsgDebugDialog::MSG_INTERNAL, msg );
	}
	return;
}

void aismsg_pi::SetPositionFixEx ( PlugIn_Position_Fix_Ex &pfix )
{
	// This method is called when the ownship position changes 
	// provides the ships current location.  To enable, include 
	// WANTS_NMEA_EVENTS in the capabilities request.

	if( NULL != m_pAISMsgDbgDlg )
	{
		wxString msg = wxString::Format ( _T("COG: %f, HDM: %f, HDT: %f, LAT: %f, LON: %f, SOG: %f, nSats: %d\n"),
			pfix.Cog, pfix.Hdm, pfix.Hdt, pfix.Lat, pfix.Lon, pfix.Sog, pfix.nSats );
		m_pAISMsgDbgDlg->AppendToDebugLog ( AISMsgDebugDialog::MSG_NMEA_EVENTS, msg );
	}
	return;
}

void aismsg_pi::ShowDebugWindow ( )
{
	// show window, only if it exists
	if ( NULL != m_pAISMsgDbgDlg )
	{
		if ( !m_pAISMsgDbgDlg->IsShown ( ) )
			m_pAISMsgDbgDlg->Show ( );
	}

	return;
}
