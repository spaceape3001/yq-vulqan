////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Move1Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Move¹Event)

namespace yq::tachyon {
    Move¹Event::Move¹Event(const Header&h, const Vector1D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Move¹Event::Move¹Event(const Move¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Move¹Event::~Move¹Event()
    {
    }

    PostCPtr    Move¹Event::clone(rebind_k, const Header& h) const 
    {
        return new Move¹Event(*this, h);
    }
   
    void Move¹Event::init_info()
    {
        auto w = writer<Move¹Event>();
        w.description("Position Moved Event in 1D");
        w.property("x", &Move¹Event::x);
    }
}
