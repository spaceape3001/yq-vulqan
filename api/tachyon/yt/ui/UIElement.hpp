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
#include <yq/typedef/axbox2.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/Tristate.hpp>
#include <yt/api/Action.hpp>
#include <tachyon/typedef/action.hpp>
#include <tachyon/typedef/texture.hpp>
#include <tachyon/typedef/uielement.hpp>

namespace yq::tachyon {
    struct ViContext;
    class Widget;
    class WidgetInfo;
    class Viewer;
    struct UIStyle;
    class UIElement;
    class UIElementWriter;
    class UIGenerator;
    
    class UIElementInfo : public ObjectInfo {
    public:
        template <typename> class Writer;
        UIElementInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());
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
        YQ_OBJECT_INFO(UIElementInfo)
        YQ_OBJECT_DECLARE(UIElement, Object)
    public:
    
        using Writer = UIElementWriter;
    
        UIElement(UIFlags flags={});
        UIElement(const UIElement&);
        virtual ~UIElement();
        
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
        virtual void    draw();
        
        ////! Spawn off any root ui elements (ie, dialogs, docks, windows, etc)
        //virtual std::vector<UIElement*> spawn();
        
        //! Our element's "title" (may be null)
        virtual const char*   title() const { return nullptr; }

        UIFlags     flags() const noexcept { return m_flags; }
        void        flag(set_k, UIFlag);
        void        flags(set_k, UIFlags);
        void        flag(clear_k, UIFlag);
        void        flags(clear_k, UIFlags);
        void        flag(set_k, UIFlag, bool);
        
        void        flag(toggle_k, UIFlag);
        
        bool        flag(UIFlag v) const;
        
        //! Checks to see if the UI element is or is derived from specified type (or is a generator)
        virtual Tristate is(const UIElementInfo& baseInfo) const;
        
        template <SomeUIElement U>
        Tristate is() const
        {
            return is(meta<U>());
        }

        UIElement*  parent();
        const UIElement*  parent() const;
        
        UIElement*  root();
        const UIElement* root() const;

        //! Viewport in window/viewer coordinates
        virtual AxBox2F     viewport() const;

        //! Viewport for content in screen coordinates
        virtual AxBox2F     viewport(content_k) const;
        
        static void init_info();

        //! Unique binding if not zero
        uint64_t            binding() const { return m_bId; }
        
        uint64_t            binding(create_k);
        
        //! User assigned ID (may or may not be unique)
        const std::string&    uid() const { return m_uId; }

        /*! \brief Current widget being processed (NULL if this isn't true)
        
            \note This is TLS data, so it'll be valid (or not) for the duration 
            of you being called, however, do not RETAIN this pointer!
        */

        static Widget*          widget();

        //! UI Element style
        static const UIStyle&   style();

    protected:
        friend class Widget;
        friend class UIGenerator;
        friend class UIElements;
        friend class UIElementWriter;

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
            HasAccessor
        };

        /*! \brief Clones the element
        
            For all elements that are specified during the widget info *MUST* implement 
            this.
        */
        virtual UIElement*     clone() const = 0;
        

        /*! \brief RENDER/DRAW the element as a whole
        
            This is the first hook for rendering/drawing the ImGui content; this is what 
            is normally overriden.
        */
        virtual void            render() {}

        //! Called if there's an if-show/perform test inside render, or similar encapsulation
        virtual void            content() {}
        
        //! Called when we've been triggered by a user event (ie, mouse clicked)
        //! \note Your state (if it's not-singular) should be at least protected-accessible
        //! UIElement default will call every registered action
        virtual void            triggered();
        void                    triggered(Action::Payload& payload);

        virtual void            update(flags_k){}
        
        
        //! Installs the specified texture, returns its ImGui texture ID
        static ImTextureID      install(const TextureCPtr&);
        
        //! Used to load a texture
        static TextureCPtr      texture(std::string_view);
        
        //! Creates an alternative from the given name (using filesystem path to parse)
        static std::string      alternative(std::string_view);

        static TextureCPtr      missing_texture();

        
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
        
    private:
        static thread_local Widget*     s_widget;
        static thread_local ViContext*  s_context;
        static UIStyle                  s_style;
    };
    
}
