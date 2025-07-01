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
    class InterfaceInfo;
    
    template <typename C>
    concept SomeUIEditor = std::derived_from<C,UIEditor>;
    
    class UIEditorInfo : public UIFormInfo { 
    public:
        template <typename> class Writer;
        
        UIEditorInfo(std::string_view, UIFormInfo&, const std::source_location& sl = std::source_location::current());
    
        //! List of classes this thing will edit
        const std::vector<const TachyonMeta*>& edits(tachyon_k) const { return m_editTachyons; }
        const std::vector<const InterfaceInfo*>& edits(proxy_k) const { return m_editIProxies; }
        
        static const std::vector<const UIEditorInfo*>& all();
        
        //  TODO... need a tree of recommendeds... (or similar)
        
    private:
        friend class UIEditor;
        struct Repo;
        static Repo& repo();
        
        std::vector<const TachyonMeta*>     m_editTachyons;
        std::vector<const InterfaceInfo*>   m_editIProxies;
    };
    
    /*! \brief ImGui Editor Panel for a tachyon object
    
        \note The constructor *WON'T* have a specific tachyon, do that 
        configuration upon bind.
    */
    class UIEditor : public UIForm {
        YQ_OBJECT_INFO(UIEditorInfo)
        YQ_OBJECT_DECLARE(UIEditor, UIForm)
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
        TypedID         bound() const { return m_bind; }
       
    protected:
        virtual UIEditor*       clone() const = 0;
        
        const TachyonSnap*      snap() const { return m_snap; }
        
    private:
        TypedID                 m_bind;
        const TachyonSnap*      m_snap      = nullptr;
    };
}
