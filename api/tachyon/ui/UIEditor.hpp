////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TypedID.hpp>
#include <tachyon/ui/UIElements.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class UIEditorWriter;
    class TachyonInfo;
    class UIEditor;
    
    template <typename C>
    concept SomeUIEditor = std::derived_from<C,UIEditor>;
    
    class UIEditorInfo : public UIElements::MyInfo {    // using this syntax in case UIElements gets a dedicated info object
    public:
        template <typename> class Writer;
        
        UIEditorInfo(std::string_view, UIElements::MyInfo&, const std::source_location& sl = std::source_location::current());
    
        //! List of classes this thing will edit
        const std::vector<const TachyonInfo*>& edits() const { return m_edits; }
        
        static const std::vector<const UIEditorInfo*>& all();
        
        //  TODO... need a tree of recommendeds... (or similar)
        
    private:
        friend class UIEditor;
        struct Repo;
        static Repo& repo();
        
        struct Field;
        class FieldExecutor;
        template <SomeUIEditor C> struct BoundFieldExecutor;
    
        std::vector<const TachyonInfo*> m_edits;
        std::vector<Field>              m_fields;
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
        //! 
        virtual bool    bind(TypedID);
        virtual void    render();
        
    protected:
        virtual UIEditor*       clone() const = 0;
        
        TypedID                 bound() const { return m_bind; }
        const TachyonSnap*      snap() const { return m_snap; }
        
    private:
        TypedID                 m_bind;
        const TachyonSnap*      m_snap  = nullptr;
    };
}
