////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySize3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize³Command)

namespace yq::tachyon {
    MultiplySize³Command::MultiplySize³Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize³Command::MultiplySize³Command(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize³Command::MultiplySize³Command(const MultiplySize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize³Command::~MultiplySize³Command()
    {
    }

    PostCPtr    MultiplySize³Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize³Command(*this, h);
    }
    
    void MultiplySize³Command::init_meta()
    {
        auto w = writer<MultiplySize³Command>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize³Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize³Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplySize³Command::δz).tag(kTag_Log);
        w.property("δ", &MultiplySize³Command::m_δ).tag(kTag_Save);
    }
}
