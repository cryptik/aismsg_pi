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

#include "AISMsgDebugDialog.h"
#include "aismsg_pi.h"

# define MAX_LN_CNT 1200

AISMsgDebugDialog::AISMsgDebugDialog ( aismsg_pi *pi, wxWindow* parent ) : AISMsgDebugDialogBase ( parent )
{
	// save the pointer to the plugin controller
	m_paismsg_pi = pi;

	// init some other stuff
	m_iBufLnCnt = 0;
	m_bPause = FALSE;
	return;
}

void AISMsgDebugDialog::OnDialogClose( wxCloseEvent& event )
{
	event.Skip( );
	return;
}

void AISMsgDebugDialog::AppendToDebugLog ( MsgTypeOptions msgOpt, wxString &msg )
{
	bool bFilterMsg = FALSE;

	// skip if we are paused
	if ( m_bPause ) { return; }

	// check the message type
	switch ( msgOpt )
	{
		case MSG_NMEA:
		{
			bFilterMsg = m_cbFilterNMEA->GetValue( );
			m_tcAisStream->SetDefaultStyle ( wxTextAttr ( *wxBLACK ) );
			break;
		}
		case MSG_NMEA_EVENTS:
		{
			bFilterMsg = m_cbFilterNMEAEvents->GetValue();
			m_tcAisStream->SetDefaultStyle ( wxTextAttr ( *wxBLUE ) );
			break;
		}
		case MSG_AIS:
		{
			bFilterMsg = m_cbFilterAIS->GetValue();
			m_tcAisStream->SetDefaultStyle ( wxTextAttr ( *wxGREEN ) );
			break;
		}
		case MSG_INTERNAL:
		{
			bFilterMsg = m_cbFilterInternal->GetValue();
			m_tcAisStream->SetDefaultStyle ( wxTextAttr ( *wxRED ) );
			break;
		}
		default:
		{
			// this should not happen
			m_tcAisStream->SetDefaultStyle ( wxTextAttr ( *wxLIGHT_GREY ) );
			break;
		}
	}

	// Only update if not filtered
	if( !bFilterMsg )
	{
		// HACK: if line count exceeds max, clear the control
		if ( m_iBufLnCnt > MAX_LN_CNT )
		{
			// clear the control of text
			m_tcAisStream->Clear ( );

			// save the current style
			wxTextAttr saveStyle = m_tcAisStream->GetDefaultStyle( );

			// write an informational message
			m_tcAisStream->SetDefaultStyle ( wxTextAttr ( *wxLIGHT_GREY ) );
			m_tcAisStream->AppendText ( _("---> BUFFER CLEARED ---\n") );

			// restore style
			m_tcAisStream->SetDefaultStyle( saveStyle );
			m_iBufLnCnt = 1;
		}

		// write the current line to the window
		m_tcAisStream->AppendText ( msg );
		m_iBufLnCnt += 1;

		// update the window stats
		wxString stats = wxString::Format ( _T ( "C: %d / L: %d" ), m_tcAisStream->GetValue ( ).length ( ), m_iBufLnCnt );
		m_tcTextStats->SetValue ( stats );
	}

	return;
}

void AISMsgDebugDialog::OnPause( wxCommandEvent& event )
{
	// get the object from the event
	wxButton *btn = wxDynamicCast( event.GetEventObject( ), wxButton );

	// should be the pause button control
	if( btn == m_btnPause )
	{
		if( m_bPause )
		{
			// we are paused.... so unpause
			btn->SetLabelText( _( "Pause" ) );
			m_bPause = FALSE;
		}
		else
		{
			// we are unpaused.... so pause
			btn->SetLabelText( _( "UnPause" ) );
			m_bPause = TRUE;
			AppendToDebugLog( MSG_INTERNAL, wxString( _( "---> PAUSED ---\n" ) ) );
		}
	}

	return;
}
