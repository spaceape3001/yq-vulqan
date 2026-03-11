////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/Position1MEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position¹MEvent)

namespace yq::tachyon {
    Position¹MEvent::Position¹MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position¹MEvent::Position¹MEvent(const Header&h, const Meter1D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Position¹MEvent::Position¹MEvent(const Position¹MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position¹MEvent::~Position¹MEvent()
    {
    }

    PostCPtr    Position¹MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position¹MEvent(*this, h);
    }
   
    void Position¹MEvent::init_meta()
    {
        auto w = writer<Position¹MEvent>();
        w.description("Position Positiond Event in 1D");
        w.property("x", &Position¹MEvent::x).tag(kTag_Log);
        w.property("position", &Position¹MEvent::m_position).tag(kTag_Save);
    }
}
