////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position1DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position¹DEvent)

namespace yq::tachyon {
    Position¹DEvent::Position¹DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position¹DEvent::Position¹DEvent(const Header&h, const Vector1D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Position¹DEvent::Position¹DEvent(const Position¹DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position¹DEvent::~Position¹DEvent()
    {
    }

    PostCPtr    Position¹DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position¹DEvent(*this, h);
    }
   
    void Position¹DEvent::init_meta()
    {
        auto w = writer<Position¹DEvent>();
        w.description("Position Positiond Event in 1D");
        w.property("x", &Position¹DEvent::x).tag(kTag_Log);
        w.property("position", &Position¹DEvent::m_position).tag(kTag_Save);
    }
}
