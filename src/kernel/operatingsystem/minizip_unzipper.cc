#include "minizip_unzipper.h"
#include <stdexcept>
#include <fstream>

using std::string;
using std::ofstream;
using std::runtime_error;

const int kSearchWithCaseSensitivity    = 1;
const unsigned int kBufferSize          = 4096;

MinizipUnzipper::MinizipUnzipper(string file_name) {
	file_name_ = file_name;
	OpenZipFileOrDie();
}

MinizipUnzipper::~MinizipUnzipper(){
	CloseZipFile();
}

void MinizipUnzipper::ExtractTo(string output_path, string file_name){
	if(!FileIsInsideZip(file_name)) throw runtime_error(file_name + " was not found inside zipfile");
	CopyFileToDestination(file_name, BuildOutputFileName(output_path, file_name));
}

void MinizipUnzipper::CopyFileToDestination(string file_name, string destination){
	ofstream output_file (destination, ofstream::binary);
	SelectFile(file_name);
	WriteSelectionIntoFile(output_file);
	RemoveSelection();
	output_file.close();
}

void MinizipUnzipper::WriteSelectionIntoFile(ofstream &output_file){
	char buffer[kBufferSize] = {0};
	int read_size = 0;
	while((read_size = SizeAfterReading(buffer)) > 0) output_file.write(buffer, read_size);
}

void MinizipUnzipper::SelectFile(string file_name){
	unzLocateFile(zip_file_, file_name.c_str(), kSearchWithCaseSensitivity);
	unzOpenCurrentFile(zip_file_);
}

void MinizipUnzipper::RemoveSelection(){
	unzCloseCurrentFile(zip_file_);
}

int MinizipUnzipper::SizeAfterReading(char* buffer){
	return unzReadCurrentFile(zip_file_, buffer, kBufferSize);
}

string MinizipUnzipper::BuildOutputFileName(string output_path, string file_name){
	if(output_path.at(output_path.length() - 1) == '/') return output_path + file_name;
	return output_path + "/" + file_name;
}

bool MinizipUnzipper::FileIsInsideZip(string file_to_locate){
	int location_result = unzLocateFile(zip_file_, file_to_locate.c_str(), kSearchWithCaseSensitivity);
	return location_result == UNZ_OK;
}

void MinizipUnzipper::OpenZipFileOrDie(){
	zip_file_ = unzOpen(file_name_.c_str());
	if (zip_file_ != NULL) return;
  	throw runtime_error("FILE NOT FOUND: " + file_name_);
}

void MinizipUnzipper::CloseZipFile(){
	unzClose(zip_file_);
}
