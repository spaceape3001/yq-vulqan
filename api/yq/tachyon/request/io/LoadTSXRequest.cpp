////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LoadTSXRequest.hpp"
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LoadTSXRequest)

namespace yq::tachyon {
    void LoadTSXRequest::init_meta()
    {
        auto w = writer<LoadTSXRequest>();
        w.description("Load/Import TSX Request");
    }
    
    LoadTSXRequest::LoadTSXRequest(const Header&h, const std::filesystem::path&fp, const ReincarnationConfig& cfg, PrepFN&& prepFN) : 
        IORequest(h), m_filepath(fp), m_config(cfg), m_prep(std::move(prepFN))
    {
    }
    
    LoadTSXRequest::LoadTSXRequest(const LoadTSXRequest&cp, const Header&h) : 
        IORequest(cp, h), m_filepath(cp.m_filepath), m_config(cp.m_config), m_prep(cp.m_prep)
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
