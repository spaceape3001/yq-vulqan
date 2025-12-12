////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetHeightFieldEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/tachyon/asset/HeightField.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetHeightFieldEvent)

namespace yq::tachyon {

    SetHeightFieldEvent::SetHeightFieldEvent(const Header&h, const HeightFieldCPtr& dm, const Url& u) : Event(h), m_heightField(dm), m_url(u)
    {
    }

    SetHeightFieldEvent::SetHeightFieldEvent(const SetHeightFieldEvent& cp, const Header& h) : 
        Event(cp, h), m_heightField(cp.m_heightField)
    {
    }
    
    SetHeightFieldEvent::~SetHeightFieldEvent()
    {
    }

    PostCPtr    SetHeightFieldEvent::clone(rebind_k, const Header&h) const 
    {
        return new SetHeightFieldEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetHeightFieldEvent::init_meta()
    {
        auto w = writer<SetHeightFieldEvent>();
        w.description("Set Height Field Event");
        w.property("url", &SetHeightFieldEvent::m_url);
    }
}
