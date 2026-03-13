////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize2CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize²CEvent)

namespace yq::tachyon {
    MinSize²CEvent::MinSize²CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize²CEvent::MinSize²CEvent(const Header&h, const Size2CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MinSize²CEvent::MinSize²CEvent(const MinSize²CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize²CEvent::~MinSize²CEvent()
    {
    }

    PostCPtr    MinSize²CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize²CEvent(*this, h);
    }
   
    void MinSize²CEvent::init_meta()
    {
        auto w = writer<MinSize²CEvent>();
        w.description("Min Size Event in 2D");
        w.property("x", &MinSize²CEvent::x).tag(kTag_Log);
        w.property("y", &MinSize²CEvent::y).tag(kTag_Log);
        w.property("size", &MinSize²CEvent::m_size).tag(kTag_Save);
    }
}
