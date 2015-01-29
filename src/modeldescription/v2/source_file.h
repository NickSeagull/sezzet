#ifndef MODELDESCRIPTION_V2_SOURCEFILE_H_
#define MODELDESCRIPTION_V2_SOURCEFILE_H_

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class SourceFile{
private:
    unordered_map<string, string> attributes_;
public:
    SourceFile();
    unordered_map<string, string> attributes();
	void set_attributes(unordered_map<string, string> attributes);
};


#endif
