////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Taskable.hpp"
#include <basic/DelayInit.hpp>

namespace yq {
    namespace engine {
        TaskableInfo::TaskableInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
            MetaObjectInfo(zName, base, sl)
        {
        }

        Taskable::Taskable()
        {
        }
        
        Taskable::~Taskable()
        {
        }
    }
}

YQ_OBJECT_IMPLEMENT(yq::engine::Taskable)
