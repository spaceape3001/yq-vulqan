////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/typedef/scene.hpp>

namespace yq::tachyon {
    class SetBgColorCommand;
    
    class SceneMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;
        SceneMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());

        //! Gets all scene informations
        static const std::vector<const SceneMeta*>&    all();

    protected:
        ~SceneMeta();
        struct Repo;
        static Repo& repo();
    };
    
    /*! \brief Frame of things to be rendered
    
        This will include lighting (eventually) & rendered objects.
    */
    class Scene : public Tachyon {
        YQ_TACHYON_INFO(SceneMeta)
        YQ_TACHYON_DATA(SceneData)
        YQ_TACHYON_SNAP(SceneSnap)
        YQ_TACHYON_DECLARE(Scene, Tachyon)
    public:
    
        Scene(const Param&p={});
        virtual ~Scene();
        
        static void init_meta();
        
        SceneID id() const { return SceneID{ UniqueID::id()}; }

        const RGBA4F&   bgcolor() const { return m_bgcolor; }
        virtual void    set_bgcolor(const RGBA4F&); // override to check/reject color sets

    protected:
        
        void    snap(SceneSnap&) const;
        void    finalize(SceneData&) const;

        RGBA4F  m_bgcolor = { 0., 0., 0., -1. };
        
        void    on_set_bg_color(const SetBgColorCommand&);
    };
}
YQ_TYPE_DECLARE(yq::tachyon::SceneID)
