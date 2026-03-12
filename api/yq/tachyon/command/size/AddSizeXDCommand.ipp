////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeˣDCommand)

namespace yq::tachyon {
    AddSizeˣDCommand::AddSizeˣDCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddSizeˣDCommand::AddSizeˣDCommand(const AddSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddSizeˣDCommand::~AddSizeˣDCommand()
    {
    }
    
    PostCPtr    AddSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeˣDCommand(*this, h);
    }

    void AddSizeˣDCommand::init_meta()
    {
        auto w = writer<AddSizeˣDCommand>();
        w.description("Add Size DCommand in X");
        w.property("Δx", &AddSizeˣDCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
