////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountWCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountʷCommand)

namespace yq::tachyon {
    AddCountʷCommand::AddCountʷCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_Δw(x)
    {
    }

    AddCountʷCommand::AddCountʷCommand(const AddCountʷCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddCountʷCommand::~AddCountʷCommand()
    {
    }
    
    PostCPtr    AddCountʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountʷCommand(*this, h);
    }

    void AddCountʷCommand::init_meta()
    {
        auto w = writer<AddCountʷCommand>();
        w.description("Add Count Command in X");
        w.property("Δw", &AddCountʷCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
