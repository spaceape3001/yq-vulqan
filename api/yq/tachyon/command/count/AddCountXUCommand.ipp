////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountXUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountˣUCommand)

namespace yq::tachyon {
    AddCountˣUCommand::AddCountˣUCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_Δx(x)
    {
    }

    AddCountˣUCommand::AddCountˣUCommand(const AddCountˣUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddCountˣUCommand::~AddCountˣUCommand()
    {
    }
    
    PostCPtr    AddCountˣUCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountˣUCommand(*this, h);
    }

    void AddCountˣUCommand::init_meta()
    {
        auto w = writer<AddCountˣUCommand>();
        w.description("Add Count Command in X");
        w.property("Δx", &AddCountˣUCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
