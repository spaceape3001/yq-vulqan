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
    class JoystickInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(JoystickInfo* joystickInfo) : TachyonMeta::Writer<C>(joystickInfo)
        {
        }
        
        Writer(JoystickInfo& joystickInfo) : Writer(&joystickInfo)
        {
        }
    };

}
