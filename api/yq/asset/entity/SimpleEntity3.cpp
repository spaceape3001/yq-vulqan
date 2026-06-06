////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleEntity3.hpp"
#include <yq/tachyon/entity/Entity3MetaWriter.hpp>

namespace yq::tachyon {
    SimpleEntity³::SimpleEntity³(const Param&p) : Entity³(p)
    {
    }
    
    SimpleEntity³::~SimpleEntity³()
    {
    }
    
    void SimpleEntity³::init_meta()
    {
        auto w = writer<SimpleEntity³>();
        w.description("Standard 3D Entity");
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleEntity³)
