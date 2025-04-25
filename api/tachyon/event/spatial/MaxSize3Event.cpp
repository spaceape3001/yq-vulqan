////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/MaxSize3Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize³Event)

namespace yq::tachyon {
    MaxSize³Event::MaxSize³Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize³Event::MaxSize³Event(const Header&h, const Size3D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize³Event::MaxSize³Event(const MaxSize³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize³Event::~MaxSize³Event()
    {
    }

    PostCPtr    MaxSize³Event::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize³Event(*this, h);
    }
   
    void MaxSize³Event::init_info()
    {
        auto w = writer<MaxSize³Event>();
        w.description("Max Size Event in 3D");
        w.property("x", &MaxSize³Event::x).tag(kTag_Log);
        w.property("y", &MaxSize³Event::y).tag(kTag_Log);
        w.property("z", &MaxSize³Event::z).tag(kTag_Log);
        w.property("size", &MaxSize³Event::m_size).tag(kTag_Save);
    }
}
