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

#ifndef __AISMSGPLUGIN_PI_H__
#define __AISMSGPLUGIN_PI_H__

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include <wx/glcanvas.h>
#include "wx/wx.h"
#endif //precompiled headers

#include "version.h"

#define	MY_API_VERSION_MAJOR    1
#define	MY_API_VERSION_MINOR    15

#include "ocpn_plugin.h"

// forward declarations
class AISMsgSettingsDialog;
class AISMsgUIDialog;

//----------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------

#define AISMSG_TOOL_POSITION -1  // Request default positioning of toolbar tool

class aismsg_pi : public opencpn_plugin_115 {
	public:
		aismsg_pi(void *ppimgr);
		~aismsg_pi(void);

		// required plugin methods
		int Init(void);
		bool DeInit(void);

		int GetAPIVersionMajor();
		int GetAPIVersionMinor();
		int GetPlugInVersionMajor();
		int GetPlugInVersionMinor();

		wxBitmap *GetPlugInBitmap();
		wxString GetCommonName();
		wxString GetShortDescription();
		wxString GetLongDescription();

		// required override plugin methods
		int GetToolbarToolCount(void);
		void OnToolbarToolCallback(int id);

		// optional plugin overrides
		void SetColorScheme(PI_ColorScheme cs);
		void SetNMEASentence(wxString &sentence);
		void SetAISSentence(wxString &sentence);
		void SetPluginMessage(wxString &message_id, wxString &message_body);
		void SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix);

		// other plublic methods
		void SetDialogX(int x) { m_iDlgX = x; };
		void SetDialogY(int y) { m_iDlgY = y; }

	private:
		wxWindow				*m_parent_window;
		AISMsgUIDialog			*m_pAISMsgUIDlg;

		int						m_iDlgX, m_iDlgY;
		int						m_iDispWidth, m_iDispHeight;
		int						m_leftclick_tool_id;
};

#endif // __AISMSGPLUGIN_PI_H__

