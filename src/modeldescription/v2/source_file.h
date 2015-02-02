#ifndef MODELDESCRIPTION_V2_SOURCEFILE_H_
#define MODELDESCRIPTION_V2_SOURCEFILE_H_

#include <string>

using std::string;

class SourceFile{
private:
    string name_;
public:
	inline void name(string new_name);
	inline string name();
    SourceFile();	
};


#endif
