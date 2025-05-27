////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/reply/IOReply.hpp>
#include <tachyon/api/Response.hpp>

namespace yq::tachyon {
    class SaveTSXReply : public IOReply {
        YQ_OBJECT_DECLARE(SaveTSXReply, IOReply)
    public:
        SaveTSXReply(const Header&, const RequestCPtr&, Response);
        Response     response() const { return m_response; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();

    protected:
        SaveTSXReply(const SaveTSXReply&, const Header&);
        virtual ~SaveTSXReply();
        
    private:
        Response     m_response;
        
        SaveTSXReply(const SaveTSXReply&) = delete;
        SaveTSXReply(SaveTSXReply&&) = delete;
        SaveTSXReply& operator=(const SaveTSXReply&) = delete;
        SaveTSXReply& operator=(SaveTSXReply&&) = delete;
    };
}
