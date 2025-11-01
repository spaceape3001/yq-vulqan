////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

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

using namespace yq;
using namespace yq::tachyon;

CameraID                editing(camera_k);
ControllerID            editing(controller_k);
LightID                 editing(light_k);
ModelID                 editing(model_k);
RenderedID              editing(rendered_k);
SceneID                 editing(scene_k);

Camera*                 pointer(CameraID);
Camera³*                pointer(Camera³ID);
Controller*             pointer(ControllerID);
Light*                  pointer(LightID);
Light³*                 pointer(Light³ID);
Model*                  pointer(ModelID);
Rendered*               pointer(RenderedID);
Rendered³*              pointer(Rendered³ID);
Scene*                  pointer(SceneID);
Scene³*                 pointer(Scene³ID);
Spatial*                pointer(SpatialID);
Spatial³*               pointer(Spatial³ID);

Camera*                 pointer(camera_k);
Camera³*                pointer(camera³_k);
Controller*             pointer(controller_k);
Light*                  pointer(light_k);
Light³*                 pointer(light³_k);
Model*                  pointer(model_k);
Rendered*               pointer(rendered_k);
Rendered³*              pointer(rendered³_k);
Scene*                  pointer(scene_k);
Scene³*                 pointer(scene³_k);


const CameraData*       lastdata(CameraID);
const Camera³Data*      lastdata(Camera³ID);
const ControllerData*   lastdata(ControllerID);
const LightData*        lastdata(LightID);
const Light³Data*       lastdata(Light³ID);
const ModelData*        lastdata(ModelID);
const RenderedData*     lastdata(RenderedID);
const Rendered³Data*    lastdata(Rendered³ID);
const SceneData*        lastdata(SceneID);
const Scene³Data*       lastdata(Scene³ID);
const SpatialData*      lastdata(SpatialID);
const Spatial³Data*     lastdata(Spatial³ID);

const CameraData*       lastdata(camera_k);
const Camera³Data*      lastdata(camera³_k);
const ControllerData*   lastdata(controller_k);
const LightData*        lastdata(light_k);
const Light³Data*       lastdata(light³_k);
const ModelData*        lastdata(model_k);
const RenderedData*     lastdata(rendered_k);
const Rendered³Data*    lastdata(rendered³_k);
const SceneData*        lastdata(scene_k);
const Scene³Data*       lastdata(scene³_k);

const CameraSnap*       snapshot(CameraID);
const Camera³Snap*      snapshot(Camera³ID);
const ControllerSnap*   snapshot(ControllerID);
const LightSnap*        snapshot(LightID);
const Light³Snap*       snapshot(Light³ID);
const ModelSnap*        snapshot(ModelID);
const RenderedSnap*     snapshot(RenderedID);
const Rendered³Snap*    snapshot(Rendered³ID);
const SceneSnap*        snapshot(SceneID);
const Scene³Snap*       snapshot(Scene³ID);
const SpatialSnap*      snapshot(SpatialID);
const Spatial³Snap*     snapshot(Spatial³ID);

const CameraSnap*       snapshot(camera_k);
const Camera³Snap*      snapshot(camera³_k);
const ControllerSnap*   snapshot(controller_k);
const LightSnap*        snapshot(light_k);
const Light³Snap*       snapshot(light³_k);
const ModelSnap*        snapshot(model_k);
const RenderedSnap*     snapshot(rendered_k);
const Rendered³Snap*    snapshot(rendered³_k);
const SceneSnap*        snapshot(scene_k);
const Scene³Snap*       snapshot(scene³_k);

TypedID                 typed_for(TachyonID);

