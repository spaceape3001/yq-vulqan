////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "engine.hpp"

#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/app/Engine.hpp>
#include <yq/tachyon/app/EngineData.hpp>

namespace yq::tachyon {
    Meter        engine_scale()
    {
        const Frame* frame = Frame::current();
        if(!frame)
            return Engine::kDefault_EngineScale;
        EngineID    engID   = frame->first(ENGINE);
        if(!engID)
            return Engine::kDefault_EngineScale;
        const EngineSnap* es    = frame->snap(engID);
        if(!es)
            return Engine::kDefault_EngineScale;
        return es->engine_scale;
    }
}
