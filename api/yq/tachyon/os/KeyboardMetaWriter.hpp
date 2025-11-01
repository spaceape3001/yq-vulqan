////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Keyboard.hpp>
#include <tachyon/os/KeyboardData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class KeyboardMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(KeyboardMeta* keyboardInfo) : TachyonMeta::Writer<C>(keyboardInfo)
        {
        }
        
        Writer(KeyboardMeta& keyboardInfo) : Writer(&keyboardInfo)
        {
        }
    };

}
