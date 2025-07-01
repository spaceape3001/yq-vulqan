////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Window.hpp>
#include <tachyon/os/WindowData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class WindowMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(WindowMeta* windowInfo) : TachyonMeta::Writer<C>(windowInfo)
        {
        }
        
        Writer(WindowMeta& windowInfo) : Writer(&windowInfo)
        {
        }
    };

}
