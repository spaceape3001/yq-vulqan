////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount³Command)

namespace yq::tachyon {
    MultiplyCount³Command::MultiplyCount³Command(const Header& h) : 
        CountCommand(h)
    {
    }

    MultiplyCount³Command::MultiplyCount³Command(const Header& h, const Vector3U& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount³Command::MultiplyCount³Command(const MultiplyCount³Command& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCount³Command::~MultiplyCount³Command()
    {
    }

    PostCPtr    MultiplyCount³Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount³Command(*this, h);
    }
    
    void MultiplyCount³Command::init_meta()
    {
        auto w = writer<MultiplyCount³Command>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount³Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyCount³Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyCount³Command::δz).tag(kTag_Log);
        w.property("δ", &MultiplyCount³Command::m_δ).tag(kTag_Save);
    }
}
