////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowSizeCommand.hpp"

#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/strings.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowSizeCommand)

namespace yq::tachyon {

    WindowSizeCommand::WindowSizeCommand(Window* v, const Size2I& sz, const Param& p) : WindowCommand(v, p), m_size(sz)
    {
    }
    
    WindowSizeCommand::~WindowSizeCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowSizeCommand::init_info()
    {
        auto w = writer<WindowSizeCommand>();
        w.description("Window Size Command");
        w.property("size", &WindowSizeCommand::size).description("New Size");
        w.property("width", &WindowSizeCommand::width).description("New Width").alias("w");
        w.property("height", &WindowSizeCommand::height).description("New Height").alias("h");
    }
}
