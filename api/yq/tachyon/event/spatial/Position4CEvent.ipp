////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position4CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position⁴CEvent)

namespace yq::tachyon {
    Position⁴CEvent::Position⁴CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position⁴CEvent::Position⁴CEvent(const Header&h, const Centimeter4D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position⁴CEvent::Position⁴CEvent(const Position⁴CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position⁴CEvent::~Position⁴CEvent()
    {
    }

    PostCPtr    Position⁴CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position⁴CEvent(*this, h);
    }
   
    void Position⁴CEvent::init_meta()
    {
        auto w = writer<Position⁴CEvent>();
        w.description("Position Positiond Event in 4D");
        w.property("x", &Position⁴CEvent::x).tag(kTag_Log);
        w.property("y", &Position⁴CEvent::y).tag(kTag_Log);
        w.property("z", &Position⁴CEvent::z).tag(kTag_Log);
        w.property("w", &Position⁴CEvent::w).tag(kTag_Log);
        w.property("position", &Position⁴CEvent::m_position).tag(kTag_Save);
    }
}
