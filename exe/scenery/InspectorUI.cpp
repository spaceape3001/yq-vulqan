////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InspectorUI.hpp"
#include <tachyon/ui/UIEditorInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(InspectorUI)

struct InspectorUI::Repo {
};

InspectorUI::Repo& InspectorUI::repo()
{
    static Repo s_repo;
    return s_repo;
}

void InspectorUI::init_info()
{
    auto w = writer<InspectorUI>();
    w.description("Inspector UI");
}

InspectorUI::InspectorUI(UIFlags flags) : UIEditor(flags)
{
}

InspectorUI::InspectorUI(const InspectorUI& cp) : UIEditor(cp)
{
}

InspectorUI::~InspectorUI()
{
}

InspectorUI* InspectorUI::clone() const 
{
    return new InspectorUI(*this);
}

bool InspectorUI::bind(TypedID tid) 
{
    if(!UIEditor::bind(tid))
        return false;
    
    //  configuration here    
    
    return true;
}

void InspectorUI::render() 
{
    UIEditor::render();
    if(!snap())
        return ;
    
    
    // children....
}

