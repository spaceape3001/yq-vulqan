////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/LuaEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaEvent)

namespace yq::tachyon {
    LuaEvent::LuaEvent(const Header& h) : Event(h)
    {
    }
    
    LuaEvent::LuaEvent(const LuaEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    LuaEvent::~LuaEvent()
    {
    }
    
    void LuaEvent::init_meta()
    {
        auto w = writer<LuaEvent>();
        w.abstract();
        w.description("Lua Event");
    }
}
