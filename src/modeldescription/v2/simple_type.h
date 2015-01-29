#ifndef MODELDESCRIPTION_V2_SIMPLETYPE_H_
#define MODELDESCRIPTION_V2_SIMPLETYPE_H_

#include <unordered_map>
#include <string>
#include <memory>

using std::unordered_map;
using std::string;
using std::shared_ptr;

class RealType;
class IntegerType;
class BooleanType;
class StringType;
class EnumerationType;

struct SimpleType{
private:
	unordered_map<string, string> attributes_;
	shared_ptr<RealType> real_;
	shared_ptr<IntegerType> integer_;
	shared_ptr<BooleanType> boolean_;
	shared_ptr<StringType> string_;
	shared_ptr<EnumerationType> enumeration_;
public:
	unordered_map<string, string> attributes();
	void set_attributes(unordered_map<string, string> attributes);
	SimpleType type();
};

#endif
