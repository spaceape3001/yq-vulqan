////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Joystick.hpp>
#include <tachyon/os/JoystickData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

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
