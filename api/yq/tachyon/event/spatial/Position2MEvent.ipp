////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position2MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position²MEvent)

namespace yq::tachyon {
    Position²MEvent::Position²MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position²MEvent::Position²MEvent(const Header&h, const Meter2D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position²MEvent::Position²MEvent(const Position²MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position²MEvent::~Position²MEvent()
    {
    }

    PostCPtr    Position²MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position²MEvent(*this, h);
    }
   
    void Position²MEvent::init_meta()
    {
        auto w = writer<Position²MEvent>();
        w.description("Position Event in 2D (meters)");
        w.property("x", &Position²MEvent::x).tag(kTag_Log);
        w.property("y", &Position²MEvent::y).tag(kTag_Log);
        w.property("position", &Position²MEvent::m_position).tag(kTag_Save);
    }
}
