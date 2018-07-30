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

#include "AISMsgUIDialog.h"
#include "aismsg_pi.h"

AISMsgUIDialog::AISMsgUIDialog ( aismsg_pi *pi, wxWindow* parent ) : AISMsgUIDialogBase ( parent )
{
	// save the pointer to the plugin controller
	m_paismsg_pi = pi;
}

void AISMsgUIDialog::OnDialogClose( wxCloseEvent& event )
{
	event.Skip( );
	return;
}

void AISMsgUIDialog::OnSetMsgType ( wxCommandEvent& event )
{
	wxString msg = wxString ( _( "SET MSG TYPE ????\n" ) );

	if ( event.GetEventObject() == m_rbMsgTypeABM )
	{
		msg = wxString ( _( "SET MSG TYPE ABM\n" ) );
	}
	else if ( event.GetEventObject() == m_rbMsgTypeBBM )
	{
		msg = wxString ( _( "SET MSG TYPE BBM\n" ) );
	}

	AppendToMsgThread ( msg );
	return;
}

void AISMsgUIDialog::OnSndMsg ( wxCommandEvent& event )
{
	wxString msg = wxString ( _("SEND\n") );
	AppendToMsgThread ( msg );
	return;
}

void AISMsgUIDialog::OnDebug ( wxCommandEvent& event )
{
	if ( NULL != m_paismsg_pi )
	{
		m_paismsg_pi->ShowDebugWindow ( );
	}
	return;
}

void AISMsgUIDialog::AppendToMsgThread ( wxString &msg )
{
	m_tcMsgThread->AppendText ( msg );
	return;
}
