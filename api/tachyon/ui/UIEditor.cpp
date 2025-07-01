////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIEditor.hpp"
#include "UIEditorWriter.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <tachyon/ui/UIEditorMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIEditor)

namespace yq::tachyon {
    struct UIEditorMeta::Repo {
        std::vector<const UIEditorMeta*>    all;
    };
    
    UIEditorMeta::Repo& UIEditorMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }
    
    const std::vector<const UIEditorMeta*>& UIEditorMeta::all()
    {
        return repo().all;
    }

    UIEditorMeta::UIEditorMeta(std::string_view name, UIFormMeta&base, const std::source_location& sl) :
        UIFormMeta(name, base, sl)
    {
        repo().all.push_back(this);
    }

    ////////////////////////////

    void UIEditor::init_meta()
    {
        auto w = writer<UIEditor>();
        w.description("UI Editor");
        w.abstract();
    }
    
    UIEditor::UIEditor(UIFlags flags) : UIForm(flags)
    {
    }
    
    UIEditor::UIEditor(const UIEditor& cp) : UIForm(cp), m_bind(cp.m_bind), m_snap(nullptr)
    {
    }
    
    UIEditor::~UIEditor()
    {
    }

    bool    UIEditor::bind(TypedID tac)
    {
        m_bind      = tac;
        return true;
    }

    void    UIEditor::render()
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return;
        m_snap          = frame->snap(m_bind);
        if(!m_snap)
            return ;
        
        UIForm::render();
    }

    ////////////////////////////
    
    UIEditorWriter::UIEditorWriter() = default;
    UIEditorWriter::UIEditorWriter(const UIEditorWriter&) = default;
    UIEditorWriter::~UIEditorWriter() = default;
    
    UIEditor* UIEditorWriter::element()
    {
        return dynamic_cast<UIEditor*>(m_ui);
    }
    
    UIEditorWriter::UIEditorWriter(UIEditor* ui) : UIFormWriter(ui)
    {
    }

}
