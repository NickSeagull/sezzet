#ifndef MODELDESCRIPTION_V2_TOOL_H_
#define MODELDESCRIPTION_V2_TOOL_H_

#include <string>

using std::string;

class Tool{
private:
	string name_;
public:
	void name(string new_name);
	string name();
    Tool();
};


#endif
