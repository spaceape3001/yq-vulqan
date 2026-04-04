////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MModel : public MTachyon {
        YQ_TACHYON_DECLARE(MModel, MTachyon)
        Q_OBJECT
    public:
    
        MModel(TypedID);
        ~MModel();
        
        static void init_meta();
    };
}
