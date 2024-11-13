////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowAspectCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowAspectCommand)

namespace yq::tachyon {

    WindowAspectCommand::WindowAspectCommand(Viewer* v, const Size2I& asp, const Param& p) : WindowCommand(v, p), m_aspect(asp)
    {
    }
    
    WindowAspectCommand::~WindowAspectCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowAspectCommand::init_info()
    {
        auto w = writer<WindowAspectCommand>();
        w.description("Window Aspect Command");
        w.property("aspect", &WindowAspectCommand::aspect).description("Aspect ratio");
        w.property("width", &WindowAspectCommand::width).description("Aspect width").alias("w");
        w.property("height", &WindowAspectCommand::height).description("Aspect height").alias("h");
    }
}
