#ifndef KERNEL_OPERATINGSYSTEM_LIBARCHIVEUNZIPPER_H_
#define KERNEL_OPERATINGSYSTEM_LIBARCHIVEUNZIPPER_H_
#include "../../../include/libarchive/archive.h"
#include <string>
#include "unzipper.h"

using std::string;

class LibArchiveUnzipper: public Unzipper {
public:
	LibArchiveUnzipper(string file_name);
	~LibArchiveUnzipper();
	void ExtractTo(string output_path, string file_name);
private:
    archive *zip_file_;
};
#endif
