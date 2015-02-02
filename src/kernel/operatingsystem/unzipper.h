#ifndef KERNEL_OPERATINGSYSTEM_UNZIPPER_H_
#define KERNEL_OPERATINGSYSTEM_UNZIPPER_H_
#include <string>
#include <vector>

using std::string;
using std::vector;

class Unzipper {
protected:
	string file_name_;
	vector<string> entries_;
public:
	virtual void ExtractToOrDie(string output_path, string file_name) = 0;
	virtual void ExtractFolderToOrDie(string output_path, string folder_name) = 0;
	virtual bool HasFile(string file_name) = 0;
};
#endif
