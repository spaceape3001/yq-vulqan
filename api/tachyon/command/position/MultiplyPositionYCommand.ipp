////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionʸCommand)

namespace yq::tachyon {
    MultiplyPositionʸCommand::MultiplyPositionʸCommand(const Header& h) : 
        PositionCommand(h)
    {
    }
    
    MultiplyPositionʸCommand::MultiplyPositionʸCommand(const Header& h, double y) : 
        PositionCommand(h), m_δy(y)
    {
    }

    MultiplyPositionʸCommand::MultiplyPositionʸCommand(const MultiplyPositionʸCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyPositionʸCommand::~MultiplyPositionʸCommand()
    {
    }

    PostCPtr    MultiplyPositionʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionʸCommand(*this, h);
    }
    
    void MultiplyPositionʸCommand::init_info()
    {
        auto w = writer<MultiplyPositionʸCommand>();
        w.description("Multiply Position Command");
        w.property("δy", &MultiplyPositionʸCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
