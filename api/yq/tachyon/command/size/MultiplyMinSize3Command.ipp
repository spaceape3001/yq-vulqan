////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/MultiplyMinSize3Command.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize³Command)

namespace yq::tachyon {
    MultiplyMinSize³Command::MultiplyMinSize³Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize³Command::MultiplyMinSize³Command(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize³Command::MultiplyMinSize³Command(const MultiplyMinSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize³Command::~MultiplyMinSize³Command()
    {
    }

    PostCPtr    MultiplyMinSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize³Command(*this, h);
    }
    
    void MultiplyMinSize³Command::init_meta()
    {
        auto w = writer<MultiplyMinSize³Command>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize³Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize³Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMinSize³Command::δz).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize³Command::m_δ).tag(kTag_Save);
    }
}
