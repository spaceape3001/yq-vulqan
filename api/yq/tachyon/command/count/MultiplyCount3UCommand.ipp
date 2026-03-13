////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount3UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount³UCommand)

namespace yq::tachyon {
    MultiplyCount³UCommand::MultiplyCount³UCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    MultiplyCount³UCommand::MultiplyCount³UCommand(const Header& h, const Vector3U& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount³UCommand::MultiplyCount³UCommand(const MultiplyCount³UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCount³UCommand::~MultiplyCount³UCommand()
    {
    }

    PostCPtr    MultiplyCount³UCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount³UCommand(*this, h);
    }
    
    void MultiplyCount³UCommand::init_meta()
    {
        auto w = writer<MultiplyCount³UCommand>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount³UCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyCount³UCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyCount³UCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplyCount³UCommand::m_δ).tag(kTag_Save);
    }
}
