////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountWUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountʷUCommand)

namespace yq::tachyon {
    AddCountʷUCommand::AddCountʷUCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_Δw(x)
    {
    }

    AddCountʷUCommand::AddCountʷUCommand(const AddCountʷUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddCountʷUCommand::~AddCountʷUCommand()
    {
    }
    
    PostCPtr    AddCountʷUCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountʷUCommand(*this, h);
    }

    void AddCountʷUCommand::init_meta()
    {
        auto w = writer<AddCountʷUCommand>();
        w.description("Add Count Command in X");
        w.property("Δw", &AddCountʷUCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
