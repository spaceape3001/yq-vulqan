////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/EditorCommand.hpp>

#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EditorCommand)

namespace yq::tachyon {
    EditorCommand::EditorCommand(const Header&h) : Command(h)
    {
    }
    
    EditorCommand::EditorCommand(const EditorCommand& cp, const Header&h) : Command(cp, h)
    {
    }


    EditorCommand::~EditorCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void EditorCommand::init_info()
    {
        auto w = writer<EditorCommand>();
        w.description("Editor command base class");
    }
}
