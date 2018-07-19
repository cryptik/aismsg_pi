## Copyright (c) 2018 Ken Erney
##
## This file is part of the aismsg_pi distribution, and OpenCPN Plugin.
##
## aismsg_pi is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## aismsg_pi is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with aismsg_pi.  If not, see <https://www.gnu.org/licenses/>.
 
# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(aismsg_pi)

SET(CMAKE_VERBOSE_MAKEFILE ON)

SET(PACKAGE_NAME aismsg_pi)
SET(VERBOSE_NAME AISMessageControl)
SET(TITLE_NAME AISMessageControl)
SET(CPACK_PACKAGE_CONTACT "Ken E.")

SET(BUNDLE_DATA TRUE)

INCLUDE( "VERSION.cmake" )
SET(PLUGIN_VERSION "${PLUGIN_VERSION_MAJOR}.${PLUGIN_VERSION_MINOR}.${PLUGIN_VERSION_PATCH}" )

SET(VERSION_MAJOR ${PLUGIN_VERSION_MAJOR})
SET(VERSION_MINOR ${PLUGIN_VERSION_MINOR})
SET(VERSION_DATE ${PLUGIN_VERSION_DATE})

#SET(CMAKE_BUILD_TYPE Debug)

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_AISMSG
    src/aismsg_pi.cpp
    src/aismsg_pi.h
    src/AISMsgSettingsDialog.cpp
    src/AISMsgSettingsDialog.h
    src/AISMsgUIDialog.cpp
    src/AISMsgUIDialog.h
    src/AISMSGUIDialogBase.cpp
    src/AISMSGUIDialogBase.h
    src/icons.cpp
    src/icons.h
	src/ocpn_plugin.h
)

IF(WIN32)
SET(SRC_LTINYXML
		src/tinyxml/tinyxml.cpp
		src/tinyxml/tinyxmlerror.cpp
		src/tinyxml/tinyxmlparser.cpp
		src/tinyxml/tinystr.cpp
)
ENDIF(WIN32)
	
SET(SRC_LNMEA0183
		src/nmea0183/latlong.cpp
		src/nmea0183/long.cpp
		src/nmea0183/nmea0183.cpp
		src/nmea0183/response.cpp
		src/nmea0183/rmb.cpp
		src/nmea0183/sentence.cpp
		src/nmea0183/talkerid.cpp
		src/nmea0183/rmc.cpp
		src/nmea0183/hexvalue.cpp
		src/nmea0183/lat.cpp
		src/nmea0183/expid.cpp
		src/nmea0183/wpl.cpp
		src/nmea0183/rte.cpp
		src/nmea0183/hdt.cpp
		src/nmea0183/hdg.cpp
		src/nmea0183/hdm.cpp
		src/nmea0183/gll.cpp
		src/nmea0183/vtg.cpp
		src/nmea0183/gga.cpp
		src/nmea0183/gsv.cpp
		src/nmea0183/dbt.cpp
		src/nmea0183/dpt.cpp
		src/nmea0183/mtw.cpp
		src/nmea0183/mwv.cpp
		src/nmea0183/vhw.cpp
		src/nmea0183/vwr.cpp
		src/nmea0183/vwt.cpp
		src/nmea0183/xdr.cpp
		src/nmea0183/zda.cpp
		src/nmea0183/rsa.cpp
)

ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_AISMSG} ${SRC_LTINYXML} ${SRC_LNMEA0183})

ADD_DEFINITIONS(-DTIXML_USE_STL)

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")

