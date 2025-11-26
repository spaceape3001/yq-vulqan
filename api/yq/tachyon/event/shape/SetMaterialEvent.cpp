////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaterialEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/tachyon/asset/Material.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaterialEvent)

namespace yq::tachyon {

    SetMaterialEvent::SetMaterialEvent(const Header&h, const MaterialCPtr& dm) : ShapeEvent(h), m_material(dm)
    {
    }

    SetMaterialEvent::SetMaterialEvent(const SetMaterialEvent& cp, const Header& h) : 
        ShapeEvent(cp, h), m_material(cp.m_material)
    {
    }
    
    SetMaterialEvent::~SetMaterialEvent()
    {
    }

    PostCPtr    SetMaterialEvent::clone(rebind_k, const Header&h) const 
    {
        return new SetMaterialEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMaterialEvent::init_meta()
    {
        auto w = writer<SetMaterialEvent>();
        w.description("Set Material Event");
    }
}
