////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <basic/Object.hpp>
#include <basic/UniqueID.hpp>
#include <basic/Flags.hpp>
#include <meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    class Viewer;

    class WidgetInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;
        WidgetInfo(std::string_view, const ObjectInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    /*! \brief Root something that's drawwable & interactable
    
        It follows ImGui's rules, this is something that is 
        "drawable" and needs some amount of state information.
    */
    class Widget : public Object, public UniqueID {    
        YQ_OBJECT_INFO(WidgetInfo)
        YQ_OBJECT_DECLARE(Widget, Object)
    public:
    
        Widget();
        virtual ~Widget();

        virtual void    imgui_(ViContext&);
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
        
        Widget*         parent()  { return m_parent; }
        const Widget*   parent() const { return m_parent; }

        Widget*         root();
        const Widget*   root() const;
        
        Viewer*         viewer();
        const Viewer*   viewer() const ;

    protected:
        friend class Viewer;
        Viewer*                 m_viewer    = nullptr;
        Widget*                 m_parent    = nullptr;
        std::vector<Widget*>    m_children;
        std::string             m_windowID;
        
        virtual void            prerecord(ViContext&);

        virtual void            child_added(Widget*){}
        virtual void            child_removed(Widget*){}
    };

    template <typename C>
    class WidgetInfo::Writer : public ObjectInfo::Writer<C> {
    public:
        Writer(WidgetInfo* widgetInfo) : ObjectInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        Writer(WidgetInfo& widgetInfo) : Writer(&widgetInfo)
        {
        }

        void    imgui()
        {
            Meta::Writer::options({Flag::IMGUI});
        }
        
        void    vulkan()
        {
            Meta::Writer::options({Flag::VULKAN});
        }
        
    private:
        WidgetInfo* m_meta;
    };
}
