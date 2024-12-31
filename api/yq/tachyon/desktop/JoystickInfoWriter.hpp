////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/Joystick.hpp>
#include <yq/tachyon/desktop/JoystickData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

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
