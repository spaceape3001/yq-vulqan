////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize1DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize¹DEvent)

namespace yq::tachyon {
    MinSize¹DEvent::MinSize¹DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize¹DEvent::MinSize¹DEvent(const Header&h, const Size1D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize¹DEvent::MinSize¹DEvent(const MinSize¹DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize¹DEvent::~MinSize¹DEvent()
    {
    }

    PostCPtr    MinSize¹DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize¹DEvent(*this, h);
    }
   
    void MinSize¹DEvent::init_meta()
    {
        auto w = writer<MinSize¹DEvent>();
        w.description("Min Size Event in 1D");
        w.property("x", &MinSize¹DEvent::x).tag(kTag_Log);
        w.property("size", &MinSize¹DEvent::m_size).tag(kTag_Save);
    }
}
