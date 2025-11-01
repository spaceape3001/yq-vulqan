////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Scene3.hpp>
#include <yq/tachyon/api/Scene3Data.hpp>
#include <yq/tachyon/api/SceneMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Scene³Meta::Writer : public SceneMeta::Writer<C> {
    public:
        Writer(Scene³Meta* sceneInfo) : SceneMeta::Writer<C>(sceneInfo)
        {
        }
        
        Writer(Scene³Meta& sceneInfo) : Writer(&sceneInfo)
        {
        }
    };

}
