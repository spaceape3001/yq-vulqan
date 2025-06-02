////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class UIEditorWriter;
    class TachyonInfo;
    
    class UIEditorInfo : public UIElements::MyInfo {    // using this syntax in case UIElements gets a dedicated info object
    public:
        template <typename> class Writer;
        
        UIEditorInfo(std::string_view, UIElements::MyInfo&, const std::source_location& sl = std::source_location::current());
    
        //! List of classes this thing will edit
        const std::vector<const TachyonInfo*>& edits() const { return m_edits; }
        
        static const std::vector<const UIEditorInfo*>& all();
    
    private:
        struct Repo;
        static Repo& repo();
        std::vector<const TachyonInfo*> m_edits;
    };
    
    /*! \brief ImGui Editor Panel for a tachyon object
    
        \note The constructor *WON'T* have a specific tachyon, do that 
        configuration upon bind.
    */
    class UIEditor : public UIElements {
        YQ_OBJECT_INFO(UIEditorInfo)
        YQ_OBJECT_DECLARE(UIEditor, UIElements)
    public:
        using Writer = UIEditorWriter;

        UIEditor(UIFlags flags={});
        UIEditor(const UIEditor&);
        virtual ~UIEditor();
        
        static void init_info();
        
        //! Binds to this tachyon ID (use the frame for details)
        virtual bool            bind(TachyonID) = 0;
        virtual void            render() = 0;
        
    protected:
        virtual UIEditor*       clone() const = 0;
    };
}
