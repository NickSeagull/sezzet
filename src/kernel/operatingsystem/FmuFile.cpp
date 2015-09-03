#include "FmuFile.h"
#include <memory>
#include <chrono>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>


using boost::filesystem::temp_directory_path;
using boost::filesystem::path;
using boost::filesystem::create_directory;
using boost::lexical_cast;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::make_shared;



FmuFile::FmuFile(string fmu_file_path) :
	fmu_file_path_(fmu_file_path),
	working_directory_path_(MakeTemporaryDirectory()){}

string FmuFile::MakeTemporaryDirectory(){
	string temp_folder = BuildTemporaryDirectoryPath();
	create_directory(path(temp_folder));
	return temp_folder;
}

string FmuFile::BuildTemporaryDirectoryPath(){
	string temp_folder_path = temp_directory_path().string() +
		"/fmu_" +
		lexical_cast<string>(duration_cast<milliseconds> (high_resolution_clock::now().time_since_epoch()).count()) +
		path(fmu_file_path_).stem().string();
	return temp_folder_path;
}


void FmuFile::Extract(){
	SevenZipUnzipper unzipper(fmu_file_path_);
	unzipper.ExtractTo(working_directory_path_);
	model_description_path_ = working_directory_path_ + "/modelDescription.xml";
	library_path_ = working_directory_path_ + "/binaries/" + GetLibraryPath();
}


string FmuFile::GetLibraryPath(){
#ifdef _WIN32
 #ifdef _WIN64
	return "win64";
 #else
	return "win32";
 #endif
#else
	throw exception("Operating system not supported!");
#endif
}

string FmuFile::library_path() { return library_path_; }
string FmuFile::working_directory_path(){return working_directory_path_;}
string FmuFile::model_description_path(){return model_description_path_;}

FmuFile::~FmuFile(){
	remove_all(path(working_directory_path_));
}

