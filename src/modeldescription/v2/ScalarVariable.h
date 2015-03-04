#ifndef MODELDESCRIPTION_V2_SCALARVARIABLE_H_
#define MODELDESCRIPTION_V2_SCALARVARIABLE_H_

#include <string>
#include <memory>
#include "RealType.h"
#include "IntegerType.h"
#include "BooleanType.h"
#include "StringType.h"
#include "EnumerationType.h"
#include "Tool.h"

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
	shared_ptr<StringType> stringg_;
	shared_ptr<EnumerationType> enumeration_;
	vector<Tool> annotations_;
	shared_ptr<SimpleType> type_;
	string type_name_;
public:
	void can_handle_multiple_set_per_time_instant(bool new_can_handle_multiple_set_per_time_instant);
	bool can_handle_multiple_set_per_time_instant();
	void previous(int new_previous);
	int previous();
	void initial(string new_initial);
	string initial();
	void description(string new_description);
	string description();
	void name(string new_name);
	string name();
	void variability(string new_variability);
	string variability();
	void causality(string new_causality);
	string causality();
    ScalarVariable();
	shared_ptr<RealType> real();
	void real(shared_ptr<RealType> real);
	shared_ptr<IntegerType> integer();
	void integer(shared_ptr<IntegerType> integer);
	shared_ptr<StringType> stringg();
	void stringg(shared_ptr<StringType> stringg);
	shared_ptr<EnumerationType> enumeration();
	void enumeration(shared_ptr<EnumerationType> enumeration);
	vector<Tool> annotations();
	void AddAnnotation(Tool tool);
	shared_ptr<BooleanType> boolean();
	void boolean(shared_ptr<BooleanType> new_boolean);
	void annotations(vector<Tool> annotations);
	shared_ptr<SimpleType> type();
	void type(shared_ptr<SimpleType> type);
	std::string type_name();
	void type_name(std::string type_name);

};


#endif
