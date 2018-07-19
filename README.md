# ABM/BBM Message Plug-in
### aismsg_pi

This is a plug-in designed for OpenCPN 4.8.4 that supports the sending and receiving
of Addressed Binary Messages (ABM) and Broadcast Binary Messages (BBM) to a connected
class A AIS system.

To build, run copy-ocplib.bat to create the build folder and copy the OpenCPN lib
file to the build folder.

From the cmake-gui, set the build folder, run Configure and then Generate.

Load the aismsg_pi.sln in to VisualStudio 2013 and build the debug version.

Run the copy-plugin.bat to copy the plugin files to a debug version of OpenCPN.

** NOTE: This plug-in is in development.  It compiles but is not functional.
	     Only Windows build currently supported.