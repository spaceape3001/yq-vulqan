////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/SceneCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SceneCommand)

namespace yq::tachyon {
    SceneCommand::SceneCommand(const Header& h) : Command(h)
    {
    }
    
    SceneCommand::SceneCommand(const SceneCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    SceneCommand::~SceneCommand()
    {
    }
    
    void SceneCommand::init_meta()
    {
        auto w = writer<SceneCommand>();
        w.abstract();
        w.description("Scene Command");
    }
}
