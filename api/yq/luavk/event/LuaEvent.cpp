////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/event/LuaEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaEvent)

namespace yq::lua {
    LuaEvent::LuaEvent(const Header& h) : tachyon::Event(h)
    {
    }
    
    LuaEvent::LuaEvent(const LuaEvent&cp, const Header&h) : tachyon::Event(cp, h)
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
