////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>
#include <tachyon/camera/Camera.hpp>
#include <tachyon/scene/Scene.hpp>

namespace yq {
    namespace tachyon {
        
        class Scene3D : public Widget {
            YQ_OBJECT_DECLARE(Scene3D, Widget)
        public:
        
            Scene3D();
            virtual ~Scene3D();
        
            virtual void    vulkan_(ViContext&) override;
            
            void    set_camera(Ref<Camera>);
            void    set_scene(Ref<Scene>);
            void    set_wireframe(Tristate);
            
            Ref<Camera> camera() const { return m_camera; }
            
            Tristate wireframe() const { return m_wireframe; }

        private:
        
            Ref<Camera>     m_camera;
            Ref<Scene>      m_scene;
            Tristate        m_wireframe  = Tristate::NO;
            Visualizer*     m_viz       = nullptr;
            
            struct RContext;
            struct Thing;
            
            
            using DKey      = std::pair<uint64_t, uint64_t>;
            using ThingMap  = std::map<DKey,Thing*>;
            
            ThingMap    m_things;
            void        clear_map();
            
            Thing&      thing(const Pipeline&, Rendered*);
        };
    }
}

