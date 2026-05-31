////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³Event)

namespace yq::tachyon {
    Circular³Event::Circular³Event(const Header& h) : SpatialEvent(h)
    {
    }
    
    Circular³Event::Circular³Event(const Circular³Event&cp, const Header&h) : SpatialEvent(cp, h)
    {
    }

    Circular³Event::~Circular³Event()
    {
    }
    
    void Circular³Event::init_meta()
    {
        auto w = writer<Circular³Event>();
        w.abstract();
        w.description("Circular³ Event");
    }
}
