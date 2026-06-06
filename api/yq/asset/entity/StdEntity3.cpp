////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "StdEntity3.hpp"
#include <yq/tachyon/api/Entity3MetaWriter.hpp>

namespace yq::tachyon {
    StdEntity³::StdEntity³(const Param&p) : Entity³(p)
    {
    }
    
    StdEntity³::~StdEntity³()
    {
    }
    
    void StdEntity³::init_meta()
    {
        auto w = writer<StdEntity³>();
        w.description("Standard 3D Entity");
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::StdEntity³)
