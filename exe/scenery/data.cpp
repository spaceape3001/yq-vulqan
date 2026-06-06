////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"
#include "data.hpp"
#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>
#include <yq/tachyon/api/Controller.hpp>
#include <yq/tachyon/api/ControllerData.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Light3Data.hpp>
#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Rendered3Data.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/SceneData.hpp>
#include <yq/tachyon/api/Scene3.hpp>
#include <yq/tachyon/api/Scene3Data.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Spatial3Data.hpp>
#include <yq/tachyon/ui/UIElement.hpp>
#include <format>

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

LightID                 editing(yq::tachyon::light_k)
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

PhysicsID              editing(physics_k)
{
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(UIElement::widget());
    if(!editor)
        return {};
    return editor -> selected(PHYSICS);
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

const LightData*        lastdata(yq::tachyon::light_k)
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

const PhysicsData*      lastdata(physics_k)
{
    return lastdata(editing(PHYSICS));
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

Light*                  pointer(yq::tachyon::light_k)
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

Physics*                pointer(physics_k)
{
    return pointer(editing(PHYSICS));
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

const LightSnap*        snapshot(yq::tachyon::light_k)
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

const PhysicsSnap*      snapshot(physics_k)
{
    return snapshot(editing(PHYSICS));
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

