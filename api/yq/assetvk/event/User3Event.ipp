////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³Event)

namespace yq::tachyon {
    User³Event::User³Event(const Header& h) : SpatialEvent(h)
    {
    }
    
    User³Event::User³Event(const User³Event&cp, const Header&h) : SpatialEvent(cp, h)
    {
    }

    User³Event::~User³Event()
    {
    }
    
    void User³Event::init_meta()
    {
        auto w = writer<User³Event>();
        w.abstract();
        w.description("User³ Event");
    }
}
