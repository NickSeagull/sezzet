#ifndef MODELDESCRIPTION_ELEMENTTREE_SOURCEFILEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_SOURCEFILEFILLER_H_

#include "../v2/SourceFile.h"
#include "Node.h"
#include <memory>

using std::shared_ptr;

class SourceFileFiller{
private:
    void SetField(SourceFile& source_file, string field_name, string field_value);
public:
	SourceFileFiller();
	void Fill(SourceFile& source_file, NodePointer node);
};


#endif
