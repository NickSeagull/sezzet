#ifndef MODELDESCRIPTION_V2_SIMPLETYPE_H_
#define MODELDESCRIPTION_V2_SIMPLETYPE_H_

#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

class RealType;
class IntegerType;
class BooleanType;
class StringType;
class EnumerationType;

class SimpleType{
private:
	string name_;
	string description_;
	shared_ptr<RealType> real_;
	shared_ptr<IntegerType> integer_;
	shared_ptr<BooleanType> boolean_;
	shared_ptr<StringType> string_;
	shared_ptr<EnumerationType> enumeration_;
public:
	void name(string new_name);
	string name();
	string description();
	void description(string new_description);
	SimpleType GetType();
};

#endif
