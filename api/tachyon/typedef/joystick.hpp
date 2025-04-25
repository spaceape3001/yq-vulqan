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
    class Joystick;
    using JoystickPtr      = Ref<Joystick>;
    using JoystickCPtr     = Ref<const Joystick>;

    struct JoystickSnap;
    using JoystickSnapPtr  = Ref<JoystickSnap>;
    using JoystickSnapCPtr = Ref<const JoystickSnap>;
    
    struct JoystickData;
    using JoystickDataPtr  = Ref<JoystickData>;
    using JoystickDataCPtr = Ref<const JoystickData>;

    template <class> class ID;
    using JoystickID = ID<Joystick>;
}
