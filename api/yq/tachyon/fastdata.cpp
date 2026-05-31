////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "fastdata.hpp"

#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>
#include <yq/tachyon/api/Controller.hpp>
#include <yq/tachyon/api/ControllerData.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Kinetic.hpp>
#include <yq/tachyon/api/KineticData.hpp>
#include <yq/tachyon/api/Kinetic3.hpp>
#include <yq/tachyon/api/Kinetic3Data.hpp>
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

namespace yq::tachyon {
    //////////////////////////////////////////////////////////////////////////////////

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

    const KineticData*      lastdata(KineticID id)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)  
            return nullptr;
        return frame -> data(id);
    }

    const Kinetic³Data*     lastdata(Kinetic³ID id)
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

    const PhysicsData*      lastdata(PhysicsID id)
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
        

    //////////////////////////////////////////////////////////////////////////////////

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

    Kinetic*                pointer(KineticID id)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)  
            return nullptr;
        return frame -> object(id);
    }

    Kinetic³*               pointer(Kinetic³ID id)
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

    Physics*                pointer(PhysicsID id)
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
    
    //////////////////////////////////////////////////////////////////////////////////

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

    const KineticSnap*      snapshot(KineticID id)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)  
            return nullptr;
        return frame -> snap(id);
    }

    const Kinetic³Snap*     snapshot(Kinetic³ID id)
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

    const PhysicsSnap*      snapshot(PhysicsID id)
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
    
    //////////////////////////////////////////////////////////////////////////////////

    TypedID                 typed_for(TachyonID tac)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)  
            return {};
        return frame->typed(tac);
    }

}
