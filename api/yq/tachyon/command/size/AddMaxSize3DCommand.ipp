////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize³DCommand)

namespace yq::tachyon {
    AddMaxSize³DCommand::AddMaxSize³DCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize³DCommand::AddMaxSize³DCommand(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize³DCommand::AddMaxSize³DCommand(const AddMaxSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize³DCommand::~AddMaxSize³DCommand()
    {
    }

    PostCPtr    AddMaxSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize³DCommand(*this, h);
    }
    
    void AddMaxSize³DCommand::init_meta()
    {
        auto w = writer<AddMaxSize³DCommand>();
        w.description("AddMax Size DCommand");
        w.property("Δx", &AddMaxSize³DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize³DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize³DCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize³DCommand::m_Δ).tag(kTag_Save);
    }
}
