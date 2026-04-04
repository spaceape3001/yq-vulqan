////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MScene : public MTachyon {
        YQ_TACHYON_DECLARE(MScene, MTachyon)
        Q_OBJECT
    public:
    
        MScene(TypedID);
        ~MScene();
        
        static void init_meta();
    };
}
