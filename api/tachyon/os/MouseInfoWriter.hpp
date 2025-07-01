////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Mouse.hpp>
#include <tachyon/os/MouseData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MouseInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(MouseInfo* mouseInfo) : TachyonMeta::Writer<C>(mouseInfo)
        {
        }
        
        Writer(MouseInfo& mouseInfo) : Writer(&mouseInfo)
        {
        }
    };

}
