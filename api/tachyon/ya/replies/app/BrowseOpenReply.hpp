////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Response.hpp> 
#include <ya/replies/AppReply.hpp>
#include <yv/typedef/vi_device.hpp>
#include <yt/msg/Response.hpp>
#include <filesystem>

namespace yq::tachyon {
    class BrowseOpenReply : public AppReply {
        YQ_OBJECT_DECLARE(BrowseOpenReply, AppReply)
    public:
    
        BrowseOpenReply(const Header&, const RequestCPtr&, Response);
        BrowseOpenReply(const Header&, const RequestCPtr&, const std::filesystem::path&);
        
        const std::filesystem::path&        file() const { return m_file; }
        Response    response() const { return m_response; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();
        
    protected:
        BrowseOpenReply(const BrowseOpenReply&, const Header&);
        virtual ~BrowseOpenReply();
        
    private:
        std::filesystem::path   m_file;
        Response                m_response;
        
        BrowseOpenReply(const BrowseOpenReply&) = delete;
        BrowseOpenReply(BrowseOpenReply&&) = delete;
        BrowseOpenReply& operator=(const BrowseOpenReply&) = delete;
        BrowseOpenReply& operator=(BrowseOpenReply&&) = delete;
    };
}
