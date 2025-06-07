////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplySize1Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize¹Command)

namespace yq::tachyon {
    MultiplySize¹Command::MultiplySize¹Command(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySize¹Command::MultiplySize¹Command(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize¹Command::MultiplySize¹Command(const MultiplySize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplySize¹Command::~MultiplySize¹Command()
    {
    }
    
    PostCPtr    MultiplySize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize¹Command(*this, h);
    }

    void MultiplySize¹Command::init_info()
    {
        auto w = writer<MultiplySize¹Command>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize¹Command::δx).tag(kTag_Log);
        w.property("δ", &MultiplySize¹Command::m_δ).tag(kTag_Save);
    }
}
