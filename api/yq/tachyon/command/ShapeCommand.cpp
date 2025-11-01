////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/ShapeCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ShapeCommand)

namespace yq::tachyon {
    ShapeCommand::ShapeCommand(const Header& h) : Command(h)
    {
    }
    
    ShapeCommand::ShapeCommand(const ShapeCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    ShapeCommand::~ShapeCommand()
    {
    }
    
    void ShapeCommand::init_meta()
    {
        auto w = writer<ShapeCommand>();
        w.abstract();
        w.description("Shape Command");
    }
}
