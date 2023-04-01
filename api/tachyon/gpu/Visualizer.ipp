////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/Visualizer.hpp>
#include <basic/errors.hpp>
#include <tachyon/errors.hpp>
#include <GLFW/glfw3.h>

namespace yq {
    namespace tachyon {
        Visualizer::Visualizer() 
        {
        }
        
        Visualizer::~Visualizer()
        {
        }
    
        std::error_code             Visualizer::init_visualizer(const ViewerCreateInfo& vci, GLFWwindow* w)
        {
            if(m_init)
                return std::error_code();
            m_window    = w;
            return errors::todo();
        }
        
        void                        Visualizer::kill_visualizer()
        {
            if(!m_init)
                return ;
            
        }
    }
}
