////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScaleYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleʸDCommand)

namespace yq::tachyon {
    AddScaleʸDCommand::AddScaleʸDCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }

    AddScaleʸDCommand::AddScaleʸDCommand(const Header& h, double y) : 
        ScaleCommand(h), m_Δy(y)
    {
    }
    
    AddScaleʸDCommand::AddScaleʸDCommand(const AddScaleʸDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddScaleʸDCommand::~AddScaleʸDCommand()
    {
    }

    PostCPtr    AddScaleʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleʸDCommand(*this, h);
    }
    
    void AddScaleʸDCommand::init_meta()
    {
        auto w = writer<AddScaleʸDCommand>();
        w.description("Add Scale Command in Y");
        w.property("Δy", &AddScaleʸDCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
