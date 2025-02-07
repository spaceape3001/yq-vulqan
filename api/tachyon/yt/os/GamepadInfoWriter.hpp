////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Gamepad.hpp>
#include <yt/os/GamepadData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

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
