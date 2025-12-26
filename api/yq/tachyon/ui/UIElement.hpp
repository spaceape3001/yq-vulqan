////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <variant>
#include <yq/tachyon/enum/UIFlags.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/typedef/axbox2.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/enum/DlgButton.hpp>
#include <yq/tachyon/typedef/action.hpp>
#include <yq/tachyon/typedef/gesture.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/tachyon/typedef/uielement.hpp>


namespace yq::tachyon {
    struct ViContext;
    class Widget;
    class WidgetMeta;
    class Viewer;
    class UIElement;
    class UIElementWriter;
    struct UIStyle;
    class UIWindow;
    class UIGenerator;
    struct Payload;
    struct Context;
    
    class UIElementMeta : public ObjectMeta {
    public:
        template <typename> class Writer;
        UIElementMeta(std::string_view, ObjectMeta&, const std::source_location& sl = std::source_location::current());
        
        static const std::vector<const UIElementMeta*>& all();
        
    private:
        struct Repo;
        static Repo& repo();
    };


    /*! \brief (ImGui) UI Element
    
        This is the imgui infrastructure.
        
        While the widget will still support ImGui, that's really a heavyweight option.  
        These are lighter weight alternatives, designed to encompass a single feature 
        point of ImGui (ie, menu item, button, etc), and are compositable via the 
        UIElements sub-class.
        
        \note Concession is that we'll need meta-attributes/methods for UI scripting, 
        so the object is being added.
    */
    class UIElement : public Object {
        YQ_OBJECT_META(UIElementMeta)
        YQ_OBJECT_DECLARE(UIElement, Object)
    public:
    
        static void         init_meta();

        using Writer = UIElementWriter;
    
        UIElement(UIFlags flags={});
        UIElement(const UIElement&);
        virtual ~UIElement();
        
        const auto&         actions() const { return m_actions; }
        
        size_t              actions(count_k) const;
        bool                actions(has_k) const;
        
        //! Unique binding if not zero
        uint64_t            binding() const { return m_bId; }
        
        uint64_t            binding(create_k);
        

        /*! \brief Copies the element
        
            \note Do *NOT* override this lightly (it's virtual for the generator's benefit).  
                Most likely, you want to override the clone() method.
        */
        virtual UIElement* copy() const;

        /*! \brief "Draws" the element 
        
            \note MOST UIElements should override render() instead
            
            This "draw()" is here to allow for metrics to be taken of the render()
            process (or, measuring before/after positions).
        */
        virtual void        draw();
        
        ////! Spawn off any root ui elements (ie, dialogs, docks, windows, etc)
        //virtual std::vector<UIElement*> spawn();

        UIFlags             flags() const noexcept { return m_flags; }
        void                flag(set_k, UIFlag);
        void                flags(set_k, UIFlags);
        void                flag(clear_k, UIFlag);
        void                flags(clear_k, UIFlags);
        void                flag(set_k, UIFlag, bool);
        
        void                flag(toggle_k, UIFlag);
        
        bool                flag(UIFlag v) const;
        
        //! TRUE if the invisible flag is set
        bool                invisible() const;

        //! Checks to see if the UI element is or is derived from specified type (or is a generator)
        virtual Tristate    is(const UIElementMeta& baseInfo) const;
        
        template <SomeUIElement U>
        Tristate            is() const
        {
            return is(meta<U>());
        }

        UIElement*          parent();
        const UIElement*    parent() const;
        
        UIElement*          root();
        const UIElement*    root() const;

        
        //! Our element's "title" (may be null)
        virtual const char* title() const { return nullptr; }
 
        //! User assigned ID (may or may not be unique)
        const std::string&    uid() const { return m_uId; }

        //! Viewport in window/viewer coordinates
        virtual AxBox2F     viewport() const;

        //! Viewport for content in screen coordinates
        virtual AxBox2F     viewport(content_k) const;
        
        

        /*! \brief Current widget being processed (NULL if this isn't true)
        
            \note This is TLS data, so it'll be valid (or not) for the duration 
            of you being called, however, do not RETAIN this pointer!
        */

        static Widget*          widget();

        //! UI Element style
        static const UIStyle&   style();
        
        bool                    readonly() const;

