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

#ifndef __AISMSGDEBUGDIALOG_H__
#define __AISMSGDEBUGDIALOG_H__

/**
@file Subclass of AISMsgDebugDialogBase, which is generated by wxFormBuilder.
*/

#include "AISMsgUIBase.h"

// forward declarations
class aismsg_pi;

class AISMsgDebugDialog : public AISMsgDebugDialogBase
{
	protected:
		// Overrides from base class
		void OnPause ( wxCommandEvent& event );
		void OnDialogClose( wxCloseEvent& event );

	public:
		AISMsgDebugDialog ( aismsg_pi *pi, wxWindow *parent );

	public:
		enum MsgTypeOptions { MSG_NMEA, MSG_AIS, MSG_NMEA_EVENTS, MSG_INTERNAL };

		void AppendToDebugLog ( MsgTypeOptions msgOpt, wxString &msg );

	private:
		aismsg_pi		*m_paismsg_pi;

		int				m_iBufLnCnt;
		bool			m_bPause;
};

#endif // __AISMSGDEBUGDIALOG_H__
