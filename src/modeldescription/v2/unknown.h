#ifndef MODELDESCRIPTION_V2_UNKNOWN_H_
#define MODELDESCRIPTION_V2_UNKNOWN_H_

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class Unknown{
private:
    unordered_map<string, string> attributes_;
public:
    Unknown();
    unordered_map<string, string> attributes();
	void set_attributes(unordered_map<string, string> attributes);
};


#endif
