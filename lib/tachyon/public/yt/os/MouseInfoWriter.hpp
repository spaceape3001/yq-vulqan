////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Mouse.hpp>
#include <yt/os/MouseData.hpp>
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
