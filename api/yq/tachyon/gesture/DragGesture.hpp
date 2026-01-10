////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Gesture.hpp>
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/os/ModifierKey.hpp>
#include <yq/tachyon/os/MouseButton.hpp>
#include <yq/tachyon/typedef/key_array.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {


    /*! \brief Drag Gesture
        
        This may become drag/drop sensitive
    */
    class DragGesture : public Gesture {
        YQ_OBJECT_DECLARE(DragGesture, Gesture)
    public:
    
        struct State {
            key_array_t     keys;
            Vector2D        position    = ZERO;
            MouseButtons    buttons;
            ModifierKeys    modifiers;
        };
    
        //! Called while in the middle of dragging
        virtual void    drag(imgui_k) {}
        virtual void    drag(pre_k) {}
        
        //! Called when it's cancelled
        virtual void    cancel() {}
        virtual void    drop() {}
        
        //! TRUE if the criteria for cancellation is met
        virtual bool    canceled() const;
        
        //! TRUE if the criteria for acceptance is met
        virtual bool    accepted() const;

        //! Imgui override
        virtual void    imgui() override final;

        //! Imgui hook *BEFORE* any other imgui is called
        virtual void    imgui(pre_k) override final;

        //! Current state
        const State&    current() const { return m_current; }
        
        //! Starting state
        const State&    start() const { return m_start; }
        
        //! Data being "payloaded"
        const Payload&  payload() const { return m_payload; }

        static void init_meta();

    protected:
        DragGesture();
        DragGesture(const State&);
        ~DragGesture();

        //! Gets the current state (requires the widget & frame to be valid with viewer & window)
        static State    state();

        const State     m_start;
        State           m_current;
        Payload         m_payload;
    };
}
