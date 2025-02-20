////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/requests/IORequest.hpp>
#include <yt/api/ID.hpp>
#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    class SaveCommand;
    class SaveRequest : public IORequest {
        YQ_OBJECT_DECLARE(SaveRequest, IORequest)
    public:
    
        //! Default is to include *EVERYTHING* on 
        SaveRequest(const Header&, bool doThread=false);
        SaveRequest(const Header&, const TachyonIDSet&, bool doChildren=true);
        SaveRequest(const Header&, TachyonIDSet&&, bool doChildren=true);
        SaveRequest(const Header&, const SaveCommand&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
        const TachyonIDSet&     tachyons() const { return m_tachyons; }
        
        //! If true, does the thread itself
        bool                    do_thread() const { return m_doThread; }
        bool                    do_children() const { return m_doChildren; }
        
    protected:
        SaveRequest(const SaveRequest&, const Header&);
        virtual ~SaveRequest();
        
    private:
        TachyonIDSet    m_tachyons;
        bool            m_doChildren = true;
        bool            m_doThread   = false;
    
        SaveRequest(const SaveRequest&) = delete;
        SaveRequest(SaveRequest&&) = delete;
        SaveRequest& operator=(const SaveRequest&) = delete;
        SaveRequest& operator=(SaveRequest&&) = delete;
    };
}
