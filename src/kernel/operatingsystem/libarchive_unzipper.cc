#include "libarchive_unzipper.h"

LibArchiveUnzipper::LibArchiveUnzipper(string file_name):
	zip_file_(archive_read_new()){
	file_name_ = file_name;
}

LibArchiveUnzipper::~LibArchiveUnzipper(){
	archive_read_free(zip_file_);
}

