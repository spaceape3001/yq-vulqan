////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <variant>
#include <yt/enum/UIFlags.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    struct ViContext;
    class Widget;
    class WidgetInfo;
    class Viewer;

    /*! \brief (ImGui) UI Element
    
        This is the imgui infrastructure.
        
        While the widget will still support ImGui, that's really a heavyweight option.  
        These are lighter weight alternatives, designed to encompass a single feature 
        point of ImGui (ie, menu item, button, etc), and are compositable via the 
        UIElements sub-class.
    */
    class UIElement {
    public:
        UIElement(UIFlags flags={});
        UIElement(const UIElement&);
        virtual ~UIElement();
        
        /*! \brief Clones the element
        
            For all elements that are specified during the widget info *MUST* implement 
            this.
        */
        UIElement*     copy() const;

        /*! \brief "Draws" the element 
        
            \note MOST UIElements should override render() instead
            
            This "draw()" is here to allow for metrics to be taken of the render()
            process (or, measuring before/after positions).
        */
        virtual void    draw();
        
        ////! Spawn off any root ui elements (ie, dialogs, docks, windows, etc)
        //virtual std::vector<UIElement*> spawn();
        
        //! Our element's "title" (may be null)
        virtual const char*   title() const { return nullptr; }

        UIFlags     flags() const noexcept { return m_flags; }
        void        flag(set_k, UIFlag);
        void        flag(set_k, UIFlags);
        void        flag(clear_k, UIFlag);
        void        flag(clear_k, UIFlags);
        
        UIElement*  parent();
        const UIElement*  parent() const;
        
        UIElement*  root();
        const UIElement* root() const;

    protected:
        friend class Widget;
        friend class UIWriter;
        friend class UIElements;

        /*! \brief Clones the element
        
            For all elements that are specified during the widget info *MUST* implement 
            this.
        */
        virtual UIElement*     clone() const = 0;
        

        /*! \brief RENDER/DRAW the element as a whole
        
            This is the first hook for rendering/drawing the ImGui content; this is what 
            is normally overriden.
        */
        virtual void    render() = 0;

        //! Called if there's an if-show/perform test inside render, or similar encapsulation
        virtual void    content() {}
        
        //! Called when we've been triggered by a user event (ie, mouse clicked)
        //! \note Your state (if it's not-singular) should be at least protected-accessible
        virtual void    triggered() {}

        virtual void    update(flags_k){}
        
        //! Valid during clone & draw/render/content/triggered (check for NULL)
        static Widget*  widget();
        
        UIFlags         m_flags;
        
        UIElement*      m_parent = nullptr;
        
    private:
        static thread_local Widget*     s_widget;
        static thread_local ViContext*  s_context;
    };
    
    template <typename T>
    concept SomeUIElement  = std::derived_from<T,UIElement>;
}
