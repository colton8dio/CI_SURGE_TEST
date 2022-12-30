//
// Created by paul on 1/24/22.
//

#ifndef SST_PLUGININFRA_PATHS_H
#define SST_PLUGININFRA_PATHS_H

#include "filesystem/import.h"
#include <string>


namespace sst
{
namespace plugininfra
{
namespace paths
{

/*
 * The CMAKE_INSTALL_PREFIX
 */
extern std::string CMAKE_INSTALL_PREFIX;

/*
 * HomePath is the path user thinks of as their root. On unixes this is the "~" directory
 * and on windows it is c:\users\blah
 */
fs::path homePath();

/*
 * sharedLibraryBinaryPath is the path to the running loaded dll which has linked this
 * and can be used to find the dll location for portable installs and the like
 */
fs::path sharedLibraryBinaryPath();

/*
 * bestDocumentsFolderPathFor gives the "~/Documents/productName" folder or OS specific equivalent.
 * Importantly this does *not* return any sort of portable name but only uses the OS-specific
 * documents folder resolution strategy. For portable documents folder use sharedLibraryBinaryPath
 */
fs::path bestDocumentsFolderPathFor(const std::string &productName);

/*
 * bestLibrarySharedFolderPathFor returns the "/Library/Application Support/programName"
 * or "%PROGRAM_DATA%/programName" or "/usr/share/programName" type folder, adjusted for
 * the CMAKE install prefix and XDG settings (on linux), and using the OS built in APIs
 * on Mac and Windows. "userLevel" on mac and linux returns the user-specific library
 * folder (so "~/Library/Application Support" on mac and "~/.local/share or XDG based on
 * linux).
 */
fs::path bestLibrarySharedFolderPathFor(const std::string &productName, bool userLevel = false);


}
}
}

#endif // SST_PLUGININFRA_PATHS_H
