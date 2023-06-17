////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Mode for the present queue
    
        This governs how the present queue manages when submitting tasks.
    */
    YQ_ENUM(PresentMode, ,
        Immediate = 0,  //< Max FPS, faster than video can handle, tearing can occur
        Mailbox = 1,
        Fifo = 2,
        FifoRelaxed = 3,
        SharedDeemand = 1000111000,
        SharedContinuous = 1000111001
    )
}

YQ_TYPE_DECLARE(yq::tachyon::PresentMode)
