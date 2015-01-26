#include "libarchive_unzipper.h"
#include <memory>

using std::make_shared;

LibArchiveUnzipper::LibArchiveUnzipper(string file_name):
	zip_file_(archive_read_new()){
	file_name_ = file_name;
}

LibArchiveUnzipper::~LibArchiveUnzipper(){
	archive_read_free(zip_file_);
}

