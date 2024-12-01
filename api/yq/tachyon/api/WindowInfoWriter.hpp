////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Window.hpp>
#include <yq/tachyon/api/WindowData.hpp>
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
