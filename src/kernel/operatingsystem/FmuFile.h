#ifndef KERNEL_OPERATINGSYSTEM_FMUFILE_H_
#define KERNEL_OPERATINGSYSTEM_FMUFILE_H_

#include <memory>
#include <stdexcept>
#include "SevenZipUnzipper.h"

using std::runtime_error;
using std::shared_ptr;

class FmuFile {
	shared_ptr<SevenZipUnzipper> unzipper_;
	string fmu_file_path_;
	string working_directory_path_;
	string model_description_path_;
	string library_path_;
	string MakeTemporaryDirectory();
	string BuildTemporaryDirectoryPath();
	string GetLibraryPath();
public:
	FmuFile(string fmu_file_path);
	~FmuFile();
	void Extract();
	string working_directory_path();
	string model_description_path();
	string library_path();
};

#endif
