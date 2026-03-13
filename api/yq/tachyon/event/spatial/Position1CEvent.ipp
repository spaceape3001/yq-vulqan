////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position1CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position¹CEvent)

namespace yq::tachyon {
    Position¹CEvent::Position¹CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position¹CEvent::Position¹CEvent(const Header&h, const Centimeter1D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Position¹CEvent::Position¹CEvent(const Position¹CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position¹CEvent::~Position¹CEvent()
    {
    }

    PostCPtr    Position¹CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position¹CEvent(*this, h);
    }
   
    void Position¹CEvent::init_meta()
    {
        auto w = writer<Position¹CEvent>();
        w.description("Position Positiond Event in 1D");
        w.property("x", &Position¹CEvent::x).tag(kTag_Log);
        w.property("position", &Position¹CEvent::m_position).tag(kTag_Save);
    }
}
