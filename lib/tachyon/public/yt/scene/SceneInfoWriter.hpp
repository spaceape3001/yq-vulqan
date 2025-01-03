////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Scene.hpp>
#include <yt/scene/SceneData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class SceneInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(SceneInfo* lightInfo) : TachyonInfo::Writer<C>(lightInfo)
        {
        }
        
        Writer(SceneInfo& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
