////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position4MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position⁴MEvent)

namespace yq::tachyon {
    Position⁴MEvent::Position⁴MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position⁴MEvent::Position⁴MEvent(const Header&h, const Meter4D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position⁴MEvent::Position⁴MEvent(const Position⁴MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position⁴MEvent::~Position⁴MEvent()
    {
    }

    PostCPtr    Position⁴MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position⁴MEvent(*this, h);
    }
   
    void Position⁴MEvent::init_meta()
    {
        auto w = writer<Position⁴MEvent>();
        w.description("Position Positiond Event in 4D");
        w.property("x", &Position⁴MEvent::x).tag(kTag_Log);
        w.property("y", &Position⁴MEvent::y).tag(kTag_Log);
        w.property("z", &Position⁴MEvent::z).tag(kTag_Log);
        w.property("w", &Position⁴MEvent::w).tag(kTag_Log);
        w.property("position", &Position⁴MEvent::m_position).tag(kTag_Save);
    }
}
