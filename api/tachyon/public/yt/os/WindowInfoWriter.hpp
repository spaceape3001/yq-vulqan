////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Window.hpp>
#include <yt/os/WindowData.hpp>
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
