////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/ColorProfileCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorProfileCommand)

namespace yq::tachyon {
    ColorProfileCommand::ColorProfileCommand(const Header& h) : Command(h)
    {
    }
    
    ColorProfileCommand::ColorProfileCommand(const ColorProfileCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    ColorProfileCommand::~ColorProfileCommand()
    {
    }
    
    void ColorProfileCommand::init_meta()
    {
        auto w = writer<ColorProfileCommand>();
        w.abstract();
        w.description("Color Profile Command");
    }
}
