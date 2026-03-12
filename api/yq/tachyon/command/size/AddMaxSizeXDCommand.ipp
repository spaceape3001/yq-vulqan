////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeˣDCommand)

namespace yq::tachyon {
    AddMaxSizeˣDCommand::AddMaxSizeˣDCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMaxSizeˣDCommand::AddMaxSizeˣDCommand(const AddMaxSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMaxSizeˣDCommand::~AddMaxSizeˣDCommand()
    {
    }
    
    PostCPtr    AddMaxSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeˣDCommand(*this, h);
    }

    void AddMaxSizeˣDCommand::init_meta()
    {
        auto w = writer<AddMaxSizeˣDCommand>();
        w.description("AddMax Size DCommand in X");
        w.property("Δx", &AddMaxSizeˣDCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
