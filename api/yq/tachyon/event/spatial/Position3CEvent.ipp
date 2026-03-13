////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³CEvent)

namespace yq::tachyon {
    Position³CEvent::Position³CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position³CEvent::Position³CEvent(const Header&h, const Centimeter3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position³CEvent::Position³CEvent(const Position³CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position³CEvent::~Position³CEvent()
    {
    }

    PostCPtr    Position³CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position³CEvent(*this, h);
    }
   
    void Position³CEvent::init_meta()
    {
        auto w = writer<Position³CEvent>();
        w.description("Position Event in 3D (meters)");
        w.property("x", &Position³CEvent::x).tag(kTag_Log);
        w.property("y", &Position³CEvent::y).tag(kTag_Log);
        w.property("z", &Position³CEvent::z).tag(kTag_Log);
        w.property("position", &Position³CEvent::m_position).tag(kTag_Save);
    }
}
