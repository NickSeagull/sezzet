#ifndef MODELDESCRIPTION_V2_DISPLAYUNIT_H_
#define MODELDESCRIPTION_V2_DISPLAYUNIT_H_

#include <string>

using std::string;

struct DisplayUnit{
private:
	string name_;
	double factor_;
	double offset_;
};

#endif
