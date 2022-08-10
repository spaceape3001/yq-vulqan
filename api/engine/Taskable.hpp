////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <basic/MetaObject.hpp>

namespace yq {
    namespace engine {
    
        struct SimData;

        class TaskableInfo : public MetaObjectInfo {
        public:
            template <typename C> class Writer;
            TaskableInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
        };
    
        class Taskable : public MetaObject {
            YQ_OBJECT_INFO(TaskableInfo)
            YQ_OBJECT_DECLARE(Taskable, MetaObject)
        public:
            virtual void    step(SimData&) = 0;
            
        protected:
            Taskable();
            virtual ~Taskable();
        };

        template <typename C>
        class TaskableInfo::Writer : public MetaObjectInfo::Writer<C> {
        public:
            Writer(TaskableInfo* assetInfo) : MetaObjectInfo::Writer<C>(assetInfo)
            {
            }
            
            Writer(TaskableInfo& assetInfo) : Writer(&assetInfo)
            {
            }
        };

    }
}

