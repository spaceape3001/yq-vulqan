////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/interface/INearPlane.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetNearPlaneCommand;
    
    class ANearPlane : public INearPlane, public virtual Tachyon::Helper {
    public:
        
        double  near_plane() const override { return m_near; }

        virtual bool    near_plane(disabled_k) const override { return false; }
        virtual bool    near_plane(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    near_plane(set_k, double);
        
    protected:
    
        static constexpr const double   kDefNearPlane    = 60.;
    
        double    m_near = kDefNearPlane;

        template <typename C>
        static void init_info(TachyonMeta::Writer<C>&);
        
        ANearPlane();
        virtual ~ANearPlane();
        
        void    near_plane(emit_k);

    private:
        void    on_set_near_plane(const SetNearPlaneCommand&);

    };
}
