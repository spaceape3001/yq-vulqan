////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YAppThread.hpp>

namespace yq::tachyon {
    struct TEAppThreadData;
    struct TEAppThreadSnap;
    class TEAppThread : public YAppThread {
        YQ_TACHYON_DATA(TEAppThreadData)
        YQ_TACHYON_SNAP(TEAppThreadSnap)
        YQ_TACHYON_DECLARE(TEAppThread, YAppThread)
        Q_OBJECT
    public:
    
        TEAppThread(int&, char*[], tachyon::Application&);
        ~TEAppThread();
        
        static void    init_meta();
    };
}
