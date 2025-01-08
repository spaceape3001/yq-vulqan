////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Move2Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Move²Event)

namespace yq::tachyon {
    Move²Event::Move²Event(const Header&h, const Vector2D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Move²Event::Move²Event(const Move²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Move²Event::~Move²Event()
    {
    }

    PostCPtr    Move²Event::clone(rebind_k, const Header& h) const 
    {
        return new Move²Event(*this, h);
    }
   
    void Move²Event::init_info()
    {
        auto w = writer<Move²Event>();
        w.description("Position Moved Event in 2D");
        w.property("x", &Move²Event::x);
        w.property("y", &Move²Event::y);
    }
}
