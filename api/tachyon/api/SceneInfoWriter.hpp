////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

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
