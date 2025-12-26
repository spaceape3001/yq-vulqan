////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Gesture.hpp>
#include <yq/meta/ObjectMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GestureMeta::Writer : public ObjectMeta::Writer<C> {
    public:
        Writer(GestureMeta* manipInfo) : ObjectMeta::Writer<C>(manipInfo)
        {
        }
        
        Writer(GestureMeta& manipInfo) : Writer(&manipInfo)
        {
        }
    };
    
}
