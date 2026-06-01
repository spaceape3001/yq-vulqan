////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize¹CMCommand)

namespace yq::tachyon {
    AddMaxSize¹CMCommand::AddMaxSize¹CMCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddMaxSize¹CMCommand::AddMaxSize¹CMCommand(const Header& h, const Size1CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMaxSize¹CMCommand::AddMaxSize¹CMCommand(const AddMaxSize¹CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMaxSize¹CMCommand::~AddMaxSize¹CMCommand()
    {
    }
    
    PostCPtr    AddMaxSize¹CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize¹CMCommand(*this, h);
    }

    void AddMaxSize¹CMCommand::init_meta()
    {
        auto w = writer<AddMaxSize¹CMCommand>();
        w.description("AddMax Size CMCommand");
        w.property("Δx", &AddMaxSize¹CMCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize¹CMCommand::m_Δ).tag(kTag_Save);
    }
}
