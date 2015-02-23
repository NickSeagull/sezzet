#ifndef MODELDESCRIPTION_V2_DISPLAYUNIT_H_
#define MODELDESCRIPTION_V2_DISPLAYUNIT_H_

#include <string>

using std::string;

class DisplayUnit{
private:
	string name_;
	double factor_;
	double offset_;
	
public:
	void offset(double new_offset);
	double offset();
	void factor(double new_factor);
	double factor();
	void name(string new_name);
	string name();
};

#endif
