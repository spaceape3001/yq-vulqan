////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position4CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position⁴CMEvent)

namespace yq::tachyon {
    Position⁴CMEvent::Position⁴CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position⁴CMEvent::Position⁴CMEvent(const Header&h, const Centimeter4D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position⁴CMEvent::Position⁴CMEvent(const Position⁴CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position⁴CMEvent::~Position⁴CMEvent()
    {
    }

    PostCPtr    Position⁴CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position⁴CMEvent(*this, h);
    }
   
    void Position⁴CMEvent::init_meta()
    {
        auto w = writer<Position⁴CMEvent>();
        w.description("Position Positiond Event in 4D");
        w.property("x", &Position⁴CMEvent::x).tag(kTag_Log);
        w.property("y", &Position⁴CMEvent::y).tag(kTag_Log);
        w.property("z", &Position⁴CMEvent::z).tag(kTag_Log);
        w.property("w", &Position⁴CMEvent::w).tag(kTag_Log);
        w.property("position", &Position⁴CMEvent::m_position).tag(kTag_Save);
    }
}
