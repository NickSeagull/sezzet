#ifndef KERNEL_OPERATINGSYSTEM_FMUFILE_H_
#define KERNEL_OPERATINGSYSTEM_FMUFILE_H_

#include "unzipper.h"
#include <memory>
#include <stdexcept>

#ifdef _WIN32
#define SYSTEM_EXTENSION ".dll"
#ifdef _WIN64
#define SYSTEM_FOLDER "win64"
#else
#define SYSTEM_FOLDER "win32"
#endif
#endif

#ifdef __APPLE__
#include "TargetConditionals.h"
#define SYSTEM_FOLDER "darwin64"
#define SYSTEM_EXTENSION ".dylib"
#endif

#ifdef __linux__
#define SYSTEM_EXTENSION ".so"
#ifdef __amd64__
#define SYSTEM_FOLDER "linux64"
#else
#define SYSTEM_FOLDER "linux32"
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
	string working_directory_path();
private:
	shared_ptr<Unzipper> unzipper_;
	string fmu_file_path_;
	string working_directory_path_;
	string MakeTemporaryDirectory();
	string BuildTemporaryDirectoryPath();
};

#endif
