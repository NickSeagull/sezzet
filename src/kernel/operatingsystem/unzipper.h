#ifndef KERNEL_OPERATINGSYSTEM_UNZIPPER_H_
#define KERNEL_OPERATINGSYSTEM_UNZIPPER_H_
#include <string>

using std::string;

class Unzipper {
protected:
	string file_name_;
public:
	virtual void ExtractToOrDie(string output_path, string file_name) = 0;
};
#endif
