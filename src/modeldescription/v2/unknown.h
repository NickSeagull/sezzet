#ifndef MODELDESCRIPTION_V2_UNKNOWN_H_
#define MODELDESCRIPTION_V2_UNKNOWN_H_

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class Unknown{
private:
	int index_;
	string dependencies_;
	string dependencies_kind_;	
public:
	string dependencies_kind();
	void dependencies_kind(string new_dependencies_kind);
	void dependencies(string new_dependencies);
	string dependencies();
	void index(int new_index);
	int index();
    Unknown();
};


#endif
