////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Entity3.hpp>

namespace yq::tachyon {
    class SimpleEntity³ : public Entity³ {
        YQ_TACHYON_DECLARE(SimpleEntity³, Entity³)
    public:
    
        SimpleEntity³(const Param&p={});
        ~SimpleEntity³();
        
        static void init_meta();
    };
    
}
