////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/UICommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICommand)

namespace yq::tachyon {
    UICommand::UICommand(const Header& h) : Command(h)
    {
    }
    
    UICommand::UICommand(const UICommand&cp, const Header&h) : Command(cp, h)
    {
    }

    UICommand::~UICommand()
    {
    }
    
    void UICommand::init_meta()
    {
        auto w = writer<UICommand>();
        w.abstract();
        w.description("UI Command");
    }
}
