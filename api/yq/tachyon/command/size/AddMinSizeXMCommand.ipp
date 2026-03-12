////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeˣDCommand)

namespace yq::tachyon {
    AddMinSizeˣDCommand::AddMinSizeˣDCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMinSizeˣDCommand::AddMinSizeˣDCommand(const AddMinSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMinSizeˣDCommand::~AddMinSizeˣDCommand()
    {
    }
    
    PostCPtr    AddMinSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeˣDCommand(*this, h);
    }

    void AddMinSizeˣDCommand::init_meta()
    {
        auto w = writer<AddMinSizeˣDCommand>();
        w.description("AddMin Size DCommand in X");
        w.property("Δx", &AddMinSizeˣDCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
