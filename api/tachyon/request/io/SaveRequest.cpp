////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/io/SaveRequest.hpp>
#include <tachyon/command/io/SaveCommand.hpp>
#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveRequest)

namespace yq::tachyon {

    SaveRequest::SaveRequest(const Header&h, SaveOptions opts) : IORequest(h), m_options(opts)
    {
    }

    SaveRequest::SaveRequest(const Header&h, const TachyonIDSet&tacs, SaveOptions opts) : 
        IORequest(h), m_options(opts)
    {
    }
    
    SaveRequest::SaveRequest(const Header&h, TachyonIDSet&&tacs, SaveOptions opts) : 
        IORequest(h), m_tachyons(std::move(tacs)), m_options(opts)
    {
    }

    SaveRequest::SaveRequest(const Header&h, const SaveCommand&cmd) : IORequest(h), 
        m_tachyons(cmd.tachyons()), m_options(cmd.options())
    {
    }

    SaveRequest::SaveRequest(const SaveRequest& cp, const Header& h) : 
        IORequest(cp, h), m_tachyons(cp.m_tachyons), m_options(cp.m_options)
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
