////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/ISize4.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize⁴;
    class AddSizeʷ;
    class AddSizeˣ;
    class AddSizeʸ;
    class AddSizeᶻ;
    class MultiplySize;
    class MultiplySize⁴;
    class MultiplySizeʷ;
    class MultiplySizeˣ;
    class MultiplySizeʸ;
    class MultiplySizeᶻ;
    class SetSize⁴;
    class SetSizeʷ;
    class SetSizeˣ;
    class SetSizeʸ;
    class SetSizeᶻ;

    class ASize⁴ : public ISize⁴, public virtual Tachyon::Helper {
    public:
    
        //!  Basic size in the 4D space
        Size4D          size() const override { return m_size; }
        
        double          size(x_k) const { return m_size.x; }
        double          size(y_k) const { return m_size.y; }
        double          size(z_k) const { return m_size.z; }
        double          size(w_k) const { return m_size.w; }
        
        //!  Set size the size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    size(set_k, const Size4D&) override;
        void            size(set_k, x_k, double) override;
        void            size(set_k, y_k, double) override;
        void            size(set_k, z_k, double) override;
        void            size(set_k, w_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void            size(add_k, const Vector4D&) override;
        void            size(add_k, x_k, double) override;
        void            size(add_k, y_k, double) override;
        void            size(add_k, z_k, double) override;
        void            size(add_k, w_k, double) override;

        void            size(multiply_k, double) override;
        void            size(multiply_k, const Vector4D&) override;
        void            size(multiply_k, x_k, double) override;
        void            size(multiply_k, y_k, double) override;
        void            size(multiply_k, z_k, double) override;
        void            size(multiply_k, w_k, double) override;
        
        bool            size(disabled_k) const { return false; }
        bool            size(settable_k) const { return true; }
        bool            size(addable_k) const { return true; }
        bool            size(multipliable_k) const { return true; }
        
        const Size4D&   size(ref_k) const { return m_size; }

    protected:

        Size4D      m_size = ONE;
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        ASize⁴();
        virtual ~ASize⁴();
        
        void        size(emit_k);
        
    private:
        void        on_set_size4(const SetSize⁴&);
        void        on_set_sizeW(const SetSizeʷ&);
        void        on_set_sizeX(const SetSizeˣ&);
        void        on_set_sizeY(const SetSizeʸ&);
        void        on_set_sizeZ(const SetSizeᶻ&);

        void        on_add_size4(const AddSize⁴&);
        void        on_add_sizeW(const AddSizeʷ&);
        void        on_add_sizeX(const AddSizeˣ&);
        void        on_add_sizeY(const AddSizeʸ&);
        void        on_add_sizeZ(const AddSizeᶻ&);
        
        void        on_multiply_size(const MultiplySize&);
        void        on_multiply_size4(const MultiplySize⁴&);
        void        on_multiply_sizeW(const MultiplySizeʷ&);
        void        on_multiply_sizeX(const MultiplySizeˣ&);
        void        on_multiply_sizeY(const MultiplySizeʸ&);
        void        on_multiply_sizeZ(const MultiplySizeᶻ&);

    };

}
