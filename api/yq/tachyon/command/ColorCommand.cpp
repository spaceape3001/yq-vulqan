////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/ColorCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorCommand)

namespace yq::tachyon {
    ColorCommand::ColorCommand(const Header& h) : Command(h)
    {
    }
    
    ColorCommand::ColorCommand(const ColorCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    ColorCommand::~ColorCommand()
    {
    }
    
    void ColorCommand::init_meta()
    {
        auto w = writer<ColorCommand>();
        w.abstract();
        w.description("Color Command");
    }
}
