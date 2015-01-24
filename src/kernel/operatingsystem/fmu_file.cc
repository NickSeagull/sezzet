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

FmuFile::FmuFile(string fmu_file_path) :
	unzipper_(make_shared<MinizipUnzipper>(fmu_file_path)),
	fmu_file_path_(fmu_file_path),
	working_directory_path_(MakeTemporalDirectory()){}

string FmuFile::MakeTemporalDirectory(){
	string temp_folder =
		temp_directory_path().string() +
		"/fmu_" +
		lexical_cast<string>(duration_cast<milliseconds> (high_resolution_clock::now().time_since_epoch()).count()) +
		path(fmu_file_path_).stem().string();
	create_directory(path(temp_folder));
	return temp_folder;
}
