////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/EditorCommand.hpp>

#include <yq/tachyon/api/CommandMetaWriter.hpp>

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

    void EditorCommand::init_meta()
    {
        auto w = writer<EditorCommand>();
        w.description("Editor command base class");
    }
}
