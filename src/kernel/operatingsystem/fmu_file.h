#ifndef KERNEL_OPERATINGSYSTEM_FMUFILE_H_
#define KERNEL_OPERATINGSYSTEM_FMUFILE_H_

#include "unzipper.h"
#include "minizip_unzipper.h"
#include "file_constants.h"
#include <memory>
#include <stdexcept>

#ifdef _WIN32
string system_extension = kWindowsLibraryExtension;
#ifdef _WIN64
string system_folder = kWindowsFolder + kArch64;
#else
string system_folder = kWindowsFolder + kArch32;
#endif
#endif

#ifdef __APPLE__
#include "TargetConditionals.h"
string system_folder = kMacOsFolder + kArch64;
string system_extension = kMacOsLibraryExtension;
#endif

#ifdef __linux__
string system_extension = kLinuxLibraryExtension;
#ifdef __amd64__
string system_folder = kLinuxFolder + kArch64;
#else
string system_folder = kLinuxFolder + kArch32;
#endif
#endif

using std::runtime_error;
using std::shared_ptr;

class FmuFile {
public:
	FmuFile(string fmu_file_path);
	~FmuFile();
	string GetModelDescriptionPathAfterExtractingIt();
	string GetLibraryPathAfterExtractingIt();
private:
	shared_ptr<Unzipper> unzipper_;
	string working_directory_path_;
	string fmu_file_path_;
	string MakeTemporalDirectory();
};

#endif
