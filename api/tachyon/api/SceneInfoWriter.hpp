////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class SceneInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(SceneInfo* lightInfo) : TachyonMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(SceneInfo& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
