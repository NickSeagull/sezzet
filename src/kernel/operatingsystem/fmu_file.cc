#include "fmu_file.h"
#include <memory>
#include <boost/filesystem.hpp>

using std::make_shared;
using boost::filesystem::temp_directory_path;
using boost::filesystem::path;
using boost::filesystem::create_directory;

FmuFile::FmuFile(string fmu_file_path) :
	unzipper_(make_shared<MinizipUnzipper>(fmu_file_path)),
	fmu_file_path_(fmu_file_path),
	working_directory_path_(MakeTemporalDirectory()){}

string FmuFile::MakeTemporalDirectory(){
	string temp_folder = temp_directory_path().string() + "/fmu";
	create_directory(path(temp_folder));
	return temp_folder;
}
