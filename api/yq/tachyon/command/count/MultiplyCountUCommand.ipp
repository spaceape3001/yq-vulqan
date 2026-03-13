////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "MultiplyCountUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountUCommand)

namespace yq::tachyon {
    MultiplyCountUCommand::MultiplyCountUCommand(const Header&h, unsigned f) : 
        CountCommand(h), m_δ(f)
    {
    }

    MultiplyCountUCommand::MultiplyCountUCommand(const MultiplyCountUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCountUCommand::MultiplyCountUCommand(const Header&h) : CountCommand(h)
    {
    }

    MultiplyCountUCommand::~MultiplyCountUCommand()
    {
    }
    
    PostCPtr    MultiplyCountUCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountUCommand(*this, h);
    }

    void MultiplyCountUCommand::init_meta()
    {
        auto w = writer<MultiplyCountUCommand>();
        w.description("Multiply Count Command");
        w.property("δ", &MultiplyCountUCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
