////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSize1Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize¹Command)

namespace yq::tachyon {
    MultiplyMaxSize¹Command::MultiplyMaxSize¹Command(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSize¹Command::MultiplyMaxSize¹Command(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize¹Command::MultiplyMaxSize¹Command(const MultiplyMaxSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyMaxSize¹Command::~MultiplyMaxSize¹Command()
    {
    }
    
    PostCPtr    MultiplyMaxSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize¹Command(*this, h);
    }

    void MultiplyMaxSize¹Command::init_meta()
    {
        auto w = writer<MultiplyMaxSize¹Command>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize¹Command::δx).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize¹Command::m_δ).tag(kTag_Save);
    }
}
