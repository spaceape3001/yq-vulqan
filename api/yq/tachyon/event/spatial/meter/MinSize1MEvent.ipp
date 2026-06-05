////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize1MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize¹MEvent)

namespace yq::tachyon {
    MinSize¹MEvent::MinSize¹MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize¹MEvent::MinSize¹MEvent(const Header&h, const Size1M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize¹MEvent::MinSize¹MEvent(const MinSize¹MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize¹MEvent::~MinSize¹MEvent()
    {
    }

    PostCPtr    MinSize¹MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize¹MEvent(*this, h);
    }
   
    void MinSize¹MEvent::init_meta()
    {
        auto w = writer<MinSize¹MEvent>();
        w.description("Min Size Event in 1D");
        w.property("x", &MinSize¹MEvent::x).tag(kTag_Log);
        w.property("size", &MinSize¹MEvent::m_size).tag(kTag_Save);
    }
}
