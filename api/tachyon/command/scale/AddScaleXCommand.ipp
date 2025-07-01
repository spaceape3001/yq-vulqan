////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScaleXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleˣCommand)

namespace yq::tachyon {
    AddScaleˣCommand::AddScaleˣCommand(const Header&h, double x) : 
        ScaleCommand(h), m_Δx(x)
    {
    }

    AddScaleˣCommand::AddScaleˣCommand(const AddScaleˣCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddScaleˣCommand::~AddScaleˣCommand()
    {
    }
    
    PostCPtr    AddScaleˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleˣCommand(*this, h);
    }

    void AddScaleˣCommand::init_info()
    {
        auto w = writer<AddScaleˣCommand>();
        w.description("Add Scale Command in X");
        w.property("Δx", &AddScaleˣCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
