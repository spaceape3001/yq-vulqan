////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/request/io/SaveRequest.hpp>
#include <yq/tachyon/command/io/SaveCommand.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveRequest)

namespace yq::tachyon {

    SaveRequest::SaveRequest(const Header&h, SaveFlags opts) : IORequest(h), m_flags(opts)
    {
    }

    SaveRequest::SaveRequest(const Header&h, const TachyonIDSet&tacs, SaveFlags opts) : 
        IORequest(h), m_flags(opts)
    {
    }
    
    SaveRequest::SaveRequest(const Header&h, TachyonIDSet&&tacs, SaveFlags opts) : 
        IORequest(h), m_tachyons(std::move(tacs)), m_flags(opts)
    {
    }

    SaveRequest::SaveRequest(const Header&h, const SaveCommand&cmd) : IORequest(h), 
        m_tachyons(cmd.tachyons()), m_flags(cmd.flags())
    {
    }

    SaveRequest::SaveRequest(const SaveRequest& cp, const Header& h) : 
        IORequest(cp, h), m_tachyons(cp.m_tachyons), m_flags(cp.m_flags)
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

    void SaveRequest::init_meta()
    {
        auto w = writer<SaveRequest>();
        w.description("Device Request");
    }
}
