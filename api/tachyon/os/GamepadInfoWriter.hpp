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
    class GamepadInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(GamepadInfo* gamepadInfo) : TachyonMeta::Writer<C>(gamepadInfo)
        {
        }
        
        Writer(GamepadInfo& gamepadInfo) : Writer(&gamepadInfo)
        {
        }
    };

}
