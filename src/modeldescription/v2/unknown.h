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
	inline string dependencies_kind();
	inline void dependencies_kind(string new_dependencies_kind);
	inline void dependencies(string new_dependencies);
	inline string dependencies();
	inline void index(int new_index);
	inline int index();
    Unknown();
};


#endif
