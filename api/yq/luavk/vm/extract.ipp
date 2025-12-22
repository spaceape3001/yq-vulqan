////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "extract.hpp"
#include <yq/lua/lualua.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/Scene3.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <lua.hpp>

namespace yq::errors {
}

namespace yq::tachyon {
    Expect<CameraID>       cameraID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        uint64_t    id  = (uint64_t) *ix;
        
        if(*tmx == &meta<CameraID>())
            return CameraID(*ix);
        if(*tmx == &meta<Camera³ID>())
            return CameraID(*ix);
        const Frame*    frame   = Frame::current();
        if(!frame)
            return errors::no_frame_available();
        TypedID typeId  = frame->typed(TachyonID{*ix});
        if(typeId(Type::Camera))
            return CameraID{*ix};
        return errors::not_valid_camera_id();
    }
    
    Expect<LightID>        lightID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
        if(*tmx == &meta<LightID>)
            return LightID(*ix);
        if(*tmx == &meta<Light³ID>)
            return LightID(*ix);
        const Frame*    frame   = Frame::current();
        if(!frame)
            return errors::no_frame_available();
        TypedID typeId  = frame->typed({*ix});
        if(typedid(Type::Light))
            return LightID{*ix};
        return errors::not_valid_light_id();
    }
    
    Expect<RenderedID>     renderedID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
        if(*tmx == &meta<RenderedID>)
            return RenderedID(*ix);
        if(*tmx == &meta<Rendered³ID>)
            return RenderedID(*ix);
        const Frame*    frame   = Frame::current();
        if(!frame)
            return errors::no_frame_available();
        TypedID typeId  = frame->typed({*ix});
        if(typedid(Type::Rendered))
            return RenderedID{*ix};
        return errors::not_valid_rendered_id();
    }
    
    Expect<StdThread>      stdThread(lua_State* l, int n)
    {
    }
    
    Expect<TachyonID>      tachyonID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
    }
    
    Expect<ThreadID>       threadID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
    }
    
    Expect<ViewerID>       viewerID(lua_State* l, int n)
    {
    }
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
    
    Expect<WidgetID>       widgetID(lua_State* l, int n)
    {
    }
}
