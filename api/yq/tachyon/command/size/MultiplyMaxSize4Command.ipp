////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/MultiplyMaxSize4Command.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize⁴Command)

namespace yq::tachyon {
    MultiplyMaxSize⁴Command::MultiplyMaxSize⁴Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize⁴Command::MultiplyMaxSize⁴Command(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize⁴Command::MultiplyMaxSize⁴Command(const MultiplyMaxSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize⁴Command::~MultiplyMaxSize⁴Command()
    {
    }

    PostCPtr    MultiplyMaxSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize⁴Command(*this, h);
    }
    
    void MultiplyMaxSize⁴Command::init_meta()
    {
        auto w = writer<MultiplyMaxSize⁴Command>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize⁴Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize⁴Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMaxSize⁴Command::δz).tag(kTag_Log);
        w.property("δw", &MultiplyMaxSize⁴Command::δw).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize⁴Command::m_δ).tag(kTag_Save);
    }
}
