////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/3D.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/typedef/scene3.hpp>
#include <tachyon/typedef/spatial3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class Scene³Info : public SceneMeta {
    public:
    
        template <typename> class Writer;
        
        Scene³Info(std::string_view, SceneMeta&, const std::source_location& sl = std::source_location::current());
    protected:
        ~Scene³Info();
    };
    
    class Scene³ : public Scene, public ③ {
        YQ_TACHYON_INFO(Scene³Info)
        YQ_TACHYON_SNAP(Scene³Snap)
        YQ_TACHYON_DATA(Scene³Data)
        YQ_TACHYON_DECLARE(Scene³, Scene)
    public:
    
        struct Param : public Scene::Param {
            // setting *ANY* of these creates a simple spatial (3D)
        
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
        };
    
        static void init_info();
    
        Scene³ID id() const { return Scene³ID(UniqueID::id()); }
    
    protected:
        Scene³(const Param&);
        ~Scene³();
        
        void finalize(Scene³Data&) const;
        void snap(Scene³Snap&) const;

        using Tachyon::mail;
        using Tachyon::send;
    };
}
YQ_TYPE_DECLARE(yq::tachyon::Scene³ID)
