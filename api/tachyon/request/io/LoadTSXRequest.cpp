////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LoadTSXRequest.hpp"
#include <tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LoadTSXRequest)

namespace yq::tachyon {
    void LoadTSXRequest::init_info()
    {
        auto w = writer<LoadTSXRequest>();
        w.description("Load/Import TSX Request");
    }
    
    LoadTSXRequest::LoadTSXRequest(const Header&h, const std::filesystem::path&fp, ThreadSpec th) : 
        IORequest(h), m_filepath(fp), m_thread(th)
    {
    }
    
    LoadTSXRequest::LoadTSXRequest(const LoadTSXRequest&cp, const Header&h) : 
        IORequest(cp, h), m_filepath(cp.m_filepath), m_thread(cp.m_thread)
    {
    }
    
    LoadTSXRequest::~LoadTSXRequest()
    {
    }
    
    PostCPtr LoadTSXRequest::clone(rebind_k, const Header& h) const 
    {
        return new LoadTSXRequest(*this, h);
    }
}
