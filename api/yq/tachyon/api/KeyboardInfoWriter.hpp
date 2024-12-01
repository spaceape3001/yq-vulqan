////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Keyboard.hpp>
#include <yq/tachyon/api/KeyboardData.hpp>
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
