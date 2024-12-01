////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Joystick.hpp>
#include <yq/tachyon/api/JoystickData.hpp>
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
