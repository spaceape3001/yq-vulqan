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
    class WindowInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(WindowInfo* windowInfo) : TachyonMeta::Writer<C>(windowInfo)
        {
        }
        
        Writer(WindowInfo& windowInfo) : Writer(&windowInfo)
        {
        }
    };

}
