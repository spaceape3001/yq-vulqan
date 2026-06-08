////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/joystick.hpp>
#include <yq/tachyon/os/HatState.hpp>

namespace yq::tachyon {
    class JoystickSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(JoystickSnap, TachyonSnap)
    public:
        std::string             name, guid;
        std::vector<float>      axes;
        std::vector<bool>       buttons;
        std::vector<HatState>   hats;
        
        JoystickSnap();
        ~JoystickSnap();
        static void init_meta();
    };
    
    class JoystickData : public TachyonData {
        YQ_OBJECT_DECLARE(JoystickData, TachyonData)
    public:
        JoystickData();
        ~JoystickData();
        static void init_meta();
    };
}
