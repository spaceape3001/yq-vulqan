////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseDropEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseDropEvent, MouseEvent)
    public:
    
        MouseDropEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons, std::vector<std::string>&&);
        static void init_meta();
        
        const std::vector<std::string>& paths() const { return m_paths; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MouseDropEvent(const MouseDropEvent&, const Header&);
        virtual ~MouseDropEvent();
    private:
        std::vector<std::string>  m_paths;
        
        MouseDropEvent(const MouseDropEvent&) = delete;
        MouseDropEvent(MouseDropEvent&&) = delete;
        MouseDropEvent& operator=(const MouseDropEvent&) = delete;
        MouseDropEvent& operator=(MouseDropEvent&&) = delete;
    };
}

