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
    class SaveFileReply : public AppReply {
        YQ_OBJECT_DECLARE(SaveFileReply, AppReply)
    public:
    
        SaveFileReply(const Header&, const RequestCPtr&, Response);
        SaveFileReply(const Header&, const RequestCPtr&, const std::filesystem::path&);
        
        const std::filesystem::path&        file() const { return m_file; }
        Response    response() const { return m_response; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();
        
    protected:
        SaveFileReply(const SaveFileReply&, const Header&);
        virtual ~SaveFileReply();
        
    private:
        std::filesystem::path   m_file;
        Response                m_response;
        
        SaveFileReply(const SaveFileReply&) = delete;
        SaveFileReply(SaveFileReply&&) = delete;
        SaveFileReply& operator=(const SaveFileReply&) = delete;
        SaveFileReply& operator=(SaveFileReply&&) = delete;
    };
}
