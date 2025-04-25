////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IMaxSize4.hpp>
#include <yt/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize⁴;
    class AddMaxSizeˣ;
    class AddMaxSizeʷ;
    class AddMaxSizeʸ;
    class AddMaxSizeᶻ;
    class MultiplyMaxSize;
    class MultiplyMaxSize⁴;
    class MultiplyMaxSizeʷ;
    class MultiplyMaxSizeˣ;
    class MultiplyMaxSizeʸ;
    class MultiplyMaxSizeᶻ;
    class SetMaxSize⁴;
    class SetMaxSizeʷ;
    class SetMaxSizeˣ;
    class SetMaxSizeʸ;
    class SetMaxSizeᶻ;

    class AMaxSize⁴ : public IMaxSize⁴, public virtual Tachyon::Helper {
    public:
    
        //!  Basic max_size in the 4D space
        Size4D          max_size() const override { return m_max_size; }
        
        double          max_size(x_k) const { return m_max_size.x; }
        double          max_size(y_k) const { return m_max_size.y; }
        double          max_size(z_k) const { return m_max_size.z; }
        double          max_size(w_k) const { return m_max_size.z; }
        
        //!  SetMax max_size the max_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    max_size(set_k, const Size4D&) override;
        void            max_size(set_k, x_k, double) override;
        void            max_size(set_k, y_k, double) override;
        void            max_size(set_k, z_k, double) override;
        void            max_size(set_k, w_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void            max_size(add_k, const Vector4D&) override;
        void            max_size(add_k, x_k, double) override;
        void            max_size(add_k, y_k, double) override;
        void            max_size(add_k, z_k, double) override;
        void            max_size(add_k, w_k, double) override;

        void            max_size(multiply_k, double) override;
        void            max_size(multiply_k, const Vector4D&) override;
        void            max_size(multiply_k, x_k, double) override;
        void            max_size(multiply_k, y_k, double) override;
        void            max_size(multiply_k, z_k, double) override;
        void            max_size(multiply_k, w_k, double) override;
        
        bool            max_size(disabled_k) const { return false; }
        bool            max_size(settable_k) const { return true; }
        bool            max_size(addable_k) const { return true; }
        bool            max_size(multipliable_k) const { return true; }
        
        const Size4D&   max_size(ref_k) const { return m_max_size; }

    protected:

        Size4D      m_max_size = NAN;
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AMaxSize⁴();
        virtual ~AMaxSize⁴();
        
        void        max_size(emit_k);
        
    private:
        void        on_set_max_size4(const SetMaxSize⁴&);
        void        on_set_max_sizeW(const SetMaxSizeʷ&);
        void        on_set_max_sizeX(const SetMaxSizeˣ&);
        void        on_set_max_sizeY(const SetMaxSizeʸ&);
        void        on_set_max_sizeZ(const SetMaxSizeᶻ&);

        void        on_add_max_size4(const AddMaxSize⁴&);
        void        on_add_max_sizeW(const AddMaxSizeʷ&);
        void        on_add_max_sizeX(const AddMaxSizeˣ&);
        void        on_add_max_sizeY(const AddMaxSizeʸ&);
        void        on_add_max_sizeZ(const AddMaxSizeᶻ&);
        
        void        on_multiply_max_size(const MultiplyMaxSize&);
        void        on_multiply_max_size4(const MultiplyMaxSize⁴&);
        void        on_multiply_max_sizeW(const MultiplyMaxSizeʷ&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣ&);
        void        on_multiply_max_sizeY(const MultiplyMaxSizeʸ&);
        void        on_multiply_max_sizeZ(const MultiplyMaxSizeᶻ&);

    };

}
