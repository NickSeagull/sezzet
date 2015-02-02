#ifndef MODELDESCRIPTION_V2_TOOL_H_
#define MODELDESCRIPTION_V2_TOOL_H_

#include <string>

using std::string;

class Tool{
private:
	string name_;
public:
	inline void name(string new_name);
	inline string name();
    Tool();
};


#endif
