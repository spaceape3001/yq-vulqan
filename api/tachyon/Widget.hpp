////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <0/basic/Object.hpp>
#include <0/basic/UniqueID.hpp>
#include <0/basic/Flags.hpp>
#include <0/meta/ObjectInfoWriter.hpp>

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
        virtual void            child_added(Widget*){}
        
        //! Called when a child of this widget is removed
        virtual void            child_removed(Widget*){}
    };

    /*! \brief Writer of widget information
    */
    template <typename C>
    class WidgetInfo::Writer : public ObjectInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(WidgetInfo* widgetInfo) : ObjectInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(WidgetInfo& widgetInfo) : Writer(&widgetInfo)
        {
        }

        //! Annotates that this widget will render IMGUI content
        void    imgui()
        {
            Meta::Writer::options({Flag::IMGUI});
        }
        
        //! Annotates that this widget will render Vulkan content
        void    vulkan()
        {
            Meta::Writer::options({Flag::VULKAN});
        }
        
    private:
        WidgetInfo* m_meta;
    };
}
