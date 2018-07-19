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

AISMsgUIDialog::AISMsgUIDialog( wxWindow* parent ) : AISMsgUIDialogBase( parent ) {}

void AISMsgUIDialog::OnSetMsgType( wxCommandEvent& event ) {
	// TODO: Implement OnSetMsgType
}

void AISMsgUIDialog::OnSndMsg( wxCommandEvent& event ) {
	// TODO: Implement OnSndMsg
}

void AISMsgUIDialog::OnCancel( wxCommandEvent& event ) {
	// TODO: Implement OnCancel
}

void AISMsgUIDialog::OnUpdateDebugMsg( wxString &msg ) {
	if( !m_tcMsgThread->GetValue() ) 
		m_tcMsgThread->AppendText(msg);
}

void AISMsgUIDialog::OnPluginMsg( wxString &id, wxString &msg ) {
}