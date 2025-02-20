////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/io/SaveRequest.hpp>
#include <ya/commands/io/SaveCommand.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveRequest)

namespace yq::tachyon {

    SaveRequest::SaveRequest(const Header&h, bool doThread) : IORequest(h), m_doThread(doThread)
    {
    }

    SaveRequest::SaveRequest(const Header&h, const TachyonIDSet&tacs, bool doChildren) : 
        IORequest(h), m_tachyons(tacs), m_doChildren(doChildren)
    {
    }
    
    SaveRequest::SaveRequest(const Header&h, TachyonIDSet&&tacs, bool doChildren) : 
        IORequest(h), m_tachyons(std::move(tacs)), m_doChildren(doChildren)
    {
    }

    SaveRequest::SaveRequest(const Header&h, const SaveCommand&cmd) : IORequest(h), 
        m_tachyons(cmd.tachyons()), m_doChildren(cmd.do_children())
    {
    }

    SaveRequest::SaveRequest(const SaveRequest& cp, const Header& h) : 
        IORequest(cp, h), m_tachyons(cp.m_tachyons), m_doChildren(cp.m_doChildren), m_doThread(cp.m_doThread)
    {
    }
    
    SaveRequest::~SaveRequest()
    {
    }

    PostCPtr    SaveRequest::clone(rebind_k, const Header&h) const 
    {
        return new SaveRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SaveRequest::init_info()
    {
        auto w = writer<SaveRequest>();
        w.description("Device Request");
    }
}
