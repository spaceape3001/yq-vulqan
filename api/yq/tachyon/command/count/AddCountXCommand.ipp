////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountXCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountˣCommand)

namespace yq::tachyon {
    AddCountˣCommand::AddCountˣCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_Δx(x)
    {
    }

    AddCountˣCommand::AddCountˣCommand(const AddCountˣCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddCountˣCommand::~AddCountˣCommand()
    {
    }
    
    PostCPtr    AddCountˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountˣCommand(*this, h);
    }

    void AddCountˣCommand::init_meta()
    {
        auto w = writer<AddCountˣCommand>();
        w.description("Add Count Command in X");
        w.property("Δx", &AddCountˣCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
