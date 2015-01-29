#ifndef MODELDESCRIPTION_V2_ITEM_H_
#define MODELDESCRIPTION_V2_ITEM_H_

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

struct Item{
private:
    unordered_map<string, string> attributes_;
public:
	unordered_map<string, string> attributes();
};

#endif
