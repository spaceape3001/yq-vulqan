////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize³DCommand)

namespace yq::tachyon {
    AddSize³DCommand::AddSize³DCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize³DCommand::AddSize³DCommand(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize³DCommand::AddSize³DCommand(const AddSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize³DCommand::~AddSize³DCommand()
    {
    }

    PostCPtr    AddSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize³DCommand(*this, h);
    }
    
    void AddSize³DCommand::init_meta()
    {
        auto w = writer<AddSize³DCommand>();
        w.description("Add Size DCommand");
        w.property("Δx", &AddSize³DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize³DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize³DCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddSize³DCommand::m_Δ).tag(kTag_Save);
    }
}
