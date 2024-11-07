////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    class ManipulatorInfo : public ObjectInfo {
    public:
        template <class> class Writer;
        ManipulatorInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    
    /*! \brief Controls the camera
    
        The manipulator is about controlling the camera/viewer with user input.
    */
    class Manipulator : public Object {
        YQ_OBJECT_INFO(ManipulatorInfo)
        YQ_OBJECT_DECLARE(Manipulator, Object)
    public:
        
        //  Manipulator TODO
        Manipulator();
        virtual ~Manipulator();
        
        static void init_info();
    };
    
    template <typename C>
    class ManipulatorInfo::Writer : public ObjectInfo::Writer<C> {
    public:
        Writer(ManipulatorInfo* manipInfo) : ObjectInfo::Writer<C>(manipInfo)
        {
        }
        
        Writer(ManipulatorInfo& manipInfo) : Writer(&manipInfo)
        {
        }
    };
    
}
