////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IHeightField.hpp>

namespace yq::tachyon {
    class PHeightField : public Proxy, public IHeightField {
    public:
    
        virtual HeightFieldCPtr height_field() const override;
        virtual Url             height_field(url_k) const override;
        virtual void            height_field(set_k, const HeightFieldCPtr&) override;
        virtual void            height_field(set_k, const Url&) override;
        virtual bool            height_field(disabled_k) const override;
        virtual bool            height_field(settable_k) const override;


        PHeightField(const IHeightField&);
        virtual ~PHeightField();
        
    private:
        HeightFieldCPtr     m_heightField;
        Url                 m_url;
    };
}
