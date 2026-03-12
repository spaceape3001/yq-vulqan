////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySizeDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeDCommand)

namespace yq::tachyon {
    MultiplySizeDCommand::MultiplySizeDCommand(const Header&h, double f) : 
        SizeCommand(h), m_δ(f)
    {
    }

    MultiplySizeDCommand::MultiplySizeDCommand(const MultiplySizeDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySizeDCommand::MultiplySizeDCommand(const Header&h) : SizeCommand(h)
    {
    }

    MultiplySizeDCommand::~MultiplySizeDCommand()
    {
    }
    
    PostCPtr    MultiplySizeDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeDCommand(*this, h);
    }

    void MultiplySizeDCommand::init_meta()
    {
        auto w = writer<MultiplySizeDCommand>();
        w.description("Multiply Size DCommand");
        w.property("δ", &MultiplySizeDCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
