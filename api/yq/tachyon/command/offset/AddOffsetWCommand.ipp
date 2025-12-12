////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddOffsetWCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddOffsetʷCommand)

namespace yq::tachyon {
    AddOffsetʷCommand::AddOffsetʷCommand(const Header&h) : 
        OffsetCommand(h)
    {
    }

    AddOffsetʷCommand::AddOffsetʷCommand(const Header&h, double Δw) : 
        OffsetCommand(h), m_Δw(Δw)
    {
    }
    
    AddOffsetʷCommand::AddOffsetʷCommand(const AddOffsetʷCommand& cp, const Header&h) : 
        OffsetCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    AddOffsetʷCommand::~AddOffsetʷCommand()
    {
    }
    
    PostCPtr    AddOffsetʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddOffsetʷCommand(*this, h);
    }

    void AddOffsetʷCommand::init_meta()
    {
        auto w = writer<AddOffsetʷCommand>();
        w.description("Offset AddOffset Command in X");
        w.property("Δw", &AddOffsetʷCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
