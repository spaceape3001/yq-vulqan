////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Keyboard.hpp>
#include <tachyon/os/KeyboardData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

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