        /*! \brief RENDER/DRAW the element as a whole
        
            This is the first hook for rendering/drawing the ImGui content; this is what 
            is normally overriden.
        */
        virtual void            render() {}

        //! Called if there's an if-show/perform test inside render, or similar encapsulation
        virtual void            content() {}

        #if 0
        
        //  Dialog here
        //  And filepath browsing helpers
        //  Trouble, depending on location, we can't *rely* on always probing
        using DlgCallback   = std::function<void()>;
        using DlgButtonCallbackPair   = std::pair<DlgButton,DlgCallback>;
        
        using FPCallback    = std::function<void(const std::filesystem::path&)>;

        //  need button options too....
        static DlgButton        dialog(std::string_view, DlgButtons btns={ DlgButton::Okay }, const std::source_location& sl=std::source_location::current());
        static void             dialog(std::string_view, std::initializer_list<DlgButtonCallbackPair>, const std::source_location& sl=std::source_location::current());
        
        //static DlgButton        openfile(
        #endif

    protected:
        friend class Widget;
        friend class UIGenerator;
        friend class UIElements;
        friend class UIElementsWriter;
        friend class UIElementWriter;
        friend class UIWindow;

        //! Parameter (specified, calculated, vs actual)
        template <typename T>
        struct P {
            //! User specified
            T   spec    = {};
            
            //! Calculated (dynamic)
            T   calc    = {};
            
            //! Next one to be used
            T   next    = {};
            
            //! Actual measured value
            T   actual  = {};
            
            //! Minimum permissible value
            T   minimum = {};
            
            //! Maximum permissible value
            T   maximum = {};
            
            P() = default;
            P(T v) : spec(v), calc(v), next(v), actual(v) {}
            P(T s, T c, T n, T a) : spec(s), calc(c), next(n), actual(a) {}
        };

        enum class S : uint8_t {
            LoadFailed,
            TextureIdFailed,
            MenuBar,
            ToolBar,
            NotFirst,
            HasAccessor,
            NotStale
        };

        /*! \brief Clones the element
        
            For all elements that are specified during the widget info *MUST* implement 
            this.  (Ditto for popups)
        */
        virtual UIElement*      clone() const = 0;
        
        //! Opportunity to make child elements
        virtual bool            submake() { return true; }

        
        //! Called when we've been triggered by a user event (ie, mouse clicked)
        //! \note Your state (if it's not-singular) should be at least protected-accessible
        //! UIElement default will call every registered action
        virtual void            triggered();
        void                    triggered(Payload& payload);
        void                    triggered(Payload&& payload);

        virtual void            update(flags_k){}
        
        //! Called on Widget ticks
        //! \note One *CANNOT* install ImGui textures/call-ImGui here (as there's no valid ImGui context)
        //! However frames & widget are valid (for data queries & message sending)
        virtual void            tick(){}
        
        
        //! Installs the specified texture, returns its ImGui texture ID
        static TextureID        install(const TextureCPtr&);
        
        //! Used to load a texture
        static TextureCPtr      texture(std::string_view);
        
        //! Creates an alternative from the given name (using filesystem path to parse)
        static std::string      alternative(std::string_view);

        static TextureCPtr      missing_texture();

        //! Sends to our widget
        static void             mail(const PostCPtr&);
        static void             send(const PostCPtr&);
        static void             gesture(GestureUPtr&&);
        
        //! Payload generator
        Payload                 payload();
        
        UIFlags                 m_flags;
        
        UIElement*              m_parent = nullptr;
        
        //! Our status (note this is NEVER copied on copy construction)
        Flags<S>                m_status = {};
        
        //! Binding ID (dynamic & unique to binding)
        uint64_t                m_bId   = 0;
        
        //! User specified ID
        std::string             m_uId;
        
        //! Actions to take when triggered (if this is such an element)
        std::vector<ActionCPtr> m_actions;

        static UIElement*       element(first_k, uint64_t);
        static UIElement*       element(first_k, const std::string&);

        // valid during render
        static ViContext*       vi_context() { return s_viContext; }
        
        // valid during tick
        static const Context*         context() { return s_context; }
        
    private:
        static thread_local Widget*         s_widget;
        static thread_local ViContext*      s_viContext;
        static thread_local const Context*  s_context;
        static UIStyle                      s_style;
    };
    
}
