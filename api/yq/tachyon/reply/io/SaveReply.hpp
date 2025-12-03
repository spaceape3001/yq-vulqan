////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/reply/IOReply.hpp>
#include <yq/tachyon/typedef/save.hpp>

namespace yq::tachyon {
    class SaveReply : public IOReply {
        YQ_OBJECT_DECLARE(SaveReply, IOReply)
    public:
    
        SaveReply(const Header&, const RequestCPtr&, SavePtr&&);
        SaveReply(const Header&, const RequestCPtr&, const SavePtr&);
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_meta();
        
        const SavePtr & save() const { return m_save; }
        
    protected:
        SaveReply(const SaveReply&, const Header&);
        virtual ~SaveReply();
        
    private:
        SavePtr      m_save;
        
        SaveReply(const SaveReply&) = delete;
        SaveReply(SaveReply&&) = delete;
        SaveReply& operator=(const SaveReply&) = delete;
        SaveReply& operator=(SaveReply&&) = delete;
    };
}
