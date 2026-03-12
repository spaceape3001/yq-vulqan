////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize¹MCommand)

namespace yq::tachyon {
    AddMaxSize¹MCommand::AddMaxSize¹MCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddMaxSize¹MCommand::AddMaxSize¹MCommand(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMaxSize¹MCommand::AddMaxSize¹MCommand(const AddMaxSize¹MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMaxSize¹MCommand::~AddMaxSize¹MCommand()
    {
    }
    
    PostCPtr    AddMaxSize¹MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize¹MCommand(*this, h);
    }

    void AddMaxSize¹MCommand::init_meta()
    {
        auto w = writer<AddMaxSize¹MCommand>();
        w.description("AddMax Size MCommand");
        w.property("Δx", &AddMaxSize¹MCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize¹MCommand::m_Δ).tag(kTag_Save);
    }
}
