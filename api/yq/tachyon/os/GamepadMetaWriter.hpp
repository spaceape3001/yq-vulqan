////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/Gamepad.hpp>
#include <yq/tachyon/os/GamepadData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

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
