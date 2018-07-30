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

#ifndef __AISMSGUIDIALOG_H__
#define __AISMSGUIDIALOG_H__

/**
@file Subclass of AISMsgUIDialogBase, which is generated by wxFormBuilder.
*/

#include "AISMsgUIBase.h"

// forward declarations
class aismsg_pi;

class AISMsgUIDialog : public AISMsgUIDialogBase
{
	protected:
		// Overrides from base class
		void OnSetMsgType ( wxCommandEvent& event );
		void OnSndMsg ( wxCommandEvent& event );
		void OnDebug ( wxCommandEvent& event );
		void OnDialogClose( wxCloseEvent& event );

	public:
		AISMsgUIDialog ( aismsg_pi *pi, wxWindow *parent );

	public:
		void AppendToMsgThread ( wxString &msg );

	private:
		aismsg_pi		*m_paismsg_pi;
};

#endif // __AISMSGPLUGIN_PI_H__
