#ifndef MODELDESCRIPTION_V2_SCALARVARIABLE_H_
#define MODELDESCRIPTION_V2_SCALARVARIABLE_H_

#include <string>
#include <memory>
#include "real_type.h"
#include "integer_type.h"
#include "boolean_type.h"
#include "string_type.h"
#include "enumeration_type.h"
#include "tool.h"

using std::string;
using std::shared_ptr;

class ScalarVariable{
private:
	string causality_;
	string variability_;
	string name_;
	string description_;
	string initial_;
	int previous_;
	bool can_handle_multiple_set_per_time_instant_;
	
	shared_ptr<RealType> real_;
	shared_ptr<IntegerType> integer_;
	shared_ptr<BooleanType> boolean_;
	shared_ptr<StringType> string_;
	shared_ptr<EnumerationType> enumeration_;
	vector<shared_ptr<Tool>> annotations_;
	shared_ptr<SimpleType> type_;
	string type_name_;
public:
	inline void can_handle_multiple_set_per_time_instant(bool new_can_handle_multiple_set_per_time_instant);
	inline bool can_handle_multiple_set_per_time_instant();
	inline void previous(int new_previous);
	inline int previous();
	inline void initial(string new_initial);
	inline string initial();
	inline void description(string new_description);
	inline string description();
	inline void name(string new_name);
	inline string name();
	inline void variability(string new_variability);
	inline string variability();
	inline void causality(string new_causality);
	inline string causality();
    ScalarVariable();
	inline shared_ptr<RealType> real();
	inline void real(shared_ptr<RealType> real);
	inline shared_ptr<IntegerType> integer();
	inline void integer(shared_ptr<IntegerType> integer);
	inline shared_ptr<StringType> string();
	inline void string(shared_ptr<StringType> string);
	inline shared_ptr<EnumerationType> enumeration();
	inline void enumeration(shared_ptr<EnumerationType> enumeration);
	inline vector<shared_ptr<Tool>> annotations();
	inline void annotations(vector<shared_ptr<Tool>> annotations);
	inline shared_ptr<SimpleType> type();
	inline void type(shared_ptr<SimpleType> type);
	inline std::string type_name();
	inline void type_name(std::string type_name);

};


#endif
