////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScaleXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleˣDCommand)

namespace yq::tachyon {
    AddScaleˣDCommand::AddScaleˣDCommand(const Header&h, double x) : 
        ScaleCommand(h), m_Δx(x)
    {
    }

    AddScaleˣDCommand::AddScaleˣDCommand(const AddScaleˣDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddScaleˣDCommand::~AddScaleˣDCommand()
    {
    }
    
    PostCPtr    AddScaleˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleˣDCommand(*this, h);
    }

    void AddScaleˣDCommand::init_meta()
    {
        auto w = writer<AddScaleˣDCommand>();
        w.description("Add Scale Command in X");
        w.property("Δx", &AddScaleˣDCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
