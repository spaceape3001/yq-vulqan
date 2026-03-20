////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScaleMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleMCommand)

namespace yq::tachyon {
    AddScaleMCommand::AddScaleMCommand(const Header& h) : ScaleCommand(h)
    {
    }

    AddScaleMCommand::AddScaleMCommand(const Header& h, Meter v) : 
        ScaleCommand(h), m_Δscale(v)
    {
    }
    
    AddScaleMCommand::AddScaleMCommand(const AddScaleMCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δscale(cp.m_Δscale)
    {
    }

    AddScaleMCommand::~AddScaleMCommand()
    {
    }
    
    PostCPtr    AddScaleMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleMCommand(*this, h);
    }

    void AddScaleMCommand::init_meta()
    {
        auto w = writer<AddScaleMCommand>();
        w.description("Add Scale Command");
        w.property("Δscale",  &AddScaleMCommand::m_Δscale).tag(kTag_Save).tag(kTag_Log);
    }
}
