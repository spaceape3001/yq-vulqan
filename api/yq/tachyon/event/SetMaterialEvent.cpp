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

    SetMaterialEvent::SetMaterialEvent(const Header&h, const MaterialCPtr& dm, const Url& u) : 
        Event(h), m_material(dm), m_url(u)
    {
    }

    SetMaterialEvent::SetMaterialEvent(const SetMaterialEvent& cp, const Header& h) : 
        Event(cp, h), m_material(cp.m_material), m_url(cp.m_url)
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
        w.property("url", &SetMaterialEvent::m_url);
    }
}
