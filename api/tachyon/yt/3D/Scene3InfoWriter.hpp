////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Scene3.hpp>
#include <yt/3D/Scene3Data.hpp>
#include <yt/scene/SceneInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Scene³Info::Writer : public SceneInfo::Writer<C> {
    public:
        Writer(Scene³Info* sceneInfo) : SceneInfo::Writer<C>(sceneInfo)
        {
        }
        
        Writer(Scene³Info& sceneInfo) : Writer(&sceneInfo)
        {
        }
    };

}
