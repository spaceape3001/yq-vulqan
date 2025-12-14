////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/MaterialCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaterialCommand)

namespace yq::tachyon {
    MaterialCommand::MaterialCommand(const Header& h) : Command(h)
    {
    }
    
    MaterialCommand::MaterialCommand(const MaterialCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    MaterialCommand::~MaterialCommand()
    {
    }
    
    void MaterialCommand::init_meta()
    {
        auto w = writer<MaterialCommand>();
        w.abstract();
        w.description("Material Command");
    }
}
