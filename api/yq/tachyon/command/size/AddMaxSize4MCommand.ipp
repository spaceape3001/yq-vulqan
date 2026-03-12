////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize⁴DCommand)

namespace yq::tachyon {
    AddMaxSize⁴DCommand::AddMaxSize⁴DCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize⁴DCommand::AddMaxSize⁴DCommand(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize⁴DCommand::AddMaxSize⁴DCommand(const AddMaxSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize⁴DCommand::~AddMaxSize⁴DCommand()
    {
    }

    PostCPtr    AddMaxSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize⁴DCommand(*this, h);
    }
    
    void AddMaxSize⁴DCommand::init_meta()
    {
        auto w = writer<AddMaxSize⁴DCommand>();
        w.description("AddMax Size DCommand");
        w.property("Δx", &AddMaxSize⁴DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize⁴DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize⁴DCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddMaxSize⁴DCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize⁴DCommand::m_Δ).tag(kTag_Save);
    }
}
