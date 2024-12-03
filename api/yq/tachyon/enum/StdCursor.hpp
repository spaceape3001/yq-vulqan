////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    enum class StdCursor {
        Arrow           = 0,
        IBeam,
        Crosshair,
        PointingHand,
        ResizeEW,
        ResizeNS,
        ResizeAll,
        NotAllowed
    };
}
