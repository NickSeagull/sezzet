#include "fmu_file.h"
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
	unzipper_(make_shared<MinizipUnzipper>(fmu_file_path)),
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
	unzipper_->ExtractTo(working_directory_path_, model_description_file_name);
	return working_directory_path_ + "/" + model_description_file_name;
}
