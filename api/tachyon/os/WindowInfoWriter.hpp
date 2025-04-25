////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Window.hpp>
#include <tachyon/os/WindowData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class WindowInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(WindowInfo* windowInfo) : TachyonInfo::Writer<C>(windowInfo)
        {
        }
        
        Writer(WindowInfo& windowInfo) : Writer(&windowInfo)
        {
        }
    };

}
