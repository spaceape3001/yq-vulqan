////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize¹CMCommand)

namespace yq::tachyon {
    AddSize¹CMCommand::AddSize¹CMCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddSize¹CMCommand::AddSize¹CMCommand(const Header& h, const Size1CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddSize¹CMCommand::AddSize¹CMCommand(const AddSize¹CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddSize¹CMCommand::~AddSize¹CMCommand()
    {
    }
    
    PostCPtr    AddSize¹CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize¹CMCommand(*this, h);
    }

    void AddSize¹CMCommand::init_meta()
    {
        auto w = writer<AddSize¹CMCommand>();
        w.description("Add Size CMCommand");
        w.property("Δx", &AddSize¹CMCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddSize¹CMCommand::m_Δ).tag(kTag_Save);
    }
}
