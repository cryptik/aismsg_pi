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

#ifndef __AISMSGSETTINGSDIALOG_H__
#define __AISMSGSETTINGSDIALOG_H__

/**
@file
Subclass of AISMsgSettingsDialogBase, which is generated by wxFormBuilder.
*/

#include "AISMsgUIDialogBase.h"

//// end generated include

/** Implementing AISMsgSettingsDialogBase */
class AISMsgSettingsDialog : public AISMsgSettingsDialogBase
{
	protected:
		// Handlers for AISMsgSettingsDialogBase events.
		void OnClose( wxCloseEvent& event );
		void OnCancel( wxCommandEvent& event );
		void OnOK( wxCommandEvent& event );
	public:
		/** Constructor */
		AISMsgSettingsDialog( wxWindow* parent );
	//// end generated class members


};

#endif // __AISMSGSETTINGSDIALOG_H__
