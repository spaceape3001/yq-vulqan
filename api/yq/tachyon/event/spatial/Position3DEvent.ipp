////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³DEvent)

namespace yq::tachyon {
    Position³DEvent::Position³DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position³DEvent::Position³DEvent(const Header&h, const Vector3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position³DEvent::Position³DEvent(const Position³DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position³DEvent::~Position³DEvent()
    {
    }

    PostCPtr    Position³DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position³DEvent(*this, h);
    }
   
    void Position³DEvent::init_meta()
    {
        auto w = writer<Position³DEvent>();
        w.description("Position Event in 3D");
        w.property("x", &Position³DEvent::x).tag(kTag_Log);
        w.property("y", &Position³DEvent::y).tag(kTag_Log);
        w.property("z", &Position³DEvent::z).tag(kTag_Log);
        w.property("position", &Position³DEvent::m_position).tag(kTag_Save);
    }
}
