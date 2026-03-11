////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/Size1DEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size¹DEvent)

namespace yq::tachyon {
    Size¹DEvent::Size¹DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size¹DEvent::Size¹DEvent(const Header&h, const Size1D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size¹DEvent::Size¹DEvent(const Size¹DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size¹DEvent::~Size¹DEvent()
    {
    }

    PostCPtr    Size¹DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size¹DEvent(*this, h);
    }
   
    void Size¹DEvent::init_meta()
    {
        auto w = writer<Size¹DEvent>();
        w.description("Size Event in 1D");
        w.property("x", &Size¹DEvent::x).tag(kTag_Log);
        w.property("size", &Size¹DEvent::m_size).tag(kTag_Save);
    }
}
