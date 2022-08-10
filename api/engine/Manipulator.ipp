////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Manipulator.hpp"
#include <basic/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::engine::Manipulator)

namespace yq {
    namespace engine {
        
        ManipulatorInfo::ManipulatorInfo(std::string_view name, MetaObjectInfo& base, const std::source_location& sl) :
            MetaObjectInfo(name, base, sl)
        {
        }
        
        Manipulator::Manipulator()
        {
        }
        
        Manipulator::~Manipulator()
        {
        }
        
        
        YQ_INVOKE(
            [[maybe_unused]] auto manip = writer<Manipulator>();
        )
    
    }
}
