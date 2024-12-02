////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Mouse.hpp>
#include <yq/tachyon/api/MouseData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MouseInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(MouseInfo* mouseInfo) : TachyonInfo::Writer<C>(mouseInfo)
        {
        }
        
        Writer(MouseInfo& mouseInfo) : Writer(&mouseInfo)
        {
        }
    };

}
