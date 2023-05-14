////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {

    /*! \brief GLFW Application 
    
        \note This is meant to be inherited by the tachyon application!  
            Separated for organization.
    */
    class AppGLFW {
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
        
        AppGLFW(const AppGLFW&) = delete;
        AppGLFW(AppGLFW&&) = delete;
        AppGLFW& operator=(const AppGLFW&) = delete;
        AppGLFW& operator=(AppGLFW&&) = delete;
    };
}

