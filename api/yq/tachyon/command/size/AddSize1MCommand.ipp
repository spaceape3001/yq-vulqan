////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize¹MCommand)

namespace yq::tachyon {
    AddSize¹MCommand::AddSize¹MCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddSize¹MCommand::AddSize¹MCommand(const Header& h, const Size1M& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddSize¹MCommand::AddSize¹MCommand(const AddSize¹MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddSize¹MCommand::~AddSize¹MCommand()
    {
    }
    
    PostCPtr    AddSize¹MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize¹MCommand(*this, h);
    }

    void AddSize¹MCommand::init_meta()
    {
        auto w = writer<AddSize¹MCommand>();
        w.description("Add Size MCommand");
        w.property("Δx", &AddSize¹MCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddSize¹MCommand::m_Δ).tag(kTag_Save);
    }
}
