////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IMinSize3.hpp>
#include <yt/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize³;
    class AddMinSizeˣ;
    class AddMinSizeʸ;
    class AddMinSizeᶻ;
    class MultiplyMinSize;
    class MultiplyMinSize³;
    class MultiplyMinSizeˣ;
    class MultiplyMinSizeʸ;
    class MultiplyMinSizeᶻ;
    class SetMinSize³;
    class SetMinSizeˣ;
    class SetMinSizeʸ;
    class SetMinSizeᶻ;

    class AMinSize³ : public IMinSize³, public virtual Tachyon::Helper {
    public:
    
        //!  Basic min_size in the 3D space
        Size3D          min_size() const override { return m_min_size; }
        
        double          min_size(x_k) const { return m_min_size.x; }
        double          min_size(y_k) const { return m_min_size.y; }
        double          min_size(z_k) const { return m_min_size.z; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size3D&) override;
        void            min_size(set_k, x_k, double) override;
        void            min_size(set_k, y_k, double) override;
        void            min_size(set_k, z_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Vector3D&) override;
        void            min_size(add_k, x_k, double) override;
        void            min_size(add_k, y_k, double) override;
        void            min_size(add_k, z_k, double) override;

        void            min_size(multiply_k, double) override;
        void            min_size(multiply_k, const Vector3D&) override;
        void            min_size(multiply_k, x_k, double) override;
        void            min_size(multiply_k, y_k, double) override;
        void            min_size(multiply_k, z_k, double) override;
        
        bool            min_size(disabled_k) const { return false; }
        bool            min_size(settable_k) const { return true; }
        bool            min_size(addable_k) const { return true; }
        bool            min_size(multipliable_k) const { return true; }
        
        const Size3D&   min_size(ref_k) const { return m_min_size; }

    protected:

        Size3D      m_min_size = NAN;
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AMinSize³();
        virtual ~AMinSize³();
        
        void        min_size(emit_k);
        
    private:
        void        on_set_min_size3(const SetMinSize³&);
        void        on_set_min_sizeX(const SetMinSizeˣ&);
        void        on_set_min_sizeY(const SetMinSizeʸ&);
        void        on_set_min_sizeZ(const SetMinSizeᶻ&);

        void        on_add_min_size3(const AddMinSize³&);
        void        on_add_min_sizeX(const AddMinSizeˣ&);
        void        on_add_min_sizeY(const AddMinSizeʸ&);
        void        on_add_min_sizeZ(const AddMinSizeᶻ&);
        
        void        on_multiply_min_size(const MultiplyMinSize&);
        void        on_multiply_min_size3(const MultiplyMinSize³&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣ&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸ&);
        void        on_multiply_min_sizeZ(const MultiplyMinSizeᶻ&);

    };

}
