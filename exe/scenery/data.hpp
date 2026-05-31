////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/fastdata.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tachyon/typedef/controller.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tachyon/typedef/model.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tachyon/typedef/spatial.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>

//using namespace yq;
using namespace yq::tachyon;

//using light_k = yq::tachyon::light_k;

CameraID                editing(camera_k);
ControllerID            editing(controller_k);
LightID                 editing(yq::tachyon::light_k);
ModelID                 editing(model_k);
PhysicsID               editing(physics_k);
RenderedID              editing(rendered_k);
SceneID                 editing(scene_k);

Camera*                 pointer(camera_k);
Camera³*                pointer(camera³_k);
Controller*             pointer(controller_k);
Light*                  pointer(yq::tachyon::light_k);
Light³*                 pointer(light³_k);
Model*                  pointer(model_k);
Physics*                pointer(physics_k);
Rendered*               pointer(rendered_k);
Rendered³*              pointer(rendered³_k);
Scene*                  pointer(scene_k);
Scene³*                 pointer(scene³_k);

const CameraData*       lastdata(camera_k);
const Camera³Data*      lastdata(camera³_k);
const ControllerData*   lastdata(controller_k);
const LightData*        lastdata(yq::tachyon::light_k);
const Light³Data*       lastdata(light³_k);
const ModelData*        lastdata(model_k);
const PhysicsData*      lastdata(physics_k);
const RenderedData*     lastdata(rendered_k);
const Rendered³Data*    lastdata(rendered³_k);
const SceneData*        lastdata(scene_k);
const Scene³Data*       lastdata(scene³_k);

const CameraSnap*       snapshot(camera_k);
const Camera³Snap*      snapshot(camera³_k);
const ControllerSnap*   snapshot(controller_k);
const LightSnap*        snapshot(yq::tachyon::light_k);
const Light³Snap*       snapshot(light³_k);
const ModelSnap*        snapshot(model_k);
const PhysicsSnap*      snapshot(physics_k);
const RenderedSnap*     snapshot(rendered_k);
const Rendered³Snap*    snapshot(rendered³_k);
const SceneSnap*        snapshot(scene_k);
const Scene³Snap*       snapshot(scene³_k);



