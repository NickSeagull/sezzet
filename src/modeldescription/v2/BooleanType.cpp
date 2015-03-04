#include "BooleanType.h"

BooleanType::BooleanType(){}

string BooleanType::declared_type(){return declared_type_;}
void BooleanType::declared_type(string new_declared_type){declared_type_ = new_declared_type;}
bool BooleanType::start(){return start_;}
void BooleanType::start(bool new_start){start_ = new_start;}

