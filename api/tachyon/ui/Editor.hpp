////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/widget/Widget.hpp>
#include <variant>
#include <filesystem>

namespace yq::tachyon {

    /*! \brief Editor information
    */
    class EditorInfo : public WidgetInfo {
    public:
        
        template <typename C>  struct Writer;
        
        EditorInfo(std::string_view, WidgetInfo&, const std::source_location& sl = std::source_location::current());
    
        //! TRUE if this has/needs a menu bar
        bool        menu_bar() const { return has(Flag::MENU_BAR); }
    };
    
    //! Generic argument for a ID or a filepath or a string for editor specification
    using EditorSpec    = std::variant<std::monostate, uint64_t, std::filesystem::path, std::string>;
    
    
    //! Root for an editor widget
    //!
    //! Meant to be a general base for an editor widget
    class Editor : public Widget {
        YQ_OBJECT_INFO(EditorInfo)
        YQ_OBJECT_DECLARE(Editor, Widget)
    public:
    
        //! Override to load data from file or UID 
        virtual bool    load(EditorSpec) = 0;

        //! Override for widget to fill in the menu bar
        virtual void    menubar_(ViContext&){}
        
        //! Override to fill in IMGUI content
        virtual void    content_(ViContext&){}
        
        //! This editor override calls the above two, don't need to override later unless doing something way different
        virtual void    imgui_(ViContext&) override;
        
        //virtual void    draw(/*engine::ViContext&*/) override;
        
        
        //! File path of this file being edited
        const std::filesystem::path&    file() const { return m_file; }
        
        //! Default destructor
        virtual ~Editor();
        
    protected:

        //! File path
        std::filesystem::path   m_file;
    
        //! Editor default constructor
        Editor();
    };

    /*! \brief Writer of editor information
    */
    template <typename C>
    class EditorInfo::Writer : public WidgetInfo::Writer<C> {
    public:
    
        Writer(EditorInfo* editorInfo) : WidgetInfo::Writer<C>(editorInfo), m_meta(editorInfo)
        {
        }
        
        Writer(EditorInfo& editorInfo) : Writer(&editorInfo)
        {
        }
        
        Writer&     menu_bar()
        {
            Meta::Writer::options({ Flag::MENU_BAR });
            return *this;
        }
        
    private:
        EditorInfo* m_meta;
        
    };
}
