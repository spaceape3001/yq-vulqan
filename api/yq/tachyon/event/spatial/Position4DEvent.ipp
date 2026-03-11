////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position4DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position⁴DEvent)

namespace yq::tachyon {
    Position⁴DEvent::Position⁴DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position⁴DEvent::Position⁴DEvent(const Header&h, const Vector4D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position⁴DEvent::Position⁴DEvent(const Position⁴DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position⁴DEvent::~Position⁴DEvent()
    {
    }

    PostCPtr    Position⁴DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position⁴DEvent(*this, h);
    }
   
    void Position⁴DEvent::init_meta()
    {
        auto w = writer<Position⁴DEvent>();
        w.description("Position Positiond Event in 4D");
        w.property("x", &Position⁴DEvent::x).tag(kTag_Log);
        w.property("y", &Position⁴DEvent::y).tag(kTag_Log);
        w.property("z", &Position⁴DEvent::z).tag(kTag_Log);
        w.property("w", &Position⁴DEvent::w).tag(kTag_Log);
        w.property("position", &Position⁴DEvent::m_position).tag(kTag_Save);
    }
}
