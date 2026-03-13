////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position2CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position²CEvent)

namespace yq::tachyon {
    Position²CEvent::Position²CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position²CEvent::Position²CEvent(const Header&h, const Centimeter2D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position²CEvent::Position²CEvent(const Position²CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position²CEvent::~Position²CEvent()
    {
    }

    PostCPtr    Position²CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position²CEvent(*this, h);
    }
   
    void Position²CEvent::init_meta()
    {
        auto w = writer<Position²CEvent>();
        w.description("Position Event in 2D (meters)");
        w.property("x", &Position²CEvent::x).tag(kTag_Log);
        w.property("y", &Position²CEvent::y).tag(kTag_Log);
        w.property("position", &Position²CEvent::m_position).tag(kTag_Save);
    }
}
