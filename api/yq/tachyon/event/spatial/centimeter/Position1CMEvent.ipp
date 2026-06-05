////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position1CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position¹CMEvent)

namespace yq::tachyon {
    Position¹CMEvent::Position¹CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position¹CMEvent::Position¹CMEvent(const Header&h, const Centimeter1D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Position¹CMEvent::Position¹CMEvent(const Position¹CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position¹CMEvent::~Position¹CMEvent()
    {
    }

    PostCPtr    Position¹CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position¹CMEvent(*this, h);
    }
   
    void Position¹CMEvent::init_meta()
    {
        auto w = writer<Position¹CMEvent>();
        w.description("Position Positiond Event in 1D");
        w.property("x", &Position¹CMEvent::x).tag(kTag_Log);
        w.property("position", &Position¹CMEvent::m_position).tag(kTag_Save);
    }
}
