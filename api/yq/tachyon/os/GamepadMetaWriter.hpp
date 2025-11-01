////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Gamepad.hpp>
#include <tachyon/os/GamepadData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GamepadMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(GamepadMeta* gamepadInfo) : TachyonMeta::Writer<C>(gamepadInfo)
        {
        }
        
        Writer(GamepadMeta& gamepadInfo) : Writer(&gamepadInfo)
        {
        }
    };

}
