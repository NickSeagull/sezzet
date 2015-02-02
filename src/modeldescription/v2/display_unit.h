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
	inline void offset(double new_offset);
	inline double offset();
	inline void factor(double new_factor);
	inline double factor();
	inline void name(string new_name);
	inline string name();
};

#endif
