#ifndef MODELDESCRIPTION_V2_CATEGORY_H_
#define MODELDESCRIPTION_V2_CATEGORY_H_

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

struct Category{
private:
	unordered_map<string, string> attributes_;
};

#endif
