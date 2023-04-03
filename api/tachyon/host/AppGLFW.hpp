////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/trait/not_copyable.hpp>
#include <basic/trait/not_moveable.hpp>

namespace yq {
    namespace tachyon {
    
        /*! \brief GLFW Application 
        
            \note This is meant to be inherited by the tachyon application!  
                Separated for organization.
        */
        class AppGLFW : not_copyable, not_moveable {
        public:
        
            /*! \brief Initializes the GLFW
            
                This initializes the GLFW, including the installation of a 
                function hook into the logger system
                
                \note should only be called ONCE
            */
            void    init_glfw();
        
        protected:
            
            AppGLFW();
            ~AppGLFW();
            void    kill_glfw();

        private:
            bool    m_init  = false;
        };
    }
}
