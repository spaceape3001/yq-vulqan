////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/VqApp.hpp>
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

        std::error_code             Visualizer::_ctor(const ViewerCreateInfo&vci,GLFWwindow*w)
        {
            m_app       = VqApp::vk_app();
            if(!m_app)
                return errors::no_application();

            m_window    = w;
            if(!w)
                return errors::no_window();
                
            m_vulkan    = m_app -> vulkan();
            if(!m_vulkan)
                return errors::no_vulkan();
            
            
            return errors::todo();
        }
        
        void                        Visualizer::_dtor()
        {
        
        
            m_vulkan        = nullptr;
            m_window        = nullptr;
            m_app           = nullptr;
        }
    
        std::error_code             Visualizer::init_visualizer(const ViewerCreateInfo& vci, GLFWwindow* w)
        {
            if(m_init)
                return std::error_code();
                
            std::error_code ec  = _ctor(vci, w);
            if(ec){
                _dtor();
                return ec;
            }
            
            m_init      = true;
            return std::error_code();

        }
        
        void                        Visualizer::kill_visualizer()
        {
            if(!m_init)
                return ;
            _dtor();
            m_init  = false;
        }
    }
}
