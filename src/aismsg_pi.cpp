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

#include "AISMsgSettingsDialog.h"
#include "AISMsgUIDialog.h"
#include "icons.h"


extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new aismsg_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
	delete p;
}

aismsg_pi::aismsg_pi(void *ppimgr) : opencpn_plugin_115(ppimgr)
{
	// Create the PlugIn icons
	initialize_images();
}

aismsg_pi::~aismsg_pi(void)
{
	delete _img_aismsg_pi;
	delete _img_aismsg;
}

int aismsg_pi::Init(void)
{
	AddLocaleCatalog( _T("opencpn-aismsg_pi") );

	// set some default private members
	m_iDlgX = 0;
	m_iDlgY = 0;
	::wxDisplaySize(&m_iDispWidth, &m_iDispHeight);

	// get pointer to display canvas, to use as parent for plugin dialogs
	m_parent_window = GetOCPNCanvasWindow();

	// request toolbar icon insertion 
	m_leftclick_tool_id = InsertPlugInTool(_T(""), _img_aismsg, _img_aismsg, 
		wxITEM_NORMAL, _("AisMsg"), _T(""), NULL, AISMSG_TOOL_POSITION, 0, this);

	m_pAISMsgUIDlg = NULL;

	return ( WANTS_TOOLBAR_CALLBACK | 
		     INSTALLS_TOOLBAR_TOOL | 
			 WANTS_NMEA_SENTENCES );

/*	return ( WANTS_TOOLBAR_CALLBACK | 
		     INSTALLS_TOOLBAR_TOOL | 
			 WANTS_NMEA_SENTENCES | 
			 WANTS_NMEA_EVENTS | 
			 WANTS_AIS_SENTENCES | 
			 WANTS_PLUGIN_MESSAGING ); */
}

bool aismsg_pi::DeInit(void)
{
	// save the dialog position
    if (NULL != m_pAISMsgUIDlg) {
        wxPoint p = m_pAISMsgUIDlg->GetPosition();
        SetDialogX(p.x);
        SetDialogY(p.y);

        m_pAISMsgUIDlg->Close();
        delete m_pAISMsgUIDlg;
        m_pAISMsgUIDlg = NULL;
	}

    return true;
}

int aismsg_pi::GetAPIVersionMajor() { return MY_API_VERSION_MAJOR; }
int aismsg_pi::GetAPIVersionMinor() { return MY_API_VERSION_MINOR; }
int aismsg_pi::GetPlugInVersionMajor() { return PLUGIN_VERSION_MAJOR; }
int aismsg_pi::GetPlugInVersionMinor() { return PLUGIN_VERSION_MINOR; }
wxBitmap *aismsg_pi::GetPlugInBitmap() { return _img_aismsg_pi; }
wxString aismsg_pi::GetCommonName() { return _("AISMessageControl"); }
wxString aismsg_pi::GetShortDescription() { return _("AIS message control plugin for OpenCPN."); }

wxString aismsg_pi::GetLongDescription() {
    return _(
        "Provides OpenCPN with the ability to send and receive\n"
		"AIS ABM and BBM messages to a connected AIS.");
}

int aismsg_pi::GetToolbarToolCount(void) { return 1; }

void aismsg_pi::SetColorScheme(PI_ColorScheme cs) {
    if (NULL == m_pAISMsgUIDlg) 
		return;

    DimeWindow(m_pAISMsgUIDlg);
}

void aismsg_pi::OnToolbarToolCallback(int id) {
	if (NULL == m_pAISMsgUIDlg) {
        m_pAISMsgUIDlg = new AISMsgUIDialog(m_parent_window);
        m_pAISMsgUIDlg->Move( wxPoint(m_iDlgX, m_iDlgY) );
    }

    if( !m_pAISMsgUIDlg->IsShown() )
        m_pAISMsgUIDlg->Show();
    else
        m_pAISMsgUIDlg->Hide();
}

void aismsg_pi::SetNMEASentence(wxString &sentence) {
    if (NULL != m_pAISMsgUIDlg)
		m_pAISMsgUIDlg->OnUpdateDebugMsg(sentence);
	return;
}

void aismsg_pi::SetAISSentence(wxString &sentence) {
	if (NULL != m_pAISMsgUIDlg)
		m_pAISMsgUIDlg->OnUpdateDebugMsg(sentence);
	return;
}

void aismsg_pi::SetPluginMessage(wxString &message_id, wxString &message_body) {
	if (NULL != m_pAISMsgUIDlg)
		m_pAISMsgUIDlg->OnPluginMsg(message_id, message_body);
	return;
}

void aismsg_pi::SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix){
    if (NULL != m_pAISMsgUIDlg) {
        wxString msg = wxString::Format(
            _T("Cog: %f, Hdm: %f, Hdt: %f, Lat: %f, Lon: %f, ")
            _T("Sog: %f, Var: %f, nSats: %d\n"),
            pfix.Cog, pfix.Hdm, pfix.Hdt, pfix.Lat, pfix.Lon, pfix.Sog,
            pfix.Var, pfix.nSats);
		m_pAISMsgUIDlg->OnUpdateDebugMsg(msg);
	}
}