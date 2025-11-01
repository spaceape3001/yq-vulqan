////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/Keyboard.hpp>
#include <yq/tachyon/os/KeyboardData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

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
