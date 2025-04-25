////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Position1Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position¹Event)

namespace yq::tachyon {
    Position¹Event::Position¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position¹Event::Position¹Event(const Header&h, const Vector1D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Position¹Event::Position¹Event(const Position¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position¹Event::~Position¹Event()
    {
    }

    PostCPtr    Position¹Event::clone(rebind_k, const Header& h) const 
    {
        return new Position¹Event(*this, h);
    }
   
    void Position¹Event::init_info()
    {
        auto w = writer<Position¹Event>();
        w.description("Position Positiond Event in 1D");
        w.property("x", &Position¹Event::x).tag(kTag_Log);
        w.property("position", &Position¹Event::m_position).tag(kTag_Save);
    }
}
