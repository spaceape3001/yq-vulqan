////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EventProducer.hpp>

namespace yq::tachyon {
    struct EventProducer::Thread {
        EventSocket*    socket  = nullptr;
    };
}
