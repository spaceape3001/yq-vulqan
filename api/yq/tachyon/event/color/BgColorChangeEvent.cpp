////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BgColorChangeEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BgColorChangeEvent)

namespace yq::tachyon {

    BgColorChangeEvent::BgColorChangeEvent(const Header&h, const RGBA4F& clr) : ColorEvent(h), m_bgcolor(clr)
    {
    }

    BgColorChangeEvent::BgColorChangeEvent(const BgColorChangeEvent& cp, const Header& h) : 
        ColorEvent(cp, h), m_bgcolor(cp.m_bgcolor)
    {
    }
    
    BgColorChangeEvent::~BgColorChangeEvent()
    {
    }

    PostCPtr    BgColorChangeEvent::clone(rebind_k, const Header&h) const 
    {
        return new BgColorChangeEvent(*this, h);
    }

    void        BgColorChangeEvent::set_bgcolor(const RGBA4F& v)
    {
        m_bgcolor = v;
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void BgColorChangeEvent::init_meta()
    {
        auto w = writer<BgColorChangeEvent>();
        w.description("BgColor Change Event");
        w.property("bgcolor", &BgColorChangeEvent::m_bgcolor).tag({kTag_Log});
    }
}
