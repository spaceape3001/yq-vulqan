////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Monitor.hpp>
#include <ya/interfaces/IPosition2.hpp>
#include <ya/interfaces/IScale2.hpp>
#include <ya/interfaces/ISize2.hpp>
#include <yq/color/RGB.hpp>
#include <yq/shape/Size2.hpp>

struct GLFWmonitor;
struct GLFWvidmode;

namespace yq::tachyon {
    class MonitorGLFW : public Monitor {
        YQ_TACHYON_DECLARE(MonitorGLFW, Monitor);
    public:
        MonitorGLFW(GLFWmonitor*, const Param&p = {});
        ~MonitorGLFW();
        static void init_info();
        
        
        virtual Size2MM     dimensions() const override;
        GLFWmonitor*        glfw() const { return m_monitor; }
        Vector2D            position() const override;
        Vector2F            scale() const override;
        Size2D              size() const override;
        void                snap(MonitorSnap&) const;
        virtual Execution   tick(const Context&) override;
        
        static MonitorID       monitor(GLFWmonitor*);
        static MonitorGLFW*    monitor(ptr_k, GLFWmonitor*);

        void    disconnecting();
        
    private:
    
        static MonitorGLFW* _monitor(GLFWmonitor*);

        using Tachyon::send;
        using Tachyon::mark;
    
        GLFWmonitor* const  m_monitor;
        bool                m_dead      = false;
        //MonitorState    m_state;
        
        Vector2I            m_position  = ZERO;
        Vector2F            m_scale     = ONE;
        const GLFWvidmode*  m_mode      = nullptr;
        Size2MM             m_dimensions;
        Size2D              m_size      = ONE;
        RGB3I               m_depth{};
        
        Vector2I                        _position() const;
        Rectangle2I                     _working() const;
        Size2MM                         _dimensions() const;
        Vector2F                        _scale() const;
        std::string                     _name() const;
        std::span<const GLFWvidmode*>   _modes() const;
    };
}
