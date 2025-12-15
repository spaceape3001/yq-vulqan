////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TessellationEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TessellationEvent)

namespace yq::tachyon {
    TessellationEvent::TessellationEvent(const Header& h) : Event(h)
    {
    }
    
    TessellationEvent::TessellationEvent(const TessellationEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    TessellationEvent::~TessellationEvent()
    {
    }
    
    void TessellationEvent::init_meta()
    {
        auto w = writer<TessellationEvent>();
        w.abstract();
        w.description("Tessellation Event");
    }
}
