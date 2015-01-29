#ifndef MODELDESCRIPTION_V2_MODELEXCHANGE_H_
#define MODELDESCRIPTION_V2_MODELEXCHANGE_H_

#include <unordered_map>
#include <string>
#include <vector>
#include "source_file.h"

using std::unordered_map;
using std::string;
using std::vector;

class ModelExchange{
private:
    unordered_map<string, string> attributes_;
	vector<SourceFile> source_files_;
public:
    ModelExchange();
    unordered_map<string, string> attributes();
	void set_attributes(unordered_map<string, string> attributes);
	vector<SourceFile> source_files();
	void set_source_files(vector<SourceFile> source_files);
};


#endif
