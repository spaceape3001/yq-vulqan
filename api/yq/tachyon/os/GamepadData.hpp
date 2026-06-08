////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/os/HatState.hpp>
#include <yq/tachyon/typedef/gamepad.hpp>

namespace yq::tachyon {
    class GamepadSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(GamepadSnap, TachyonSnap)
    public:
        std::string             name, guid;
        std::vector<float>      axes;
        std::vector<bool>       buttons;
        std::vector<HatState>   hats;
        
        GamepadSnap();
        virtual ~GamepadSnap();
        static void init_meta();
    };
    
    class GamepadData : public TachyonData {
        YQ_OBJECT_DECLARE(GamepadData, TachyonData)
    public:
        GamepadData();
        virtual ~GamepadData();
        static void init_meta();
    };
}
