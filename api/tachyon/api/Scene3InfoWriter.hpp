////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Scene3.hpp>
#include <tachyon/api/Scene3Data.hpp>
#include <tachyon/api/SceneMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Scene³Info::Writer : public SceneMeta::Writer<C> {
    public:
        Writer(Scene³Info* sceneInfo) : SceneMeta::Writer<C>(sceneInfo)
        {
        }
        
        Writer(Scene³Info& sceneInfo) : Writer(&sceneInfo)
        {
        }
    };

}
