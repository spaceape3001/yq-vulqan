////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/typedef/vector2.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/commands.hpp>
#include <yq/tachyon/typedef/events.hpp>
#include <yq/tachyon/typedef/replies.hpp>
#include <yq/tachyon/typedef/requests.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class Viewer;
    struct ViContext;
    class WidgetStartupCommand;

    class WidgetInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;
        WidgetInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    /*! \brief Root something that's drawwable & interactable
    
        It follows ImGui's rules, this is something that is 
        "drawable" and needs some amount of state information.
        
        \note ONE spot in the tree, with one viewer.  
        Need a second view of something?  New widget (though 
        certainly use ref-pointers to data, models, etc to
        reduce overhead!)
    */
    class Widget : public Tachyon {    
        YQ_OBJECT_INFO(WidgetInfo)
        YQ_OBJECT_DECLARE(Widget, Tachyon)
    public:
    
        static void init_info();
    
        //! Default constructor
        Widget(const Param&p={});
        
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
        
        WidgetID   id() const { return WidgetID(UniqueID::id()); }

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
        
        bool    attached() const;


    protected:
        friend class Viewer;
        
        enum class F : uint8_t {
            ClosePending
        };
        
        //! Our viewer
        Viewer*                 m_viewer    = nullptr;
        
        //! Our parent widget
        Widget*                 m_parent    = nullptr;
        
        //! Our child widgets
        std::vector<Widget*>    m_children;
        
        //! A string ID for ImGui
        std::string             m_windowID;
        
        Flags<F>                m_flags = {};
        
        //! Called before record, this is the opportunity to 
        //! pass descriptor sets to the graphics card.
        virtual void            prerecord(ViContext&);

        virtual void            on_close_request() { accept(CLOSE); }
        void                    accept(close_k);
        void                    reject(close_k);

        //virtual void            receive(const post::PostCPtr&);

        //! Called when a child of this widget is added
        //virtual void            on_child_added(Widget*){}
        
        //! Called when a child of this widget is removed
        //virtual void            on_child_removed(Widget*){}
        
        virtual PostAdvice      advise(const Post&) const override;
        
        virtual Execution       tick(Context&) override;
        
        //  override to do your own startup... 
        virtual void            startup();
        
        
        void    on_startup_command(const WidgetStartupCommand&);
        
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
