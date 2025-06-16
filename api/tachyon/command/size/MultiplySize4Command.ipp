////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplySize4Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize⁴Command)

namespace yq::tachyon {
    MultiplySize⁴Command::MultiplySize⁴Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize⁴Command::MultiplySize⁴Command(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize⁴Command::MultiplySize⁴Command(const MultiplySize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize⁴Command::~MultiplySize⁴Command()
    {
    }

    PostCPtr    MultiplySize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize⁴Command(*this, h);
    }
    
    void MultiplySize⁴Command::init_info()
    {
        auto w = writer<MultiplySize⁴Command>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize⁴Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize⁴Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplySize⁴Command::δz).tag(kTag_Log);
        w.property("δw", &MultiplySize⁴Command::δw).tag(kTag_Log);
        w.property("δ", &MultiplySize⁴Command::m_δ).tag(kTag_Save);
    }
}
