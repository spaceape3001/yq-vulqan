////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Joystick.hpp>
#include <tachyon/os/JoystickData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class JoystickMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(JoystickMeta* joystickInfo) : TachyonMeta::Writer<C>(joystickInfo)
        {
        }
        
        Writer(JoystickMeta& joystickInfo) : Writer(&joystickInfo)
        {
        }
    };

}
