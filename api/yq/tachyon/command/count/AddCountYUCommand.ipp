////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountYUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountʸUCommand)

namespace yq::tachyon {
    AddCountʸUCommand::AddCountʸUCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    AddCountʸUCommand::AddCountʸUCommand(const Header& h, unsigned y) : 
        CountCommand(h), m_Δy(y)
    {
    }
    
    AddCountʸUCommand::AddCountʸUCommand(const AddCountʸUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddCountʸUCommand::~AddCountʸUCommand()
    {
    }

    PostCPtr    AddCountʸUCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountʸUCommand(*this, h);
    }
    
    void AddCountʸUCommand::init_meta()
    {
        auto w = writer<AddCountʸUCommand>();
        w.description("Add Count Command in Y");
        w.property("Δy", &AddCountʸUCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
