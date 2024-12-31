////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/Window.hpp>
#include <yq/tachyon/desktop/WindowData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

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
