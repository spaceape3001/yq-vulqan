////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/replies/IOReply.hpp>
#include <tachyon/typedef/save.hpp>

namespace yq::tachyon {
    class SaveReply : public IOReply {
        YQ_OBJECT_DECLARE(SaveReply, IOReply)
    public:
    
        SaveReply(const Header&, const RequestCPtr&, SaveSPtr&&);
        SaveReply(const Header&, const RequestCPtr&, const SaveSPtr&);
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();
        
        const SaveSPtr& save() const { return m_save; }
        
    protected:
        SaveReply(const SaveReply&, const Header&);
        virtual ~SaveReply();
        
    private:
        SaveSPtr     m_save;
        
        SaveReply(const SaveReply&) = delete;
        SaveReply(SaveReply&&) = delete;
        SaveReply& operator=(const SaveReply&) = delete;
        SaveReply& operator=(SaveReply&&) = delete;
    };
}
