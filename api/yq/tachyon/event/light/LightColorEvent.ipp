////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightColorEvent.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LightColorEvent)

namespace yq::tachyon {

    LightColorEvent::LightColorEvent(const Header&h, const RGB3F& c) : LightEvent(h), m_color(c)
    {
    }

    LightColorEvent::LightColorEvent(const LightColorEvent& cp, const Header& h) : 
        LightEvent(cp, h), m_color(cp.m_color)
    {
    }
    
    LightColorEvent::~LightColorEvent()
    {
    }

    PostCPtr    LightColorEvent::clone(rebind_k, const Header&h) const 
    {
        return new LightColorEvent(*this, h);
    }

    void    LightColorEvent::set_color(const RGB3F&v)
    {
        m_color = v;
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LightColorEvent::init_meta()
    {
        auto w = writer<LightColorEvent>();
        w.description("Light Color Event");
        w.property("color", &LightColorEvent::m_color).tag({kTag_Save, kTag_Log});
    }
}
