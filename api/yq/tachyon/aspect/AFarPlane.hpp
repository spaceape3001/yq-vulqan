////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/interface/IFarPlane.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetFarPlaneCommand;
    
    class AFarPlane : public IFarPlane, public virtual Tachyon::Helper {
    public:
        
        double  far_plane() const override { return m_far; }

        virtual bool    far_plane(disabled_k) const override { return false; }
        virtual bool    far_plane(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    far_plane(set_k, double);
        
    protected:
    
        static constexpr const double   kDefFarPlane    = 60.;
    
        double    m_far = kDefFarPlane;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AFarPlane();
        virtual ~AFarPlane();
        
        virtual void    far_plane(emit_k);

    private:
        void    on_set_far_plane(const SetFarPlaneCommand&);

    };
}
