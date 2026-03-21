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
#include <yq/tachyon/typedef/kinetic.hpp>
#include <yq/tachyon/typedef/kinetic3.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tachyon/typedef/model.hpp>
#include <yq/tachyon/typedef/physics.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tachyon/typedef/spatial.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {

    struct TypedID;

    const CameraData*       lastdata(CameraID);
    const Camera³Data*      lastdata(Camera³ID);
    const ControllerData*   lastdata(ControllerID);
    const KineticData*      lastdata(KineticID);
    const Kinetic³Data*     lastdata(Kinetic³ID);
    const LightData*        lastdata(LightID);
    const Light³Data*       lastdata(Light³ID);
    const ModelData*        lastdata(ModelID);
    const PhysicsData*      lastdata(PhysicsID);
    const RenderedData*     lastdata(RenderedID);
    const Rendered³Data*    lastdata(Rendered³ID);
    const SceneData*        lastdata(SceneID);
    const Scene³Data*       lastdata(Scene³ID);
    const SpatialData*      lastdata(SpatialID);
    const Spatial³Data*     lastdata(Spatial³ID);

    Camera*                 pointer(CameraID);
    Camera³*                pointer(Camera³ID);
    Controller*             pointer(ControllerID);
    Kinetic*                pointer(KineticID);
    Kinetic³*               pointer(Kinetic³ID);
    Light*                  pointer(LightID);
    Light³*                 pointer(Light³ID);
    Model*                  pointer(ModelID);
    Physics*                pointer(PhysicsID);
    Rendered*               pointer(RenderedID);
    Rendered³*              pointer(Rendered³ID);
    Scene*                  pointer(SceneID);
    Scene³*                 pointer(Scene³ID);
    Spatial*                pointer(SpatialID);
    Spatial³*               pointer(Spatial³ID);

    const CameraSnap*       snapshot(CameraID);
    const Camera³Snap*      snapshot(Camera³ID);
    const ControllerSnap*   snapshot(ControllerID);
    const KineticSnap*      snapshot(KineticID);
    const Kinetic³Snap*     snapshot(Kinetic³ID);
    const LightSnap*        snapshot(LightID);
    const Light³Snap*       snapshot(Light³ID);
    const ModelSnap*        snapshot(ModelID);
    const PhysicsSnap*      snapshot(PhysicsID);
    const RenderedSnap*     snapshot(RenderedID);
    const Rendered³Snap*    snapshot(Rendered³ID);
    const SceneSnap*        snapshot(SceneID);
    const Scene³Snap*       snapshot(Scene³ID);
    const SpatialSnap*      snapshot(SpatialID);
    const Spatial³Snap*     snapshot(Spatial³ID);

    TypedID                 typed_for(TachyonID);
}
