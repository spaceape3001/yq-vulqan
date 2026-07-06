////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/typedef/domain.hpp>

namespace yq::tachyon {
    class SetDomainCommand;

    class SimpleScene : public Scene {
        YQ_TACHYON_DECLARE(SimpleScene, Scene)
    public:
    
        using Param = Scene::Param;
    
        SimpleScene();
        SimpleScene(const Param&);
        ~SimpleScene();
        static void init_meta();
        
    protected:
        void    snap(SceneSnap&) const;
        
        DomainID    m_domain;
        
        void on_set_domain_command(const SetDomainCommand&);
    };
}
