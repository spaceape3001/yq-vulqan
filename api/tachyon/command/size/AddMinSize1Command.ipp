////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSize1Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize¹Command)

namespace yq::tachyon {
    AddMinSize¹Command::AddMinSize¹Command(const Header& h) : SizeCommand(h)
    {
    }

    AddMinSize¹Command::AddMinSize¹Command(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMinSize¹Command::AddMinSize¹Command(const AddMinSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMinSize¹Command::~AddMinSize¹Command()
    {
    }
    
    PostCPtr    AddMinSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize¹Command(*this, h);
    }

    void AddMinSize¹Command::init_info()
    {
        auto w = writer<AddMinSize¹Command>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize¹Command::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMinSize¹Command::m_Δ).tag(kTag_Save);
    }
}
