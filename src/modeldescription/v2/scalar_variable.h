#ifndef MODELDESCRIPTION_V2_SCALARVARIABLE_H_
#define MODELDESCRIPTION_V2_SCALARVARIABLE_H_

#include <unordered_map>
#include <string>
#include <memory>
#include "real_type.h"
#include "integer_type.h"
#include "boolean_type.h"
#include "string_type.h"
#include "enumeration_type.h"
#include "tool.h"

using std::unordered_map;
using std::string;
using std::shared_ptr;

class ScalarVariable{
private:
    unordered_map<string, string> attributes_;
	shared_ptr<RealType> real_;
	shared_ptr<IntegerType> integer_;
	shared_ptr<BooleanType> boolean_;
	shared_ptr<StringType> string_;
	shared_ptr<EnumerationType> enumeration_;
	vector<shared_ptr<Tool>> annotations_;
	shared_ptr<SimpleType> type_;
	string type_name_;
public:
    ScalarVariable();
    unordered_map<string, string> attributes();
	void set_attributes(unordered_map<string, string> attributes);
	shared_ptr<RealType> real();
	void set_real(shared_ptr<RealType> real);
	shared_ptr<IntegerType> integer();
	void set_integer(shared_ptr<IntegerType> integer);
	shared_ptr<StringType> string();
	void set_string(shared_ptr<StringType> string);
	shared_ptr<EnumerationType> enumeration();
	void set_enumeration(shared_ptr<EnumerationType> enumeration);
	vector<shared_ptr<Tool>> annotations();
	void set_annotations(vector<shared_ptr<Tool>> annotations);
	shared_ptr<SimpleType> type();
	void set_type(shared_ptr<SimpleType> type);
	std::string type_name();
	void set_type_name(std::string type_name);

};


#endif
