#ifndef KERNEL_OPERATINGSYSTEM_LIBARCHIVEUNZIPPER_H_
#define KERNEL_OPERATINGSYSTEM_LIBARCHIVEUNZIPPER_H_
#include <minizip/unzip.h>
#include <string>
#include "unzipper.h"

using std::string;
using std::ofstream;

class LibArchiveUnzipper: public Unzipper {
public:
	LibArchiveUnzipper(string file_name);
	~LibArchiveUnzipper();
	void ExtractTo(string output_path, string file_name);
private:

};
#endif
