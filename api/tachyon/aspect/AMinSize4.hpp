////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IMinSize4.hpp>
#include <tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize⁴Command;
    class AddMinSizeʷCommand;
    class AddMinSizeˣCommand;
    class AddMinSizeʸCommand;
    class AddMinSizeᶻCommand;
    class MultiplyMinSize;
    class MultiplyMinSize⁴Command;
    class MultiplyMinSizeʷCommand;
    class MultiplyMinSizeˣCommand;
    class MultiplyMinSizeʸCommand;
    class MultiplyMinSizeᶻCommand;
    class SetMinSize⁴Command;
    class SetMinSizeʷCommand;
    class SetMinSizeˣCommand;
    class SetMinSizeʸCommand;
    class SetMinSizeᶻCommand;

    class AMinSize⁴ : public IMinSize⁴, public virtual Tachyon::Helper {
    public:
    
        //!  Basic min_size in the 4D space
        Size4D          min_size() const override { return m_min_size; }
        
        double          min_size(x_k) const { return m_min_size.x; }
        double          min_size(y_k) const { return m_min_size.y; }
        double          min_size(z_k) const { return m_min_size.z; }
        double          min_size(w_k) const { return m_min_size.w; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size4D&) override;
        void            min_size(set_k, x_k, double) override;
        void            min_size(set_k, y_k, double) override;
        void            min_size(set_k, z_k, double) override;
        void            min_size(set_k, w_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Vector4D&) override;
        void            min_size(add_k, x_k, double) override;
        void            min_size(add_k, y_k, double) override;
        void            min_size(add_k, z_k, double) override;
        void            min_size(add_k, w_k, double) override;

        void            min_size(multiply_k, double) override;
        void            min_size(multiply_k, const Vector4D&) override;
        void            min_size(multiply_k, x_k, double) override;
        void            min_size(multiply_k, y_k, double) override;
        void            min_size(multiply_k, z_k, double) override;
        void            min_size(multiply_k, w_k, double) override;
        
        bool            min_size(disabled_k) const { return false; }
        bool            min_size(settable_k) const { return true; }
        bool            min_size(addable_k) const { return true; }
        bool            min_size(multipliable_k) const { return true; }
        
        const Size4D&   min_size(ref_k) const { return m_min_size; }

    protected:

        Size4D      m_min_size = NAN;
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AMinSize⁴();
        virtual ~AMinSize⁴();
        
        void        min_size(emit_k);
        
    private:
        void        on_set_min_size4(const SetMinSize⁴Command&);
        void        on_set_min_sizeW(const SetMinSizeʷCommand&);
        void        on_set_min_sizeX(const SetMinSizeˣCommand&);
        void        on_set_min_sizeY(const SetMinSizeʸCommand&);
        void        on_set_min_sizeZ(const SetMinSizeᶻCommand&);

        void        on_add_min_size4(const AddMinSize⁴Command&);
        void        on_add_min_sizeW(const AddMinSizeʷCommand&);
        void        on_add_min_sizeX(const AddMinSizeˣCommand&);
        void        on_add_min_sizeY(const AddMinSizeʸCommand&);
        void        on_add_min_sizeZ(const AddMinSizeᶻCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSize&);
        void        on_multiply_min_size4(const MultiplyMinSize⁴Command&);
        void        on_multiply_min_sizeW(const MultiplyMinSizeʷCommand&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣCommand&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸCommand&);
        void        on_multiply_min_sizeZ(const MultiplyMinSizeᶻCommand&);

    };

}
