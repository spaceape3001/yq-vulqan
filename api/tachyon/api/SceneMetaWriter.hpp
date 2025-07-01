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
    class SceneMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(SceneMeta* lightInfo) : TachyonMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(SceneMeta& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
