////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position3Event)

namespace yq::tachyon {
    Position3Event::Position3Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position3Event::Position3Event(const Header&h, const Vector3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position3Event::Position3Event(const Position3Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position3Event::~Position3Event()
    {
    }

    PostCPtr    Position3Event::clone(rebind_k, const Header& h) const 
    {
        return new Position3Event(*this, h);
    }
   
    void Position3Event::init_meta()
    {
        auto w = writer<Position3Event>();
        w.description("Position Event in 3D");
        w.property("x", &Position3Event::x).tag(kTag_Log);
        w.property("y", &Position3Event::y).tag(kTag_Log);
        w.property("z", &Position3Event::z).tag(kTag_Log);
        w.property("position", &Position3Event::m_position).tag(kTag_Save);
    }
}
