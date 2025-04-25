////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Mouse.hpp>
#include <tachyon/os/MouseData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

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
