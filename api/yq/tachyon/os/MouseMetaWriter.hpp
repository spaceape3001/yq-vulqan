////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/Mouse.hpp>
#include <yq/tachyon/os/MouseData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MouseMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(MouseMeta* mouseInfo) : TachyonMeta::Writer<C>(mouseInfo)
        {
        }
        
        Writer(MouseMeta& mouseInfo) : Writer(&mouseInfo)
        {
        }
    };

}
