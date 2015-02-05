#ifndef MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_ATTRIBUTE_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_ATTRIBUTE_H_

#include <string>

using std::string;

class Attribute{
private:
	string name_;
	string value_;
public:
	void value(string new_value);
	string value();
	void name(string new_name);
	string name();
	Attribute();
};


#endif
