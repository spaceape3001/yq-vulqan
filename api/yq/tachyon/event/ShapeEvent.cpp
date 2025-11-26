////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ShapeEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ShapeEvent)

namespace yq::tachyon {
    ShapeEvent::ShapeEvent(const Header& h) : Event(h)
    {
    }
    
    ShapeEvent::ShapeEvent(const ShapeEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    ShapeEvent::~ShapeEvent()
    {
    }
    
    void ShapeEvent::init_meta()
    {
        auto w = writer<ShapeEvent>();
        w.abstract();
        w.description("Shape Event");
    }
}
