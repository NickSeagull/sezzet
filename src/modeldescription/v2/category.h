#ifndef MODELDESCRIPTION_V2_CATEGORY_H_
#define MODELDESCRIPTION_V2_CATEGORY_H_

#include <string>

using std::string;

struct Category{
private:
	string name_;
	string description_;
	
public:
	inline void description(string new_description);
	inline string description();
	inline void name(string new_name);
	inline string name();
};

#endif
