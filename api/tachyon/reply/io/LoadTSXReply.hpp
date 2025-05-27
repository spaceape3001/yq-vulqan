////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/reply/IOReply.hpp>
#include <tachyon/api/Response.hpp>
#include <tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class LoadTSXReply : public IOReply {
        YQ_OBJECT_DECLARE(LoadTSXReply, IOReply)
    public:
        static void  init_info();
        
        LoadTSXReply(const Header&, const RequestCPtr&, Response);
        LoadTSXReply(const Header&, const RequestCPtr&, const TachyonIDSet&);
        LoadTSXReply(const Header&, const RequestCPtr&, TachyonIDSet&&);
        
        PostCPtr clone(rebind_k, const Header&) const override;
        
        Response            response() const { return m_response; }
        const TachyonIDSet& tachyons() const { return m_tachyons; }
    
    protected:
        LoadTSXReply(const LoadTSXReply&, const Header&);
        virtual ~LoadTSXReply();
        
    private:
        Response        m_response;
        TachyonIDSet    m_tachyons;
        
        LoadTSXReply(const LoadTSXReply&) = delete;
        LoadTSXReply(LoadTSXReply&&) = delete;
        LoadTSXReply& operator=(const LoadTSXReply&) = delete;
        LoadTSXReply& operator=(LoadTSXReply&&) = delete;
    };
}
