////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <yq/tags.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Save)

namespace yq::tachyon {
    Save::Save(SaveType st) : m_type(st)
    {
    }
    
    Save::~Save()
    {
    }
    
    void    Save::init_meta()
    {
        auto w  = writer<Save>();
        w.description("Tachyon Save");
        w.property("type", &Save::m_type).tag({kTag_Save});
    }
}
