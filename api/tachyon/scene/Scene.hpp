////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <basic/Object.hpp>
#include <basic/Ref.hpp>
#include <tachyon/preamble.hpp>
#include <tachyon/scene/Rendered.hpp>

namespace yq {
    namespace tachyon {
        /*! \brief Frame of things to be rendered
        
            This will include lighting (eventually) & rendred objects.
        
        */

        class Scene : public Object, public RefCount {
            YQ_OBJECT_DECLARE(Scene, Object)
        public:
        
            Scene();
            ~Scene();
            
            
            std::vector<RenderedPtr>    things;
            float                       utime = 0.; // for the push constant
        };
    }
}
