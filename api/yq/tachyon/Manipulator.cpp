////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Manipulator.hpp"
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Manipulator)

namespace yq::tachyon {
        
    ManipulatorInfo::ManipulatorInfo(std::string_view name, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(name, base, sl)
    {
        set(Flag::MANIPULATOR);
    }
    
    Manipulator::Manipulator()
    {
    }
    
    Manipulator::~Manipulator()
    {
    }
    
    
    static void reg_manipulator()
    {
        {
            auto w = writer<Manipulator>();
            w.description("Manipulator base");
        }
    }
    
    YQ_INVOKE(reg_manipulator();)
}
