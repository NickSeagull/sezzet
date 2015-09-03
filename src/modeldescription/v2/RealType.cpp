#include "RealType.h"

RealType::RealType(){}

string RealType::declared_type(){return declared_type_;}
void RealType::declared_type(string new_declared_type){declared_type_ = new_declared_type;}
string RealType::quantity(){return quantity_;}
void RealType::quantity(string new_quantity){quantity_ = new_quantity;}
string RealType::unit(){return unit_;}
void RealType::unit(string new_unit){unit_ = new_unit;}
bool RealType::relative_quantity(){return relative_quantity_;}
void RealType::relative_quantity(bool new_relative_quantity){relative_quantity_ = new_relative_quantity;}
double RealType::min(){return min_;}
void RealType::min(double new_min){min_ = new_min;}
double RealType::max(){return max_;}
void RealType::max(double new_max){max_ = new_max;}
bool RealType::unbound(){return unbound_;}
void RealType::unbound(bool new_unbound){unbound_ = new_unbound;}
double RealType::start(){return start_;}
void RealType::start(double new_start){start_ = new_start;}
int RealType::derivative(){return derivative_;}
void RealType::derivative(int new_derivative){derivative_ = new_derivative;}
bool RealType::reinit(){return reinit_;}
void RealType::reinit(bool new_reinit){reinit_ = new_reinit;}
double RealType::nominal(){return nominal_;}
void RealType::nominal(double new_nominal){nominal_ = new_nominal;}











