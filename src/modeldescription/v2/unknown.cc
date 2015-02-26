#include "unknown.h"

Unknown::Unknown(){}

int Unknown::index(){return index_;}
void Unknown::index(int new_index){index_ = new_index;}
string Unknown::dependencies(){return dependencies_;}
void Unknown::dependencies(string new_dependencies){dependencies_ = new_dependencies;}
string Unknown::dependencies_kind(){return dependencies_kind_;}
void Unknown::dependencies_kind(string new_dependencies_kind){dependencies_kind_ = new_dependencies_kind;}


