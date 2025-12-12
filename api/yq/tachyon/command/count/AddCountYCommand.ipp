////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountʸCommand)

namespace yq::tachyon {
    AddCountʸCommand::AddCountʸCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    AddCountʸCommand::AddCountʸCommand(const Header& h, unsigned y) : 
        CountCommand(h), m_Δy(y)
    {
    }
    
    AddCountʸCommand::AddCountʸCommand(const AddCountʸCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddCountʸCommand::~AddCountʸCommand()
    {
    }

    PostCPtr    AddCountʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountʸCommand(*this, h);
    }
    
    void AddCountʸCommand::init_meta()
    {
        auto w = writer<AddCountʸCommand>();
        w.description("Add Count Command in Y");
        w.property("Δy", &AddCountʸCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
