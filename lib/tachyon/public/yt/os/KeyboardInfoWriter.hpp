////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Keyboard.hpp>
#include <yt/os/KeyboardData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class KeyboardInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(KeyboardInfo* keyboardInfo) : TachyonInfo::Writer<C>(keyboardInfo)
        {
        }
        
        Writer(KeyboardInfo& keyboardInfo) : Writer(&keyboardInfo)
        {
        }
    };

}
