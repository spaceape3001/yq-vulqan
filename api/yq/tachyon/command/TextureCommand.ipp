////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/TextureCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TextureCommand)

namespace yq::tachyon {
    TextureCommand::TextureCommand(const Header& h) : Command(h)
    {
    }
    
    TextureCommand::TextureCommand(const TextureCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    TextureCommand::~TextureCommand()
    {
    }
    
    void TextureCommand::init_meta()
    {
        auto w = writer<TextureCommand>();
        w.abstract();
        w.description("Texture Command");
    }
}
