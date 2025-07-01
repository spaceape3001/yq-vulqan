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
    class KeyboardInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(KeyboardInfo* keyboardInfo) : TachyonMeta::Writer<C>(keyboardInfo)
        {
        }
        
        Writer(KeyboardInfo& keyboardInfo) : Writer(&keyboardInfo)
        {
        }
    };

}
