////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize1CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize¹CEvent)

namespace yq::tachyon {
    MinSize¹CEvent::MinSize¹CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize¹CEvent::MinSize¹CEvent(const Header&h, const Size1CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize¹CEvent::MinSize¹CEvent(const MinSize¹CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize¹CEvent::~MinSize¹CEvent()
    {
    }

    PostCPtr    MinSize¹CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize¹CEvent(*this, h);
    }
   
    void MinSize¹CEvent::init_meta()
    {
        auto w = writer<MinSize¹CEvent>();
        w.description("Min Size Event in 1D");
        w.property("x", &MinSize¹CEvent::x).tag(kTag_Log);
        w.property("size", &MinSize¹CEvent::m_size).tag(kTag_Save);
    }
}
