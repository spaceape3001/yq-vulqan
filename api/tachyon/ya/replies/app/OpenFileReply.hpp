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
    class OpenFileReply : public AppReply {
        YQ_OBJECT_DECLARE(OpenFileReply, AppReply)
    public:
    
        OpenFileReply(const Header&, const RequestCPtr&, Response);
        OpenFileReply(const Header&, const RequestCPtr&, const std::filesystem::path&);
        
        const std::filesystem::path&        file() const { return m_file; }
        Response    response() const { return m_response; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();
        
    protected:
        OpenFileReply(const OpenFileReply&, const Header&);
        virtual ~OpenFileReply();
        
    private:
        std::filesystem::path   m_file;
        Response                m_response;
        
        OpenFileReply(const OpenFileReply&) = delete;
        OpenFileReply(OpenFileReply&&) = delete;
        OpenFileReply& operator=(const OpenFileReply&) = delete;
        OpenFileReply& operator=(OpenFileReply&&) = delete;
    };
}
