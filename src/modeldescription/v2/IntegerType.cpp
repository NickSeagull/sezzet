#include "IntegerType.h"

IntegerType::IntegerType(){}

string IntegerType::declared_type(){return declared_type_;}
void IntegerType::declared_type(string new_declared_type){declared_type_ = new_declared_type;}
string IntegerType::quantity(){return quantity_;}
void IntegerType::quantity(string new_quantity){quantity_ = new_quantity;}
double IntegerType::min(){return min_;}
void IntegerType::min(double new_min){min_ = new_min;}
double IntegerType::max(){return max_;}
void IntegerType::max(double new_max){max_ = new_max;}
int IntegerType::start(){return start_;}
void IntegerType::start(int new_start){start_ = new_start;}




