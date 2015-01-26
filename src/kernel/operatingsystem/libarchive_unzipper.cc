#include "libarchive_unzipper.h"
#include "../../../include/libarchive/archive_entry.h"
#include <stdexcept>
#include <iostream>
#include <ostream>
#include <fstream>

using std::runtime_error;
using std::cout;
using std::endl;
using std::ofstream;

const int kBlockSize = 10240;
const int kBufferSize = 4096;

LibArchiveUnzipper::LibArchiveUnzipper(string file_name):
	zip_file_(archive_read_new()){
	file_name_ = file_name;
	ConfigureZipFile();
	OpenZipArchiveOrDie();
}

void LibArchiveUnzipper::ConfigureZipFile(){
	archive_read_support_filter_all(zip_file_);
	archive_read_support_format_all(zip_file_);
}

void LibArchiveUnzipper::OpenZipArchiveOrDie(){
	if (archive_read_open_filename(zip_file_, file_name_.c_str(), kBlockSize) == ARCHIVE_OK) return;
	throw runtime_error("Could not open ziparchive" + file_name_);
}

LibArchiveUnzipper::~LibArchiveUnzipper(){
	if(archive_read_free(zip_file_) != ARCHIVE_OK) throw runtime_error("Could not close zipfile " + file_name_);
}

void LibArchiveUnzipper::ExtractToOrDie(string destiny_path, string file_to_extract){
	bool did_not_finish_reading = true;
	while(ReadNextHeader() && did_not_finish_reading)
		did_not_finish_reading = !ExtractEntryIfEqualsFileToExtract(destiny_path, file_to_extract);
}

bool LibArchiveUnzipper::ReadNextHeader(){
	return (archive_read_next_header(zip_file_, &current_zip_entry_) == ARCHIVE_OK);
}

bool LibArchiveUnzipper::ExtractEntryIfEqualsFileToExtract(string destiny_path, string file_to_extract){
	if(EntryNameEquals(file_to_extract)) {
		ExtractEntry(BuildDestinyFilePath(destiny_path, file_to_extract));
		return true;
	}
	return false;
}

bool LibArchiveUnzipper::EntryNameEquals(string file_name){
	string entry_name(archive_entry_pathname(current_zip_entry_));
	return (entry_name == file_name.c_str());
}

void LibArchiveUnzipper::ExtractEntry(string destiny_path){
	ofstream output_file(destiny_path, ofstream::binary);
	WriteEntryIntoFile(output_file);
	output_file.close();
}

string LibArchiveUnzipper::BuildDestinyFilePath(string destiny_path, string file_name){
	if(destiny_path.at(destiny_path.length() - 1) == '/') return destiny_path + file_name;
	return destiny_path + "/" + file_name;
}

void LibArchiveUnzipper::WriteEntryIntoFile(ofstream &output_file){
	char buffer[kBufferSize] = {0};
	int read_size = 0;
	while((read_size = SizeAfterReading(buffer)) > 0) output_file.write(buffer, read_size);
	if (read_size < 0) throw runtime_error("Could not write entry into file");
}

int LibArchiveUnzipper::SizeAfterReading(char* buffer){
	return archive_read_data(zip_file_, buffer, kBufferSize);
}

