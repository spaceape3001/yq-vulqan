////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DragGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/os/WindowData.hpp>
#include <yq/tachyon/os/WindowState.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DragGesture)

namespace yq::tachyon {
    void DragGesture::init_meta()
    {
        auto w = writer<DragGesture>();
        w.description("Drag Gesture");
    }

    DragGesture::State    DragGesture::state()
    {
        State   ret{};
        
        if(const WindowSnap*   sn  = snap(WINDOW)){
            ret.position        = sn -> mouse.position;
            ret.buttons         = sn -> mouse.buttons;
            ret.modifiers       = sn -> keyboard.modifiers;
            ret.keys            = sn -> keyboard.keys;
        }
        
        return ret;
    }

    DragGesture::DragGesture() : DragGesture(state())
    {
    }

    DragGesture::DragGesture(const State&s) : m_start(s)
    {
    }
    
    DragGesture::~DragGesture()
    {
    }
    
    bool    DragGesture::canceled() const
    {
        return m_current.buttons && (m_current.buttons != m_start.buttons);
    }
    
    bool    DragGesture::accepted() const
    {
        return m_start.buttons && (m_current.buttons == MouseButtons());
    }

    void    DragGesture::imgui(pre_k) 
    {
        m_current   = state();
        drag(PRE);
    }

    void    DragGesture::imgui() 
    {
        if(canceled()){
            cancel();
            m_done  = true;
        } else if(accepted()){
            drop();
            m_done  = true;
        } else {
            drag(IMGUI);
        }
    }
}
