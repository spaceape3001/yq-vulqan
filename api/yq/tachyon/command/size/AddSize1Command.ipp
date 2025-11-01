////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSize1Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize¹Command)

namespace yq::tachyon {
    AddSize¹Command::AddSize¹Command(const Header& h) : SizeCommand(h)
    {
    }

    AddSize¹Command::AddSize¹Command(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddSize¹Command::AddSize¹Command(const AddSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddSize¹Command::~AddSize¹Command()
    {
    }
    
    PostCPtr    AddSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new AddSize¹Command(*this, h);
    }

    void AddSize¹Command::init_meta()
    {
        auto w = writer<AddSize¹Command>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize¹Command::Δx).tag(kTag_Log);
        w.property("Δ",  &AddSize¹Command::m_Δ).tag(kTag_Save);
    }
}
