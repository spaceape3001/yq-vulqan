////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMinSize4Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize⁴Command)

namespace yq::tachyon {
    MultiplyMinSize⁴Command::MultiplyMinSize⁴Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize⁴Command::MultiplyMinSize⁴Command(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize⁴Command::MultiplyMinSize⁴Command(const MultiplyMinSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize⁴Command::~MultiplyMinSize⁴Command()
    {
    }

    PostCPtr    MultiplyMinSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize⁴Command(*this, h);
    }
    
    void MultiplyMinSize⁴Command::init_info()
    {
        auto w = writer<MultiplyMinSize⁴Command>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize⁴Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize⁴Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMinSize⁴Command::δz).tag(kTag_Log);
        w.property("δw", &MultiplyMinSize⁴Command::δw).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize⁴Command::m_δ).tag(kTag_Save);
    }
}
