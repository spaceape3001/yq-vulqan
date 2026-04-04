////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MThread : public MTachyon {
        YQ_TACHYON_DECLARE(MThread, MTachyon)
        Q_OBJECT
    public:
    
        MThread(TypedID);
        ~MThread();
        
        static void init_meta();
    };
}
