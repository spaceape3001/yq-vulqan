////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MLayer : public MTachyon {
        YQ_TACHYON_DECLARE(MLayer, MTachyon)
        Q_OBJECT
    public:
    
        MLayer(TypedID);
        ~MLayer();
        
        static void init_meta();
    };
}
