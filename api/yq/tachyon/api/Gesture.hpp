////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/gesture.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <variant>

namespace yq::tachyon {
    class GestureMeta : public ObjectMeta {
    public:
        template <class> class Writer;
        GestureMeta(std::string_view, ObjectMeta&, const std::source_location& sl = std::source_location::current());
    };
    
    class Widget;
    struct ViContext;
    struct Context;
    
    /*! A gesture is a *specific* thing the user is doing
    
        Click & drag should be done, and when released, 
        becomes a mouse drag event, possibly issuing events 
        along the way.  Another example is file input... needs
        a dialog box, so submit the gesture to Widget to 
        handle (might be preemptive)
        
        \note ImGui gestures are called in the widget's UI ImGui handler.
        
        \note Also, these are meant to be short lived... do the task, signal 
        finality
    */
    class Gesture : public Object, public RefCount { 
        YQ_OBJECT_META(GestureMeta)
        YQ_OBJECT_DECLARE(Gesture, Object)
    public:
    
        //! TRUE if we're an imgui gesture (ie, dialog popup)
        virtual bool                is_imgui() const { return false; }

        //! TRUE if we're an imgui modal style gesture (ie, dialog popup)
        virtual bool                is_modal() const { return false; }
        
        //! Imgui hook *BEFORE* any other imgui is called
        virtual void    imgui(pre_k){}
        
        //! Normal imgui *AFTER* any other imgui is called
        virtual void    imgui(){}
        
        //! Called with the widget's tick (ImGui will be invalid)
        virtual void   tick(){}
        
        //! Other inputs...
        bool        done() const { return m_done; }

        static void init_meta();

        // to let unique pointer do its thing... grr
        virtual ~Gesture();
        
    protected:
        Gesture();
        Gesture(const Gesture&);
        
        // Set to true when done
        bool    m_done  = false;
        
        //  gotta consider this one...
        //UIElement*  m_before = nullptr;
        //UIElement*  m_after = nullptr;
        
        static void mail(const PostCPtr&);
        static void send(const PostCPtr&);
        static void gesture(GesturePtr&&);
        
        static const Context*   context() { return s_context; }
        static ViContext*       vi_context() { return s_viContext; }
        static Widget*          widget() { return s_widget; }

    private:
        friend class Widget;
        static thread_local Widget*         s_widget;
        static thread_local ViContext*      s_viContext;
        static thread_local const Context*  s_context;
    };
}
