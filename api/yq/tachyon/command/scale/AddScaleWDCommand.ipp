////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScaleWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleʷDCommand)

namespace yq::tachyon {
    AddScaleʷDCommand::AddScaleʷDCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    AddScaleʷDCommand::AddScaleʷDCommand(const Header&h, double z) : 
        ScaleCommand(h), m_Δw(z)
    {
    }

    AddScaleʷDCommand::AddScaleʷDCommand(const AddScaleʷDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    AddScaleʷDCommand::~AddScaleʷDCommand()
    {
    }

    PostCPtr    AddScaleʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleʷDCommand(*this, h);
    }
    
    void AddScaleʷDCommand::init_meta()
    {
        auto w = writer<AddScaleʷDCommand>();
        w.description("Add Scale Command in Z");
        w.property("Δw", &AddScaleʷDCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
