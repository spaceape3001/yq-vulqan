////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/manipulator/Manipulator.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
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
