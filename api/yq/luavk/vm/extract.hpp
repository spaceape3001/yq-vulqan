////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

struct lua_State;

#include <yq/core/Expect.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tachyon/typedef/spatial.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    struct TypedID;

    Expect<TypedID>        typedID(lua_State*, int);

    Expect<CameraID>       cameraID(lua_State*, int);
    Expect<Camera³ID>      camera³ID(lua_State*, int);
    Expect<LightID>        lightID(lua_State*, int);
    Expect<Light³ID>       light³ID(lua_State*, int);
    Expect<RenderedID>     renderedID(lua_State*, int);
    Expect<Rendered³ID>    rendered³ID(lua_State*, int);
    Expect<SceneID>        sceneID(lua_State*, int);
    Expect<Scene³ID>       scene³ID(lua_State*, int);
    Expect<SpatialID>      spatialID(lua_State*, int);
    Expect<Spatial³ID>     spatial³ID(lua_State*, int);
    Expect<StdThread>      stdThread(lua_State*, int);
    Expect<TachyonID>      tachyonID(lua_State*, int);
    Expect<ThreadID>       threadID(lua_State*, int);
    Expect<ViewerID>       viewerID(lua_State*, int);
    Expect<WidgetID>       widgetID(lua_State*, int);
    
}
