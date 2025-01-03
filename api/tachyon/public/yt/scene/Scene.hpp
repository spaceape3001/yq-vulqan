////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/scene/Rendered.hpp>
#include <yt/typedef/scene.hpp>

namespace yq::tachyon {
    /*! \brief Frame of things to be rendered
    
        This will include lighting (eventually) & rendered objects.
    */
    struct Scene0 {
        std::vector<RenderedPtr>    things;
        std::optional<RGB3F>        background;
        // eventually things like lights, background/layers/materials/etc will go here
        double                      utime   = 0.; // for the push constant
    };
    
    class SceneInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;
        SceneInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    protected:
        ~SceneInfo();
    };
    
    class Scene : public Tachyon {
        YQ_TACHYON_INFO(SceneInfo)
        YQ_TACHYON_DATA(SceneData)
        YQ_TACHYON_SNAP(SceneSnap)
        YQ_TACHYON_DECLARE(Scene, Tachyon)
    public:
    
        Scene(const Param&p={});
        virtual ~Scene();
        
        static void init_info();

    };
}