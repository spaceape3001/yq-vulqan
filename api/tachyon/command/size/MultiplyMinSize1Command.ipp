////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMinSize1Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize¹Command)

namespace yq::tachyon {
    MultiplyMinSize¹Command::MultiplyMinSize¹Command(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMinSize¹Command::MultiplyMinSize¹Command(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize¹Command::MultiplyMinSize¹Command(const MultiplyMinSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyMinSize¹Command::~MultiplyMinSize¹Command()
    {
    }
    
    PostCPtr    MultiplyMinSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize¹Command(*this, h);
    }

    void MultiplyMinSize¹Command::init_info()
    {
        auto w = writer<MultiplyMinSize¹Command>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize¹Command::δx).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize¹Command::m_δ).tag(kTag_Save);
    }
}
