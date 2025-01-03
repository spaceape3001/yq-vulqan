////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Joystick.hpp>
#include <yt/os/JoystickData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class JoystickInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(JoystickInfo* joystickInfo) : TachyonInfo::Writer<C>(joystickInfo)
        {
        }
        
        Writer(JoystickInfo& joystickInfo) : Writer(&joystickInfo)
        {
        }
    };

}
