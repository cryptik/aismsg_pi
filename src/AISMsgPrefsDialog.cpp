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

/*
wxCheckBox*		m_cbEnableBBM;
wxCheckBox*		m_cbEnableABM;
wxTextCtrl*		m_tcOwnshipMMSI;
wxButton*		m_sdbSizer1OK;
wxButton*		m_sdbSizer1Cancel;
wxString		m_wsOwnMMSI;
*/

#include <wx/wx.h>

#include "AISMsgPrefsDialog.h"

AISMsgPrefsDialog::AISMsgPrefsDialog( wxWindow* parent ) : AISMsgPrefsDialogBase( parent ) 
{
	EnableCloseButton( false );
	m_tcOwnshipMMSI->Enable( false );
	return;
}

void AISMsgPrefsDialog::OnEnableBBM( wxCommandEvent& event )
{
	// no special processing required
	return;
}

void AISMsgPrefsDialog::OnEnableABM( wxCommandEvent& event )
{
	// if ABM is enabled, then required an MMSI
	if( m_cbEnableABM->IsChecked( ) )
	{
		m_tcOwnshipMMSI->Enable( true );
	}
	else
	{
		m_tcOwnshipMMSI->Enable( false );
		m_tcOwnshipMMSI->Clear( );
	}

	return;
}

void AISMsgPrefsDialog::OnOk( wxCommandEvent& event )
{
	// if ABM is disabled... then no MMSI is required
	if( !m_cbEnableABM->IsChecked( ) )
	{
		wxDialog::EndModal( wxID_OK );
	}
	else
	{
		// validate and check length
		if( Validate( ) && (m_wsOwnMMSI.Length( ) == AISMSG_MMSI_LEN) )
		{
			// MMSI is good
			wxDialog::EndModal( wxID_OK );
		}
		else
		{
			// MMSI is invalid ... post error message
			wxMessageDialog *dMsg = new wxMessageDialog( NULL,
														 _( "ABM messages require a valid 9 digit MMSI.\n"
														 "Please provide an MMSI or disable ABM messages." ),
														 _( "Info" ), wxOK );
			dMsg->ShowModal( );
		}
	}

	return;
}
