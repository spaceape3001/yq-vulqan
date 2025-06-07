////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScaleYCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleʸCommand)

namespace yq::tachyon {
    AddScaleʸCommand::AddScaleʸCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }

    AddScaleʸCommand::AddScaleʸCommand(const Header& h, double y) : 
        ScaleCommand(h), m_Δy(y)
    {
    }
    
    AddScaleʸCommand::AddScaleʸCommand(const AddScaleʸCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddScaleʸCommand::~AddScaleʸCommand()
    {
    }

    PostCPtr    AddScaleʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleʸCommand(*this, h);
    }
    
    void AddScaleʸCommand::init_info()
    {
        auto w = writer<AddScaleʸCommand>();
        w.description("Add Scale Command in Y");
        w.property("Δy", &AddScaleʸCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
