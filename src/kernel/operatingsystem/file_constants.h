#ifndef KERNEL_OPERATINGSYSTEM_FILECONSTANTS_H_
#define KERNEL_OPERATINGSYSTEM_FILECONSTANTS_H_

#include <string>

using std::string;

const string kBinariesFolder = "binaries";
const string kMacOsFolder = "darwin";
const string kWindowsFolder = "win";
const string kLinuxFolder = "linux";
const string kMacOsLibraryExtension = ".dylib";
const string kWindowsLibraryExtension = ".dll";
const string kLinuxLibraryExtension = ".so";
const string kArch64 = "64";
const string kArch32 = "32";
const string kMissingSystemMessage = "Sezzet is not prepared for your system";
const string kModelDescriptionFilename = "modeldescription.xml";
const string kResourcesFolder = "resources";

#endif
