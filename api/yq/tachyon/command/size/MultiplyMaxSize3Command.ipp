////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSize3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize³Command)

namespace yq::tachyon {
    MultiplyMaxSize³Command::MultiplyMaxSize³Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize³Command::MultiplyMaxSize³Command(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize³Command::MultiplyMaxSize³Command(const MultiplyMaxSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize³Command::~MultiplyMaxSize³Command()
    {
    }

    PostCPtr    MultiplyMaxSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize³Command(*this, h);
    }
    
    void MultiplyMaxSize³Command::init_meta()
    {
        auto w = writer<MultiplyMaxSize³Command>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize³Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize³Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMaxSize³Command::δz).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize³Command::m_δ).tag(kTag_Save);
    }
}
