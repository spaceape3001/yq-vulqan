////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>
#include <variant>
#include <yq/typedef/filesystem_path.hpp>

namespace yq::tachyon {

    /*! \brief Editor information
    */
    class EditorMeta : public WidgetMeta {
    public:
        
        template <typename C>  struct Writer;
        
        EditorMeta(std::string_view, WidgetMeta&, const std::source_location& sl = std::source_location::current());
    
        //! TRUE if this has/needs a menu bar
        bool        menu_bar() const { return has(Flag::MENU_BAR); }
    };
    
    //! Generic argument for a ID or a filepath or a string for editor specification
    using EditorSpec    = std::variant<std::monostate, uint64_t, std::filesystem::path, std::string>;
    
    
    //! Root for an editor widget
    //!
    //! Meant to be a general base for an editor widget
    class Editor : public Widget {
        YQ_TACHYON_META(EditorMeta)
        YQ_TACHYON_DECLARE(Editor, Widget)
    public:
    
        //! Override to load data from file or UID 
        virtual bool    load(EditorSpec) = 0;

        //! Override for widget to fill in the menu bar
        virtual void    menubar_(ViContext&){}
        
        //! Override to fill in IMGUI content
        virtual void    content_(ViContext&){}
        
        EditorID        id() const { return EditorID{ UniqueID::id() }; }
        
        //! This editor override calls the above two, don't need to override later unless doing something way different
        virtual void    imgui(ViContext&) override;
        
        //virtual void    draw(/*engine::ViContext&*/) override;
        
        
        //! File path of this file being edited
        const std::filesystem::path&    file() const { return m_file; }
        
        //! Default destructor
        virtual ~Editor();
        
        static void init_meta();
        
    protected:

        //! File path
        std::filesystem::path   m_file;
    
        //! Editor default constructor
        Editor();
    };
}
YQ_TYPE_DECLARE(yq::tachyon::EditorID)
