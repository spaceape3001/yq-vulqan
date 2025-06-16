////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSize1Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize¹Command)

namespace yq::tachyon {
    AddMaxSize¹Command::AddMaxSize¹Command(const Header& h) : SizeCommand(h)
    {
    }

    AddMaxSize¹Command::AddMaxSize¹Command(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMaxSize¹Command::AddMaxSize¹Command(const AddMaxSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMaxSize¹Command::~AddMaxSize¹Command()
    {
    }
    
    PostCPtr    AddMaxSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize¹Command(*this, h);
    }

    void AddMaxSize¹Command::init_info()
    {
        auto w = writer<AddMaxSize¹Command>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize¹Command::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize¹Command::m_Δ).tag(kTag_Save);
    }
}
