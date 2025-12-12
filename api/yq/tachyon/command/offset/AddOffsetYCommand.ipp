////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddOffsetYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddOffsetʸCommand)

namespace yq::tachyon {
    AddOffsetʸCommand::AddOffsetʸCommand(const Header&h) : 
        OffsetCommand(h)
    {
    }

    AddOffsetʸCommand::AddOffsetʸCommand(const Header&h, double Δy) : 
        OffsetCommand(h), m_Δy(Δy)
    {
    }

    AddOffsetʸCommand::AddOffsetʸCommand(const AddOffsetʸCommand& cp, const Header&h) : 
        OffsetCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    AddOffsetʸCommand::~AddOffsetʸCommand()
    {
    }
    
    PostCPtr    AddOffsetʸCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddOffsetʸCommand(*this, h);
    }

    void AddOffsetʸCommand::init_meta()
    {
        auto w = writer<AddOffsetʸCommand>();
        w.description("Offset AddOffset Command in Y");
        w.property("Δy", &AddOffsetʸCommand::Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
