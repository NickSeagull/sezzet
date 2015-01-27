#include "fmu_file.h"
#include "libarchive_unzipper.h"
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



FmuFile::~FmuFile(){
	remove_all(path(working_directory_path_));
}

FmuFile::FmuFile(string fmu_file_path) :
	unzipper_(make_shared<LibArchiveUnzipper>(fmu_file_path)),
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

string FmuFile::working_directory_path(){
	return working_directory_path_;
}

string FmuFile::GetModelDescriptionPathAfterExtractingIt(){
	string model_description_file_name = "modelDescription.xml";
	unzipper_->ExtractToOrDie(working_directory_path_, model_description_file_name);
	return working_directory_path_ + "/" + model_description_file_name;
}

string FmuFile::GetLibraryPathAfterExtractingIt(){
	string library_path_inside_zip = BuildLibraryPathInsideZip();
	unzipper_->ExtractToOrDie(working_directory_path_, library_path_inside_zip);
	return working_directory_path_ + "/" + library_path_inside_zip;
}

string FmuFile::BuildLibraryPathInsideZip(){
	string system_folder(SYSTEM_FOLDER);
	string system_extension(SYSTEM_EXTENSION);
	return "binaries/" + system_folder + "/" + GetModelName() + system_extension;
}

string FmuFile::GetModelName(){
	return "bouncingBall";
}

void FmuFile::Extract(){
	library_path_ = this->GetLibraryPathAfterExtractingIt();
	model_description_path_ = this->GetModelDescriptionPathAfterExtractingIt();
}

string FmuFile::library_path(){
	return library_path_;
}

string FmuFile::model_description_path(){
	return model_description_path_;
}
