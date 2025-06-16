////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/interface/IFieldOfView.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetFOVCommand;
    
    class AFieldOfView : public IFieldOfView, public virtual Tachyon::Helper {
    public:
        
        unit::Degree   field_of_view() const override { return m_fov; }

        virtual bool    field_of_view(disabled_k) const override { return false; }
        virtual bool    field_of_view(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    field_of_view(set_k, unit::Degree) override;
        
    protected:
    
        static constexpr const unit::Degree   kDefFieldOfView   = 70._deg;
    
        unit::Degree    m_fov = kDefFieldOfView;

        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AFieldOfView();
        virtual ~AFieldOfView();
        
    private:
        void    on_set_fov(const SetFOVCommand&);

    };
}
