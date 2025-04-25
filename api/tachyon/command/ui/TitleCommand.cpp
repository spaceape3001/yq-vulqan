////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/TitleCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TitleCommand)

namespace yq::tachyon {

    TitleCommand::TitleCommand(const Header&h, std::string_view szTitle) : UICommand(h), m_title(szTitle)
    {
    }

    TitleCommand::TitleCommand(const TitleCommand& cp, const Header& h) : UICommand(cp, h), m_title(cp.m_title)
    {
    }
    
    TitleCommand::~TitleCommand()
    {
    }

    PostCPtr    TitleCommand::clone(rebind_k, const Header&h) const 
    {
        return new TitleCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TitleCommand::init_info()
    {
        auto w = writer<TitleCommand>();
        w.description("Title Command");
        w.property("title", &TitleCommand::m_title).tag(kTag_Log).tag(kTag_Save);
    }
}
