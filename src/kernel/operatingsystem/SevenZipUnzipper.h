#include <string>
#ifndef KERNEL_OPERATINGSYSTEM_SEVENZIPUNZIPPER_
#define KERNEL_OPERATINGSYSTEM_SEVENZIPUNZIPPER_

using std::string;

class SevenZipUnzipper {
	string file_path_;
public:
	SevenZipUnzipper(string file_path);
	~SevenZipUnzipper();
	void ExtractTo(string output_path);
};

#endif

