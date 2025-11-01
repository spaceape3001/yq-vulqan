////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Proxy.hpp>
#include <tachyon/interface/IFieldOfView.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class PFieldOfView : public Proxy, public IFieldOfView {
    public:
    
        virtual unit::Degree  field_of_view() const override;

        virtual bool    field_of_view(disabled_k) const override;
        virtual bool    field_of_view(settable_k) const override;
        
        virtual void    field_of_view(set_k, unit::Degree) override;

        PFieldOfView(const IFieldOfView& i);
        ~PFieldOfView();

    private:
        const unit::Degree  m_field_of_view;
    };
}
