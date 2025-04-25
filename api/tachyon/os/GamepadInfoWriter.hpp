////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Gamepad.hpp>
#include <tachyon/os/GamepadData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GamepadInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(GamepadInfo* gamepadInfo) : TachyonInfo::Writer<C>(gamepadInfo)
        {
        }
        
        Writer(GamepadInfo& gamepadInfo) : Writer(&gamepadInfo)
        {
        }
    };

}
