////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/keywords.hpp>
#include <yt/api/Tachyon.hpp>
#include <ya/typedef/commands.hpp>
#include <ya/typedef/events.hpp>
#include <yt/typedef/layout.hpp>
#include <ya/typedef/replies.hpp>
#include <ya/typedef/requests.hpp>
#include <yt/typedef/viewer.hpp>
#include <yt/typedef/widget.hpp>
#include <yt/typedef/camera3.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/typedef/vector2.hpp>
#include <yt/typedef/push.hpp>
#include <yt/typedef/rendered.hpp>
#include <yt/typedef/rendered3.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/shape/Size2.hpp>

//   A macro rename

#define YQ_WIDGET_DATA(...)         YQ_TACHYON_DATA(__VA_ARGS__);
#define YQ_WIDGET_INFO(...)         YQ_TACHYON_INFO(__VA_ARGS__)
#define YQ_WIDGET_FIXER(...)        YQ_TACHYON_FIXER(__VA_ARGS__)
#define YQ_WIDGET_SNAP(...)         YQ_TACHYON_SNAP(__VA_ARGS__);
#define YQ_WIDGET_DECLARE(...)      YQ_TACHYON_DECLARE(__VA_ARGS__)
#define YQ_WIDGET_IMPLEMENT(...)    YQ_TACHYON_IMPLEMENT(__VA_ARGS__)

namespace yq::tachyon {
    struct ViContext;
    class CloseCommand;
    class HideCommand;
    class ShowCommand;
    //class StartupCommand;
    class SetViewer;
    class TitleCommand;
    class Frame;
    class UIElement;
    class UIElements;
    class UIWriter;
    class FramebufferResizeEvent;

    class WidgetInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;
        WidgetInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
        friend class UIWriter;
        friend class Widget;
        UIElements*                m_ui    = nullptr;
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
        YQ_TACHYON_INFO(WidgetInfo)
        YQ_TACHYON_SNAP(WidgetSnap)
        YQ_TACHYON_DATA(WidgetData)
        YQ_TACHYON_DECLARE(Widget, Tachyon)
    public:
    
        /*
            STARTUP...
            
            This will be automatic, first tick.  Visibility will 
            not be gained until startup occurs.
        */

        static void init_info();
    
        //! Default constructor
        Widget();
        
        //! Default destructor
        virtual ~Widget();

        void        cmd_hide();
        void        cmd_show();

        //! Dimension count to the widget (ie...add dimensions to allow for layout resizing)
        virtual uint8_t dimensions(count_k) const { return 0; }

        double      height() const;

        /*! \brief Renders ImGui content
        
            This routine is called by the viewer for our widget 
            to properly render ImGui content.  The context
            is all the extra information that may or may
            not be needed.  Default implementation iterates 
            through children, calling their methods recursively. 
        */
        virtual void    imgui(ViContext&);
        
        //! Calls the imgui on all children
        void    imgui(children_k, ViContext&);

        //! Calls the render on all UIElement elements
        void    imgui(ui_k, ViContext&);


        WidgetID   id() const { return WidgetID(UniqueID::id()); }

        bool    is_imgui() const;
        
        using Tachyon::parent;
        
        //! Our parent widget
        Widget*         parent(ptr_k);

        //! Our parent widget
        const Widget*   parent(ptr_k) const;
        
        WidgetID        root() const;

        //! Our root widget
        Widget*         root(ptr_k);

        //! Our root widget
        const Widget*   root(ptr_k) const;
        
        void            set_layout(LayoutPtr);
        
        ViewerID        viewer() const;
        
        //! Our viewer
        Viewer*         viewer(ptr_k);

        //! Our viewer
        const Viewer*   viewer(ptr_k) const ;
        
        //! TRUE if we're attached (either as a child-widget or to a viewer)
        bool    attached() const;

        bool            visible() const;

        /*! \brief Renders Vulkan content
        
            This routine is called by the viewer for our widget to
            properly render Vulkan content.  The context 
            is all the extra information that may or may
            not be needed.  Default implementation iterates
            through children, calling their methods recursively.
        */
        virtual void    vulkan(ViContext&);

        virtual Widget* widget_at(const Vector2D&) const;
        
        double          width() const;

    protected:
        friend class Viewer;
        friend class Layout;
        friend class UIElement;
        friend class UIWriter;
        
        enum class F : uint8_t {
            //ClosePending,
            Visible,
            AutoRender,
            HasSize,
            HasPosition
        };
        using FFlags = Flags<F>;

        //! Our viewer
        TypedID                 m_viewer;
        
        //! A string ID for ImGui
        const std::string       m_windowID;
        
        FFlags                  m_flags = { F::Visible, F::AutoRender };

        virtual PostAdvice      advise(const Post&) const override;
        
        //bool                    started() const;

        //! Override to accept/reject
        virtual void            close(request_k) { close(ACCEPT); }
        void                    close(accept_k);
        void                    close(reject_k);
        
        

        //! A string ID for ImGui
        virtual const char*     imgui_id() const;
        
        void                    on_close_command(const CloseCommand&);
        void                    on_close_request(const CloseRequestCPtr&);
        
        void                    on_fb_resize_event(const FramebufferResizeEvent&);
        
        void                    on_hide_command(const HideCommand&);
        
        void                    on_set_viewer(const SetViewer&);
        void                    on_show_command(const ShowCommand&);
        void                    on_title_command(const TitleCommand&);

        //! Called before record, this is the opportunity to 
        //! pass descriptor sets to the graphics card.
        virtual void            prerecord(ViContext&);


        virtual Execution       setup(const Context&);
        
        void                    snap(WidgetSnap&) const;

        virtual Execution       tick(const Context&);

        
        
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
        
        struct PreContext {
            ViContext&      vi;
            const Frame&    frame;
            Tensor44D       view        = IDENTITY;
            Tensor44D       projection  = IDENTITY;
            RGBA4F          gamma       = { 1., 1., 1., 1. };
            double          time        = 0.;
        };
        
        static void camera_matrix(PreContext&, Camera³ID);
        
        static void camera_matrix(Tensor44D& view, Tensor44D& proj, const Frame&, Camera³ID);
        static void push_buffer(PushBuffer&, const PreContext&, const RenderedSnap&);
        
        //! Used to push an item to the rendered vector *THIS PRERECORD* (it'll be cleared by the vulkan() call)
        void        prerecord(const PreContext&, RenderedID);
        
    private:
    
        using UIMMap = std::multimap<uint64_t,UIElement*>;
    
        struct R;
        CloseRequestCPtr                m_closeRequest;
        LayoutPtr                       m_layout;
        std::vector<R>                  m_rendereds;
        UIElements*                     m_ui            = nullptr;
        UIMMap                          m_uimap;    //< for cross-linking
        Tristate                        m_wireframe     = Tristate::INHERIT;
        Vector2D                        m_position      = { 0., 0. };
        Size2D                          m_size          = { -1, -1 };   // unknown sizing
        
        void    _kill();


        static void push_buffer_mvp(PushBuffer&, const PreContext&, const Rendered³Snap&);
        static void push_buffer_full(PushBuffer&, const PreContext&, const Rendered³Snap&);
        static void push_buffer_view(PushBuffer&, const PreContext&, const RenderedSnap&);
        static void push_buffer_viewproj(PushBuffer&, const PreContext&, const RenderedSnap&);
        static void push_buffer_view64proj(PushBuffer&, const PreContext&, const RenderedSnap&);
    };
}
YQ_TYPE_DECLARE(yq::tachyon::WidgetID)
