#ifndef MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_DATA_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_DATA_H_

#include "content.h"
#include <string>

using std::string;

class Data : public Content{
private:
	string data_;
public:
	string data();
    Data(string data);
    
};


#endif
