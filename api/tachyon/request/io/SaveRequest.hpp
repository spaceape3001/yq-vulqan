////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/IORequest.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/save.hpp>

namespace yq::tachyon {
    class SaveCommand;
    class SaveRequest : public IORequest {
        YQ_OBJECT_DECLARE(SaveRequest, IORequest)
    public:
    
        //! Default is to include *EVERYTHING* on 
        SaveRequest(const Header&, SaveOptions opts={});
        SaveRequest(const Header&, const TachyonIDSet&, SaveOptions opts={});
        SaveRequest(const Header&, TachyonIDSet&&, SaveOptions opts={});
        SaveRequest(const Header&, const SaveCommand&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
        const TachyonIDSet&     tachyons() const { return m_tachyons; }
        
        SaveOptions options() const { return m_options; }
        bool        option(SaveOption so) const { return m_options(so); }
        
    protected:
        SaveRequest(const SaveRequest&, const Header&);
        virtual ~SaveRequest();
        
    private:
        TachyonIDSet    m_tachyons;
        SaveOptions     m_options = {};
    
        SaveRequest(const SaveRequest&) = delete;
        SaveRequest(SaveRequest&&) = delete;
        SaveRequest& operator=(const SaveRequest&) = delete;
        SaveRequest& operator=(SaveRequest&&) = delete;
    };
}
