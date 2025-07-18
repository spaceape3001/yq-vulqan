////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TypedID.hpp>
#include <tachyon/ui/UIForm.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class UIEditorWriter;
    class TachyonMeta;
    class UIEditor;
    class InterfaceMeta;
    
    template <typename C>
    concept SomeUIEditor = std::derived_from<C,UIEditor>;
    
    class UIEditorMeta : public UIFormMeta { 
    public:
        template <typename> class Writer;
        
        UIEditorMeta(std::string_view, UIFormMeta&, const std::source_location& sl = std::source_location::current());
    
        //! List of classes this thing will edit
        const std::vector<const TachyonMeta*>& edits(tachyon_k) const { return m_editTachyons; }
        const std::vector<const InterfaceMeta*>& edits(proxy_k) const { return m_editIProxies; }
        
        static const std::vector<const UIEditorMeta*>& all();
        
        //  TODO... need a tree of recommendeds... (or similar)
        
    private:
        friend class UIEditor;
        struct Repo;
        static Repo& repo();
        
        std::vector<const TachyonMeta*>     m_editTachyons;
        std::vector<const InterfaceMeta*>   m_editIProxies;
    };
    
    /*! \brief ImGui Editor Panel for a tachyon object
    
        \note The constructor *WON'T* have a specific tachyon, do that 
        configuration upon bind.
    */
    class UIEditor : public UIForm {
        YQ_OBJECT_META(UIEditorMeta)
        YQ_OBJECT_DECLARE(UIEditor, UIForm)
    public:
        using Writer = UIEditorWriter;

        UIEditor(UIFlags flags={});
        UIEditor(const UIEditor&);
        virtual ~UIEditor();
        
        static void init_meta();
        
        //! Binds to this tachyon ID (use the frame for details)
        //! 
        virtual bool    bind(TypedID);
        virtual void    render();
        TypedID         bound() const { return m_bind; }
       
    protected:
        virtual UIEditor*       clone() const = 0;
        
        const TachyonSnap*      snap() const { return m_snap; }
        
    private:
        TypedID                 m_bind;
        const TachyonSnap*      m_snap      = nullptr;
    };
}
