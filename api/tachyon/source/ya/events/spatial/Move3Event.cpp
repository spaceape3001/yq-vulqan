////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Move3Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Move³Event)

namespace yq::tachyon {
    Move³Event::Move³Event(const Header&h, const Vector3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Move³Event::Move³Event(const Move³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Move³Event::~Move³Event()
    {
    }

    PostCPtr    Move³Event::clone(rebind_k, const Header& h) const 
    {
        return new Move³Event(*this, h);
    }
   
    void Move³Event::init_info()
    {
        auto w = writer<Move³Event>();
        w.description("Position Moved Event in 3D");
        w.property("x", &Move³Event::x);
        w.property("y", &Move³Event::y);
        w.property("z", &Move³Event::z);
    }
}
