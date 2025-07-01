////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Gamepad;
    using GamepadPtr      = Ref<Gamepad>;
    using GamepadCPtr     = Ref<const Gamepad>;

    struct GamepadSnap;
    using GamepadSnapPtr  = Ref<GamepadSnap>;
    using GamepadSnapCPtr = Ref<const GamepadSnap>;
    
    struct GamepadData;
    using GamepadDataPtr  = Ref<GamepadData>;
    using GamepadDataCPtr = Ref<const GamepadData>;

    template <class> class ID;
    using GamepadID = ID<Gamepad>;
    
    class GamepadMeta;
}
