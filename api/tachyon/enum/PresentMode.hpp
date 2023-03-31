////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(PresentMode, ,
            Immediate = 0,
            Mailbox = 1,
            Fifo = 2,
            FifoRelaxed = 3,
            SharedDeemand = 1000111000,
            SharedContinuous = 1000111001
        )
    }
}
YQ_TYPE_DECLARE(yq::tachyon::PresentMode)
