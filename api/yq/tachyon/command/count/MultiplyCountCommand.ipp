////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "MultiplyCountCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountCommand)

namespace yq::tachyon {
    MultiplyCountCommand::MultiplyCountCommand(const Header&h, unsigned f) : 
        CountCommand(h), m_δ(f)
    {
    }

    MultiplyCountCommand::MultiplyCountCommand(const MultiplyCountCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCountCommand::MultiplyCountCommand(const Header&h) : CountCommand(h)
    {
    }

    MultiplyCountCommand::~MultiplyCountCommand()
    {
    }
    
    PostCPtr    MultiplyCountCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountCommand(*this, h);
    }

    void MultiplyCountCommand::init_meta()
    {
        auto w = writer<MultiplyCountCommand>();
        w.description("Multiply Count Command");
        w.property("δ", &MultiplyCountCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
