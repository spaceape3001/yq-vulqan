////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"
#include "data.hpp"
#include <tachyon/api/Camera.hpp>
#include <tachyon/api/Camera3.hpp>
#include <tachyon/api/Controller.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Light.hpp>
#include <tachyon/api/Light3.hpp>
#include <tachyon/api/Model.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/Rendered3.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/Scene3.hpp>
#include <tachyon/api/Spatial.hpp>
#include <tachyon/api/Spatial3.hpp>
#include <tachyon/ui/UIElement.hpp>

using namespace yq;
using namespace yq::tachyon;

    ////////////// EDITING /////////////

CameraID                editing(camera_k)
{
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(UIElement::widget());
    if(!editor)
        return {};
    return editor -> selected(CAMERA);
}

ControllerID            editing(controller_k)
{
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(UIElement::widget());
    if(!editor)
        return {};
    return editor -> selected(CONTROLLER);
}

LightID                 editing(light_k)
{
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(UIElement::widget());
    if(!editor)
        return {};
    return editor -> selected(LIGHT);
}

ModelID                 editing(model_k)
{
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(UIElement::widget());
    if(!editor)
        return {};
    return editor -> selected(MODEL);
}

RenderedID              editing(rendered_k)
{
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(UIElement::widget());
    if(!editor)
        return {};
    return editor -> selected(RENDERED);
}

SceneID                 editing(scene_k)
{
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(UIElement::widget());
    if(!editor)
        return {};
    return editor -> selected(SCENE);
}


    ////////////// LAST DATA /////////////

const CameraData*       lastdata(CameraID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const Camera³Data*      lastdata(Camera³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const ControllerData*   lastdata(ControllerID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const LightData*        lastdata(LightID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const Light³Data*       lastdata(Light³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const ModelData*        lastdata(ModelID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const RenderedData*     lastdata(RenderedID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const Rendered³Data*    lastdata(Rendered³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const SceneData*        lastdata(SceneID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const Scene³Data*       lastdata(Scene³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const SpatialData*      lastdata(SpatialID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const Spatial³Data*     lastdata(Spatial³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> data(id);
}

const CameraData*       lastdata(camera_k)
{
    return lastdata(editing(CAMERA));
}

const Camera³Data*      lastdata(camera³_k)
{
    return lastdata((Camera³ID) editing(CAMERA));
}

const ControllerData*   lastdata(controller_k)
{
    return lastdata(editing(CONTROLLER));
}

const LightData*        lastdata(light_k)
{
    return lastdata(editing(LIGHT));
}

const Light³Data*       lastdata(light³_k)
{
    return lastdata((Light³ID) editing(LIGHT));
}

const ModelData*        lastdata(model_k)
{
    return lastdata(editing(MODEL));
}

const RenderedData*     lastdata(rendered_k)
{
    return lastdata(editing(RENDERED));
}

const Rendered³Data*    lastdata(rendered³_k)
{
    return lastdata((Rendered³ID) editing(RENDERED));
}

const SceneData*        lastdata(scene_k)
{
    return lastdata(editing(SCENE));
}

const Scene³Data*       lastdata(scene³_k)
{
    return lastdata((Scene³ID) editing(SCENE));
}

    ////////////// POINTERS /////////////

Camera*                 pointer(CameraID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Camera³*                pointer(Camera³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Controller*             pointer(ControllerID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Light*                  pointer(LightID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Light³*                 pointer(Light³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Model*                  pointer(ModelID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Rendered*               pointer(RenderedID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Rendered³*              pointer(Rendered³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Scene*                  pointer(SceneID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Scene³*                 pointer(Scene³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Spatial*                pointer(SpatialID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Spatial³*               pointer(Spatial³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> object(id);
}

Camera*                 pointer(camera_k)
{
    return pointer(editing(CAMERA));
}

Camera³*                pointer(camera³_k)
{
    return pointer((Camera³ID) editing(CAMERA));
}

Controller*             pointer(controller_k)
{
    return pointer(editing(CONTROLLER));
}

Light*                  pointer(light_k)
{
    return pointer(editing(LIGHT));
}

Light³*                 pointer(light³_k)
{
    return pointer((Light³ID) editing(LIGHT));
}

Model*                  pointer(model_k)
{
    return pointer(editing(MODEL));
}

Rendered*               pointer(rendered_k)
{
    return pointer(editing(RENDERED));
}

Rendered³*              pointer(rendered³_k)
{
    return pointer((Rendered³ID) editing(RENDERED));
}

Scene*                  pointer(scene_k)
{
    return pointer(editing(SCENE));
}

Scene³*                 pointer(scene³_k)
{
    return pointer((Scene³ID) editing(SCENE));
}

    ////////////// SNAPSHOTS /////////////


const CameraSnap*       snapshot(CameraID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const Camera³Snap*      snapshot(Camera³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const ControllerSnap*   snapshot(ControllerID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const LightSnap*        snapshot(LightID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const Light³Snap*       snapshot(Light³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const ModelSnap*        snapshot(ModelID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const RenderedSnap*     snapshot(RenderedID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const Rendered³Snap*    snapshot(Rendered³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const SceneSnap*        snapshot(SceneID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const Scene³Snap*       snapshot(Scene³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const SpatialSnap*      snapshot(SpatialID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}

const Spatial³Snap*     snapshot(Spatial³ID id)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return nullptr;
    return frame -> snap(id);
}


const CameraSnap*       snapshot(camera_k)
{
    return snapshot(editing(CAMERA));
}

const Camera³Snap*      snapshot(camera³_k)
{
    return snapshot((Camera³ID) editing(CAMERA));
}

const ControllerSnap*   snapshot(controller_k)
{
    return snapshot(editing(CONTROLLER));
}

const LightSnap*        snapshot(light_k)
{
    return snapshot(editing(LIGHT));
}

const Light³Snap*       snapshot(light³_k)
{
    return snapshot((Light³ID) editing(LIGHT));
}

const ModelSnap*        snapshot(model_k)
{
    return snapshot(editing(MODEL));
}

const RenderedSnap*     snapshot(rendered_k)
{
    return snapshot(editing(RENDERED));
}

const Rendered³Snap*    snapshot(rendered³_k)
{
    return snapshot((Rendered³ID) editing(RENDERED));
}

const SceneSnap*        snapshot(scene_k)
{
    return snapshot(editing(SCENE));
}

const Scene³Snap*       snapshot(scene³_k)
{
    return snapshot((Scene³ID) editing(SCENE));
}

///

TypedID                 typed_for(TachyonID tac)
{
    const Frame*    frame   = Frame::current();
    if(!frame)  
        return {};
    return frame->typed(tac);
}
