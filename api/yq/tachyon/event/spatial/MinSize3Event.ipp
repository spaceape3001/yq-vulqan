////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/MinSize3Event.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize³Event)

namespace yq::tachyon {
    MinSize³Event::MinSize³Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize³Event::MinSize³Event(const Header&h, const Size3D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize³Event::MinSize³Event(const MinSize³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize³Event::~MinSize³Event()
    {
    }

    PostCPtr    MinSize³Event::clone(rebind_k, const Header& h) const 
    {
        return new MinSize³Event(*this, h);
    }
   
    void MinSize³Event::init_meta()
    {
        auto w = writer<MinSize³Event>();
        w.description("Min Size Event in 3D");
        w.property("x", &MinSize³Event::x).tag(kTag_Log);
        w.property("y", &MinSize³Event::y).tag(kTag_Log);
        w.property("z", &MinSize³Event::z).tag(kTag_Log);
        w.property("size", &MinSize³Event::m_size).tag(kTag_Save);
    }
}
