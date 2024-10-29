////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBX.hpp>
#include <yq/core/UniqueID.hpp>

namespace yq::tachyon {
    class Viewer;
    struct ViContext;
    class Event;
    
    class KeyCharacter;
    class KeyPress;
    class KeyRelease;
    
    class MouseEnter;
    class MouseLeft;
    class MouseMove;
    class MousePress;
    class MouseRelease;
    class MouseScroll;
    
    class WidgetMove;
    class WidgetResize;
    class WidgetRescale;
    
    class CloseRequest;
    
    //class WidgetMoveEvent;
    //class WidgetResizeEvent;
    //class WidgetRescaleEvent;
    //class WidgetCloseRequest;

    class WidgetInfo : public post::PBXInfo {
    public:
        template <typename C> class Writer;
        WidgetInfo(std::string_view, const post::PBXInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    /*! \brief Root something that's drawwable & interactable
    
        It follows ImGui's rules, this is something that is 
        "drawable" and needs some amount of state information.
    */
    class Widget : public post::PBX, public UniqueID {    
        YQ_OBJECT_INFO(WidgetInfo)
        YQ_OBJECT_DECLARE(Widget, post::PBX)
    public:
    
        //! Default constructor
        Widget();
        
        //! Default destructor
        virtual ~Widget();

        /*! \brief Renders ImGui content
        
            This routine is called by the viewer for our widget 
            to properly render ImGui content.  The context
            is all the extra information that may or may
            not be needed.  Default implementation iterates 
            through children, calling their methods recursively.
        */
        virtual void    imgui_(ViContext&);
        
        /*! \brief Renders Vulkan content
        
            This routine is called by the viewer for our widget to
            properly render Vulkan content.  The context 
            is all the extra information that may or may
            not be needed.  Default implementation iterates
            through children, calling their methods recursively.
        */
        virtual void    vulkan_(ViContext&);
        
        /*! \brief Sets the parent of this widget
        
            This will fail if a parent-loop is detected.  
            (ie, trying to set to self)
        
            \param[in] p    Proposed parent (can be null)
            \return TRUE if the change was taken
        */
        bool    set_parent(Widget* p);
        
        /*! \brief Adds the child to this widget
        
            This will fail for reasons of set_parent, OR the
            child is null.
            
            \param[in] ch   Child to add
            \return TRUE if the change was taken
        */
        bool    add_child(Widget* ch);
        
        /*! \brief Tests for parentage
        
            Checks to see if the argument is this widget's parent
            or grandparent or great grandparent to whatever degree.
        
            \param p    Supposed parent in question
        */
        bool    has_parentage(const Widget* p) const;
        
        bool    is_imgui() const;
        
        //! Our parent widget
        Widget*         parent()  { return m_parent; }

        //! Our parent widget
        const Widget*   parent() const { return m_parent; }

        //! Our root widget
        Widget*         root();

        //! Our root widget
        const Widget*   root() const;
        
        //! Our viewer
        Viewer*         viewer();

        //! Our viewer
        const Viewer*   viewer() const ;
        
        virtual Widget* widget_at(const Vector2D&) const;

    protected:
        friend class Viewer;
        
        //! Our viewer
        Viewer*                 m_viewer    = nullptr;
        
        //! Our parent widget
        Widget*                 m_parent    = nullptr;
        
        //! Our child widgets
        std::vector<Widget*>    m_children;
        
        //! A string ID for ImGui
        std::string             m_windowID;
        
        //! Called before record, this is the opportunity to 
        //! pass descriptor sets to the graphics card.
        virtual void            prerecord(ViContext&);

        //! Called when a child of this widget is added
        //virtual void            on_child_added(Widget*){}
        
        //! Called when a child of this widget is removed
        //virtual void            on_child_removed(Widget*){}
        
        #if 0
        virtual void            on(const WidgetChildAdd&) {};
        virtual void            on(const WidgetChildRemove&) {};
        
        //! Called when the user submits a character (could be meta-induced)
        virtual void            on(const KeyCharacter&){}
        virtual void            on(const KeyPress&){}
        virtual void            on(const KeyRelease&){}
        virtual void            on(const KeyRepeat&){}
        
        virtual void            on(const WidgetMove&){}
        virtual void            on(const WidgetResize&){}
        virtual void            on(const WidgetRescale&){}
        virtual void            on(const CloseRequest&){}

        virtual void            on(const MouseMove&) {}
        virtual void            on(const MouseEnter&) {}
        virtual void            on(const MouseLeft&) {}
        virtual void            on(const MousePress&) {}
        virtual void            on(const MouseRelease&) {}
        virtual void            on(const MouseScroll&) {}
        #endif

        #if 0
        virtual void            on_window_iconified() {}
        
        virtual void            on_window_restored() {}
        
        virtual void            on_window_maximized() {}
        #endif
    };

}
