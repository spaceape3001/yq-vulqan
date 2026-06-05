////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position2CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position²CMEvent)

namespace yq::tachyon {
    Position²CMEvent::Position²CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position²CMEvent::Position²CMEvent(const Header&h, const Centimeter2D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position²CMEvent::Position²CMEvent(const Position²CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position²CMEvent::~Position²CMEvent()
    {
    }

    PostCPtr    Position²CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position²CMEvent(*this, h);
    }
   
    void Position²CMEvent::init_meta()
    {
        auto w = writer<Position²CMEvent>();
        w.description("Position Event in 2D (meters)");
        w.property("x", &Position²CMEvent::x).tag(kTag_Log);
        w.property("y", &Position²CMEvent::y).tag(kTag_Log);
        w.property("position", &Position²CMEvent::m_position).tag(kTag_Save);
    }
}
