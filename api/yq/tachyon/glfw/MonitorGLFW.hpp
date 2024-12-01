////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Monitor.hpp>
#include <yq/tachyon/interfaces/IPosition2I.hpp>

struct GLFWmonitor;
struct GLFWvidmode;

namespace yq::tachyon {
    class MonitorGLFW : public Monitor, private IPosition2I {
        YQ_TACHYON_DECLARE(MonitorGLFW, Monitor);
    public:
        MonitorGLFW(GLFWmonitor*, const Param&p = {});
        ~MonitorGLFW();
        static void init_info();
        
        virtual Execution tick(Context&) override;
        
        void        snap(MonitorSnap&) const;
        
        
        
    private:
        GLFWmonitor*        m_monitor;
        //MonitorState    m_state;
        
        Vector2I            m_position;
        
        
        Vector2I                        _position() const;
        Rectangle2I                     _working() const;
        Size2MM                         _dimensions() const;
        Vector2F                        _scale() const;
        std::string                     _name() const;
        std::span<const GLFWvidmode*>   _modes() const;
    };
}
