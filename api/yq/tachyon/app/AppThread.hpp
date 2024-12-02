////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class AppThread : public Thread {
        YQ_TACHYON_DECLARE(AppThread, Thread)
    public:
        AppThread(const Param&p ={});
        ~AppThread();
        static void init_info();
    };
}
