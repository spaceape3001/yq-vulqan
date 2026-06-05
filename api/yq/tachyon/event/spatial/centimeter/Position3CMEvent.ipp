////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³CMEvent)

namespace yq::tachyon {
    Position³CMEvent::Position³CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position³CMEvent::Position³CMEvent(const Header&h, const Centimeter3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position³CMEvent::Position³CMEvent(const Position³CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position³CMEvent::~Position³CMEvent()
    {
    }

    PostCPtr    Position³CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position³CMEvent(*this, h);
    }
   
    void Position³CMEvent::init_meta()
    {
        auto w = writer<Position³CMEvent>();
        w.description("Position Event in 3D (meters)");
        w.property("x", &Position³CMEvent::x).tag(kTag_Log);
        w.property("y", &Position³CMEvent::y).tag(kTag_Log);
        w.property("z", &Position³CMEvent::z).tag(kTag_Log);
        w.property("position", &Position³CMEvent::m_position).tag(kTag_Save);
    }
}
