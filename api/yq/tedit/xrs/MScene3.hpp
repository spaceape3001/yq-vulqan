////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MScene.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MScene3 : public MScene {
        YQ_TACHYON_DECLARE(MScene3, MScene)
        Q_OBJECT
    public:
    
        MScene3(TypedID);
        ~MScene3();
        
        static void init_meta();
    };
}
