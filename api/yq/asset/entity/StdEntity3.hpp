////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Entity3.hpp>

namespace yq::tachyon {
    class StdEntity³ : public Entity³ {
        YQ_TACHYON_DECLARE(StdEntity³, Entity³)
    public:
    
        StdEntity³(const Param&p={});
        ~StdEntity³();
        
        static void init_meta();
    };
    
}
