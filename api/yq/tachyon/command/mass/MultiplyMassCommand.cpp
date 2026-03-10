////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMassCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMassCommand)

namespace yq::tachyon {
    MultiplyMassCommand::MultiplyMassCommand(const Header&h, double δ) : 
        MassCommand(h), m_δmass(δ)
    {
    }

    MultiplyMassCommand::MultiplyMassCommand(const MultiplyMassCommand& cp, const Header& h) : 
        MassCommand(cp, h), m_δmass(cp.m_δmass)
    {
    }
    
    MultiplyMassCommand::MultiplyMassCommand(const Header&h) : MassCommand(h)
    {
    }

    MultiplyMassCommand::~MultiplyMassCommand()
    {
    }
    
    PostCPtr    MultiplyMassCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMassCommand(*this, h);
    }

    void MultiplyMassCommand::init_meta()
    {
        auto w = writer<MultiplyMassCommand>();
        w.description("Multiply Mass Command");
        w.property("δmass", &MultiplyMassCommand::m_δmass).tag(kTag_Log).tag(kTag_Save);
    }
}
