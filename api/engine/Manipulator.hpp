////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/MetaObject.hpp>

namespace yq {
    namespace engine {
        class ManipulatorInfo : public MetaObjectInfo {
        public:
            template <class> class Writer;
            ManipulatorInfo(std::string_view, MetaObjectInfo&, const std::source_location& sl = std::source_location::current());
        };
        
        
        /*! \brief Controls the camera
        
            The manipulator is about controlling the camera/viewer with user input.
        */
        class Manipulator : public MetaObject {
            YQ_OBJECT_INFO(ManipulatorInfo)
            YQ_OBJECT_DECLARE(Manipulator, MetaObject)
        public:
            
            //  Manipulator TODO
            
        protected:
            Manipulator();
            virtual ~Manipulator();
        };
        
        template <typename C>
        class ManipulatorInfo::Writer : public MetaObjectInfo::Writer<C> {
        public:
            Writer(ManipulatorInfo* manipInfo) : MetaObjectInfo::Writer<C>(manipInfo)
            {
            }
            
            Writer(ManipulatorInfo& manipInfo) : Writer(&manipInfo)
            {
            }
        };
        
    }
}
