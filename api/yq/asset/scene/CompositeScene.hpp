////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Scene.hpp>

namespace yq::tachyon {
    /*! \brief A scene that's a composite of other scenes
    
        This will generally mean that this scene won't be directly renderable 
        by the composite widget either.
    */
    class CompositeScene : public Scene {
        YQ_TACHYON_DECLARE(CompositeScene, Scene)
    public:
    
        CompositeScene();
        ~CompositeScene();
        
        static void init_meta();
    };
}
